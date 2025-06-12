#include "GameView.h"

GameView* GameView::create(const LevelConfig& levelConfig)
{
    GameView* ret = new GameView();
    if (ret && ret->init(levelConfig))
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        delete ret;
        return nullptr;
    }
}

bool GameView::init(const LevelConfig& levelConfig)
{
    if (!Node::init())
        return false;

    for (const auto& cardConfig : levelConfig.playfield)
    {
        CardView* cardView = 
            CardView::create(CardModel(cardConfig.cardFace, cardConfig.cardSuit));
        cardView->setPosition(cardConfig.position);
        this->addChild(cardView);
    }
    return true;
}

bool GameView::init()
{
    return Node::init();
}
