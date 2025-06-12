#include "GameController.h"
#include "configs/loaders/LevelConfigLoader.h"
#include "GameModel.h"
#include "GameView.h"

void GameController::initGame(const std::string& levelId)
{
    // 加载关卡配置
    LevelConfig levelConfig = LevelConfigLoader::loadLevelConfig(levelId);

    // 创建游戏模型
    gameModel = new GameModel(levelConfig);

    // 初始化视图
    gameView = GameView::create();
    gameView->init(levelConfig);

    // 添加回退管理器
    undoManager = new UndoManager();

    // 设置控制器逻辑
    setupEventListeners();
}