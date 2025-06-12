#pragma once
#include <vector>
#include "CardModel.h"  // 引用Card定义

struct LevelConfig
{
    std::vector<Card> Playfield;
    std::vector<Card> Stack;

    static LevelConfig loadFromFile(const std::string& filename);
};
