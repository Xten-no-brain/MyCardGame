#pragma once
#include "cocos2d.h"

USING_NS_CC;

class CardView : public Node
{
public:
    // �����ӿڣ������ĸ��������ߴ硢��ɫ�����֡���ɫ
    static CardView* create(const std::string& size, const std::string& color,
        const std::string& number, const std::string& suit);

    // ��ʼ������
    bool init(const std::string& size, const std::string& color,
        const std::string& number, const std::string& suit);

private:
    Sprite* numberSprite;
    Sprite* suitSprite;
};
