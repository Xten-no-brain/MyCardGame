#include "GameController.h"
#include "configs/loaders/LevelConfigLoader.h"
#include "GameModel.h"
#include "GameView.h"

void GameController::initGame(const std::string& levelId)
{
    // ���عؿ�����
    LevelConfig levelConfig = LevelConfigLoader::loadLevelConfig(levelId);

    // ������Ϸģ��
    gameModel = new GameModel(levelConfig);

    // ��ʼ����ͼ
    gameView = GameView::create();
    gameView->init(levelConfig);

    // ��ӻ��˹�����
    undoManager = new UndoManager();

    // ���ÿ������߼�
    setupEventListeners();
}