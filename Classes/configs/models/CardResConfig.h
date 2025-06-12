#pragma once

#include <string>
#include <unordered_map>

struct CardResConfig
{
    // 花色对应的图片资源路径
    static std::unordered_map<int, std::string> suitToSprite;
    // 点数对应的图标资源路径
    static std::unordered_map<int, std::string> faceToSprite;

    static std::string getSuitSprite(int suit);
    static std::string getFaceSprite(int face);
};
