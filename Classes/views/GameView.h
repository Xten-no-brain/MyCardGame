// GameView.h
#pragma once

#include "cocos2d.h"
#include "LevelConfig.h"
#include "CardView.h"

class GameView : public cocos2d::Node
{
public:
    // 静态创建方法
    static GameView* create(const LevelConfig& levelConfig);

    // 初始化函数
    bool init(const LevelConfig& levelConfig);

protected:
    // 继承Node的init需要重写无参init，供create调用
    virtual bool init() override;

};
