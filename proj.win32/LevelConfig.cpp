#include "LevelConfig.h"
#include "models/CardModel.h"
#include "json/document.h"
#include "cocos2d.h"

std::string Card::getCardFaceStr() const
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

std::string Card::getCardSuitStr() const
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

LevelConfig LevelConfig::loadFromFile(const std::string& filename)
{
    LevelConfig config;

    // 加载 JSON 文件
    std::string jsonContent = 
        cocos2d::FileUtils::getInstance()->getStringFromFile(filename);

    if (jsonContent.empty()) 
    {
        CCLOG("Failed to load file: %s", filename.c_str());
        return config;
    }

    // 解析 JSON
    rapidjson::Document document;
    document.Parse(jsonContent.c_str());

    // 解析 Playfield
    if (document.HasMember("Playfield") && document["Playfield"].IsArray()) 
    {
        const rapidjson::Value& playfield = document["Playfield"];
        for (rapidjson::SizeType i = 0; i < playfield.Size(); i++) 
        {
            const rapidjson::Value& card = playfield[i];
            Card c;
            c.CardFace = card["CardFace"].GetInt();
            c.CardSuit = card["CardSuit"].GetInt();
            c.Position = cocos2d::Vec2(card["Position"]["x"].GetFloat(), 
                card["Position"]["y"].GetFloat());
            config.Playfield.push_back(c);
        }
    }

    // 解析 Stack
    if (document.HasMember("Stack") && document["Stack"].IsArray()) 
    {
        const rapidjson::Value& stack = document["Stack"];
        for (rapidjson::SizeType i = 0; i < stack.Size(); i++) 
        {
            const rapidjson::Value& card = stack[i];
            Card c;
            c.CardFace = card["CardFace"].GetInt();
            c.CardSuit = card["CardSuit"].GetInt();
            c.Position = cocos2d::Vec2(card["Position"]["x"].GetFloat(), 
                card["Position"]["y"].GetFloat());
            config.Stack.push_back(c);
        }
    }

    return config;
}
