#pragma once

#include <string>
#include <unordered_map>

struct CardResConfig
{
    // ��ɫ��Ӧ��ͼƬ��Դ·��
    static std::unordered_map<int, std::string> suitToSprite;
    // ������Ӧ��ͼ����Դ·��
    static std::unordered_map<int, std::string> faceToSprite;

    static std::string getSuitSprite(int suit);
    static std::string getFaceSprite(int face);
};
