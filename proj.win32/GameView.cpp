#include "GameView.h"
#include "CardView.h"

void GameView::init(const LevelConfig& levelConfig)
{
    // ���ó�ʼ����
    for (const auto& cardConfig : levelConfig.playfield)
    {
        CardView* cardView = 
            CardView::create(CardModel(cardConfig.cardFace, cardConfig.cardSuit));
        cardView->setPosition(cardConfig.position);
        this->addChild(cardView);
    }
    // �����ʼ���߼�
}