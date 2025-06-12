#include "LevelConfig.h"
#include "CardModel.h"
#include "json/document.h"
#include "cocos2d.h"

// ��������������ռ䣬���� models������Cardǰ׺
// using namespace models;

LevelConfig LevelConfig::loadFromFile(const std::string& filename)
{
    LevelConfig config;

    // ��ȡ�ļ�
    std::string jsonContent = cocos2d::FileUtils::getInstance()->getStringFromFile(filename);

    if (jsonContent.empty())
    {
        CCLOG("Failed to load file: %s", filename.c_str());
        return config;
    }

    // ���� JSON
    rapidjson::Document document;
    document.Parse(jsonContent.c_str());

    // ���� Playfield
    if (document.HasMember("Playfield") && document["Playfield"].IsArray())
    {
        const rapidjson::Value& playfield = document["Playfield"];
        for (rapidjson::SizeType i = 0; i < playfield.Size(); i++)
        {
            const rapidjson::Value& cardJson = playfield[i];
            Card c;
            c.CardFace = cardJson["CardFace"].GetInt();
            c.CardSuit = cardJson["CardSuit"].GetInt();
            c.Position = cocos2d::Vec2(cardJson["Position"]["x"].GetFloat(),
                cardJson["Position"]["y"].GetFloat());
            config.Playfield.push_back(c);
        }
    }

    // ���� Stack
    if (document.HasMember("Stack") && document["Stack"].IsArray())
    {
        const rapidjson::Value& stack = document["Stack"];
        for (rapidjson::SizeType i = 0; i < stack.Size(); i++)
        {
            const rapidjson::Value& cardJson = stack[i];
            Card c;
            c.CardFace = cardJson["CardFace"].GetInt();
            c.CardSuit = cardJson["CardSuit"].GetInt();
            c.Position = cocos2d::Vec2(cardJson["Position"]["x"].GetFloat(),
                cardJson["Position"]["y"].GetFloat());
            config.Stack.push_back(c);
        }
    }

    return config;
}