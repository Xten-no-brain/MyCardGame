#pragma once
#include <vector>
#include "CardModel.h"  // ����Card����

struct LevelConfig
{
    std::vector<Card> Playfield;
    std::vector<Card> Stack;

    static LevelConfig loadFromFile(const std::string& filename);
};
