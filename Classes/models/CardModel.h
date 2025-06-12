#pragma once
#include "cocos2d.h"
#include <string>

enum CardFaceType
{
    CFT_ACE = 1,
    CFT_TWO,
    // ...
    CFT_KING
};

enum CardSuitType
{
    CST_CLUBS = 1,
    CST_DIAMONDS,
    CST_HEARTS,
    CST_SPADES
};

struct Card
{
    int CardFace;
    int CardSuit;
    cocos2d::Vec2 Position;

    std::string getCardFaceStr() const;
    std::string getCardSuitStr() const;
};
