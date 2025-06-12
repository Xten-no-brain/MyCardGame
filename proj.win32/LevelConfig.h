#ifndef __LEVEL_CONFIG_H__
#define __LEVEL_CONFIG_H__

#include "cocos2d.h"
#include <vector>

// ���忨�ƽṹ
struct Card 
{
    int CardFace;  // ʹ�����ֱ�ʾ�Ŀ���
    int CardSuit;  // ʹ�����ֱ�ʾ�Ļ�ɫ
    cocos2d::Vec2 Position;  // ����λ��
    std::string getCardFaceStr() const;  // ��ȡ�����ַ���
    std::string getCardSuitStr() const;  // ��ȡ��ɫ�ַ���
};

// ����ؿ����ýṹ
struct LevelConfig 
{
    std::vector<Card> Playfield;  // ������
    std::vector<Card> Stack;      // ����

    static LevelConfig loadFromFile(const std::string& filename);  // ���ļ����عؿ�����
};

#endif // __LEVEL_CONFIG_H__
