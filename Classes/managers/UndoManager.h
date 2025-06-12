#pragma once

#include "LevelConfig.h"
#include "GameModel.h"
#include "GameView.h"
#include <string>

class GameController
{
public:
    GameController();
    ~GameController();

    // ��ʼ����Ϸ
    void initGame(const std::string& levelId);

    // ���ܻ���Ҫ���������ӿڣ������¼������

private:
    void setupEventListeners();

    GameModel* gameModel = nullptr;
    GameView* gameView = nullptr;
    UndoManager* undoManager = nullptr;
};
