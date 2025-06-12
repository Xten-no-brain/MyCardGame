#pragma once
#include "cocos2d.h"
#include "LevelConfig.h"
#include "CardView.h"


USING_NS_CC;

class CardView : public Node
{
public:
    // 创建接口，传入四个参数：尺寸、颜色、数字、花色
    static CardView* create(const std::string& size, const std::string& color,
        const std::string& number, const std::string& suit);

    // 初始化函数
    bool init(const std::string& size, const std::string& color,
        const std::string& number, const std::string& suit);

private:
    Sprite* numberSprite;
    Sprite* suitSprite;
};
