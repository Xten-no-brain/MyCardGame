#include "GameView.h"
#include "CardView.h"

void GameView::init(const LevelConfig& levelConfig)
{
    // 设置初始布局
    for (const auto& cardConfig : levelConfig.playfield)
    {
        CardView* cardView = 
            CardView::create(CardModel(cardConfig.cardFace, cardConfig.cardSuit));
        cardView->setPosition(cardConfig.position);
        this->addChild(cardView);
    }
    // 更多初始化逻辑
}