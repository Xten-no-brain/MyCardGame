// GameView.h
#pragma once

#include "cocos2d.h"
#include "LevelConfig.h"
#include "CardView.h"

class GameView : public cocos2d::Node
{
public:
    // ��̬��������
    static GameView* create(const LevelConfig& levelConfig);

    // ��ʼ������
    bool init(const LevelConfig& levelConfig);

protected:
    // �̳�Node��init��Ҫ��д�޲�init����create����
    virtual bool init() override;

};
