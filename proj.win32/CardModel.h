#pragma once

#include "cocos2d.h"

enum CardSuitType
{
    CST_NONE = -1,
    CST_CLUBS,      // ÷��
    CST_DIAMONDS,   // ����
    CST_HEARTS,     // ����
    CST_SPADES,     // ����
    CST_NUM_CARD_SUIT_TYPES
};

enum CardFaceType
{
    CFT_NONE = -1,
    CFT_ACE,
    CFT_TWO,
    CFT_THREE,
    CFT_FOUR,
    CFT_FIVE,
    CFT_SIX,
    CFT_SEVEN,
    CFT_EIGHT,
    CFT_NINE,
    CFT_TEN,
    CFT_JACK,
    CFT_QUEEN,
    CFT_KING,
    CFT_NUM_CARD_FACE_TYPES
};

// ����ģ�ͽṹ��
struct Card
{
    CardFaceType CardFace = CFT_NONE;
    CardSuitType CardSuit = CST_NONE;
    cocos2d::Vec2 Position = cocos2d::Vec2::ZERO;

    // ���������ַ���
    std::string getCardFaceStr() const
    {
        switch (CardFace)
        {
        case CFT_ACE: return "Ace";
        case CFT_TWO: return "Two";
        case CFT_THREE: return "Three";
        case CFT_FOUR: return "Four";
        case CFT_FIVE: return "Five";
        case CFT_SIX: return "Six";
        case CFT_SEVEN: return "Seven";
        case CFT_EIGHT: return "Eight";
        case CFT_NINE: return "Nine";
        case CFT_TEN: return "Ten";
        case CFT_JACK: return "Jack";
        case CFT_QUEEN: return "Queen";
        case CFT_KING: return "King";
        default: return "Unknown";
        }
    }

    // ���ػ�ɫ�ַ���
    std::string getCardSuitStr() const
    {
        switch (CardSuit)
        {
        case CST_CLUBS: return "Clubs";
        case CST_DIAMONDS: return "Diamonds";
        case CST_HEARTS: return "Hearts";
        case CST_SPADES: return "Spades";
        default: return "Unknown";
        }
    }
};
