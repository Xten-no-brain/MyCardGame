cmake_minimum_required(VERSION 3.10)

set(APP_NAME TemplateCpp)

project(MyCardGame)

set(CMAKE_GENERATOR_TOOLSET "v143" CACHE STRING "Platform Toolset")

file(GLOB_RECURSE RESOURCE_FILES "${CMAKE_SOURCE_DIR}/Resources/*")

foreach(resource ${RESOURCE_FILES})
    file(RELATIVE_PATH relPath "${CMAKE_SOURCE_DIR}/Resources" ${resource})
    configure_file(${resource} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${relPath} COPYONLY)
endforeach()

set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

include(CocosBuildSet)
if(NOT USE_COCOS_PREBUILT)
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)
endif()

# 添加 include 目录：Classes 下所有子目录，Classes/src，Classes/win32（也方便 main.cpp 里引用）
include_directories(
    Classes
    Classes/models
    Classes/configs
    ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

# 记录代码文件
set(GAME_SOURCE)
set(GAME_HEADER)

# 添加 Classes 目录下的所有源文件和头文件
file(GLOB GAME_SOURCE
    Classes/*.cpp
    Classes/**/*.cpp
)

file(GLOB GAME_HEADER
    Classes/*.h
    Classes/**/*.h
)

# 手动添加关键文件
list(APPEND ${CMAKE_SOURCE_DIR}
    "${CMAKE_SOURCE_DIR}/Classes/AppDelegate.cpp"
    "${CMAKE_SOURCE_DIR}/Classes/HelloWorldScene.cpp"
)

# 定义一个函数来检查文件是否存在
function(check_file_exists file)
    if(NOT EXISTS ${file})
        message(FATAL_ERROR "缺失文件: ${file}")
    endif()
endfunction()

# 检查关键文件
check_file_exists("${CMAKE_SOURCE_DIR}/Classes/AppDelegate.cpp")
check_file_exists("${CMAKE_SOURCE_DIR}/Classes/HelloWorldScene.cpp")

if(WINDOWS)
    list(APPEND GAME_SOURCE
        "${CMAKE_SOURCE_DIR}/proj.win32/main.cpp"
        "${CMAKE_SOURCE_DIR}/proj.win32/game.rc"
    )
    check_file_exists("${CMAKE_SOURCE_DIR}/proj.win32/main.cpp")
    check_file_exists("${CMAKE_SOURCE_DIR}/proj.win32/game.rc")
endif()

# Windows 平台，加入 win32 目录下 main.cpp 和 game.rc
if(WINDOWS)
    list(APPEND GAME_SOURCE
        "${CMAKE_SOURCE_DIR}/proj.win32/main.cpp"
        "${CMAKE_SOURCE_DIR}/proj.win32/game.rc"
    )
endif()


# 资源文件夹，供复制
set(GAME_RES_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/Resources")

if(APPLE OR WINDOWS)
    cocos_mark_multi_resources(common_res_files RES_TO "Resources" FOLDERS ${GAME_RES_FOLDER})
endif()

if(ANDROID)
    set(APP_NAME MyGame)
    list(APPEND GAME_SOURCE
         proj.android/app/jni/hellocpp/main.cpp
    )
elseif(LINUX)
    list(APPEND GAME_SOURCE
         proj.linux/main.cpp
    )
elseif(WINDOWS)
    list(APPEND GAME_HEADER
	     proj.win32/main.h
         proj.win32/resource.h
    )
    list(APPEND GAME_SOURCE
         proj.win32/main.cpp
         proj.win32/game.rc
         ${common_res_files}
    )
elseif(APPLE)
    # 苹果相关保持不变
endif()

set(APP_SRC
    ${GAME_SOURCE}
    ${GAME_HEADER}
)

cocos_build_app(${APP_NAME}
    APP_SRC "${APP_SRC}"
    DEPEND_COMMON_LIBS "cocos2d"
    DEPEND_ANDROID_LIBS "cocos2d_android"
)

if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")
    if(MACOSX)
        set_target_properties(${APP_NAME} PROPERTIES
            MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/mac/Info.plist"
        )
    elseif(IOS)
        cocos_pak_xcode(${APP_NAME} INFO_PLIST "iOSBundleInfo.plist.in")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
    endif()
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME} COPY_TO ${APP_BIN_DIR})
endif()

if(LINUX OR WINDOWS)
    cocos_copy_target_res(${APP_NAME} COPY_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()