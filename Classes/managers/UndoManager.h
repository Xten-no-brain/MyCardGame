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

    // 初始化游戏
    void initGame(const std::string& levelId);

    // 可能还需要其它公共接口，比如事件处理等

private:
    void setupEventListeners();

    GameModel* gameModel = nullptr;
    GameView* gameView = nullptr;
    UndoManager* undoManager = nullptr;
};
