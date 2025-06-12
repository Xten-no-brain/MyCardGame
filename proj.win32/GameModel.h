#pragma once
#include <vector>
#include "CardModel.h"

class GameModel
{
public:
    std::vector<CardModel> playfield;
    std::vector<CardModel> stack;
    CardModel currentBottomCard;
};