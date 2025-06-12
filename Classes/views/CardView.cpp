#include "CardView.h"

CardView* CardView::create(const std::string& size, const std::string& color,
    const std::string& number, const std::string& suit)
{
    CardView* ret = new CardView();
    if (ret && ret->init(size, color, number, suit))
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        delete ret;
        return nullptr;
    }
}

bool CardView::init(const std::string& size, const std::string& color,
    const std::string& number, const std::string& suit)
{
    if (!Node::init()) return false;

    // ��Դ��ƴ��
    std::string numberFile = "res/number/" + size + "_" + color + "_" + number + ".png";
    CCLOG("Loading number sprite: %s", numberFile.c_str());
    numberSprite = Sprite::create(numberFile);
    if (!numberSprite)
    {
        CCLOG("Failed to load number sprite: %s", numberFile.c_str());
        return false;
    }
    // ����ͼê�����ϣ�������ƫ��
    numberSprite->setAnchorPoint(Vec2(0, 1));
    numberSprite->setPosition(Vec2(0, numberSprite->getContentSize().height));
    this->addChild(numberSprite);

    // ƴ�ӻ�ɫͼƬ·��
    std::string suitFile = "res/suits/" + suit + ".png";
    CCLOG("Loading suit sprite: %s", suitFile.c_str());
    suitSprite = Sprite::create(suitFile);
    if (!suitSprite)
    {
        CCLOG("Failed to load suit sprite: %s", suitFile.c_str());
        return false;
    }
    // ��ɫê�����£�������ͼ���·�
    suitSprite->setAnchorPoint(Vec2(1, 0));
    suitSprite->setPosition(Vec2(numberSprite->getContentSize().width, 0));
    this->addChild(suitSprite);

    return true;
}
