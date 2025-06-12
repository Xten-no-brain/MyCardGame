#include "cocos2d.h"
#include "json/document.h"
#include <vector>

struct CardConfig
{
    int cardFace;
    int cardSuit;
    cocos2d::Vec2 position;
};

struct LevelConfig
{
    std::vector<CardConfig> playfield;
    std::vector<CardConfig> stack;
};

class LevelConfigLoader
{
public:
    static LevelConfig loadLevelConfig(const std::string& levelId);
};