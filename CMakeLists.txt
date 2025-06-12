cmake_minimum_required(VERSION 3.10)
project(MyCardGame)

set(APP_NAME "MyCardGame")
set(CMAKE_GENERATOR_TOOLSET "v143" CACHE STRING "Platform Toolset")

# 引擎源码目录
set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)
include(CocosBuildSet)

if(NOT USE_COCOS_PREBUILT)
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)
endif()

# 添加 include 目录
include_directories(
    ${CMAKE_SOURCE_DIR}/Classes
    ${CMAKE_SOURCE_DIR}/Classes/models
    ${CMAKE_SOURCE_DIR}/Classes/configs/loaders
	${CMAKE_SOURCE_DIR}/Classes/configs/models
    ${CMAKE_SOURCE_DIR}/Classes/views
    ${CMAKE_SOURCE_DIR}/Classes/controllers
    ${CMAKE_SOURCE_DIR}/Classes/managers
    ${CMAKE_SOURCE_DIR}/Classes/services
    ${CMAKE_SOURCE_DIR}/Classes/utils
    ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

# 资源文件复制（示例）
file(GLOB_RECURSE RESOURCE_FILES "${CMAKE_SOURCE_DIR}/Resources/*")
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources)

# 收集源码和头文件
file(GLOB_RECURSE GAME_SOURCE "${CMAKE_SOURCE_DIR}/Classes/*.cpp")
file(GLOB_RECURSE GAME_HEADER "${CMAKE_SOURCE_DIR}/Classes/*.h")

if(WINDOWS)
    list(APPEND GAME_SOURCE
        "${CMAKE_SOURCE_DIR}/proj.win32/main.cpp"
        "${CMAKE_SOURCE_DIR}/proj.win32/game.rc"
    )
    list(APPEND GAME_HEADER
        "${CMAKE_SOURCE_DIR}/proj.win32/main.h"
        "${CMAKE_SOURCE_DIR}/proj.win32/resource.h"
    )
endif()

# 检查文件（可选）
function(check_file_exists file)
    if(NOT EXISTS ${file})
        message(FATAL_ERROR "缺失文件: ${file}")
    endif()
endfunction()

check_file_exists("${CMAKE_SOURCE_DIR}/Classes/AppDelegate.cpp")
check_file_exists("${CMAKE_SOURCE_DIR}/Classes/HelloWorldScene.cpp")
check_file_exists("${CMAKE_SOURCE_DIR}/proj.win32/main.cpp")
check_file_exists("${CMAKE_SOURCE_DIR}/proj.win32/game.rc")

# 组合所有源文件
set(APP_SRC
    ${GAME_SOURCE}
    ${GAME_HEADER}
)

# 构建应用
cocos_build_app(${APP_NAME}
    APP_SRC ${APP_SRC}
    DEPEND_COMMON_LIBS "cocos2d"
)
