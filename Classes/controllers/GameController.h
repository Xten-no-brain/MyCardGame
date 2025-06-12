#pragma once

#include "cocos2d.h"
#include "GameModel.h"
#include "GameView.h"
#include "UndoManager.h"

class GameController
{
public:
    void initGame(const std::string& levelId);

private:
    GameModel* gameModel = nullptr;
    GameView* gameView = nullptr;
    UndoManager* undoManager = nullptr;

    void setupEventListeners();
};
