#ifndef __LEVEL_CONFIG_H__
#define __LEVEL_CONFIG_H__

#include "cocos2d.h"
#include <vector>

// 定义卡牌结构
struct Card 
{
    int CardFace;  // 使用数字表示的卡面
    int CardSuit;  // 使用数字表示的花色
    cocos2d::Vec2 Position;  // 卡牌位置
    std::string getCardFaceStr() const;  // 获取卡面字符串
    std::string getCardSuitStr() const;  // 获取花色字符串
};

// 定义关卡配置结构
struct LevelConfig 
{
    std::vector<Card> Playfield;  // 主牌区
    std::vector<Card> Stack;      // 卡堆

    static LevelConfig loadFromFile(const std::string& filename);  // 从文件加载关卡配置
};

#endif // __LEVEL_CONFIG_H__
