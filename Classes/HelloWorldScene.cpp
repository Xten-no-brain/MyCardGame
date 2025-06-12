/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "LevelConfig.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/'"
        "in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    CCLOG("HelloWorld::init() called");

    if (!Scene::init())
    {
        CCLOG("Scene::init() failed");
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // ±³¾°Í¼
    auto background = Sprite::create("card_general.png");
    if (!background)
    {
        CCLOG("Failed to load background card_general.png");
    }
    else
    {
        // ÉèÖÃ±³¾°Í¼¾ÓÖÐ
        background->setPosition(Vec2(origin.x + visibleSize.width / 2, 
            origin.y + visibleSize.height / 2));

        // »ñÈ¡±³¾°Í¼Ô­Ê¼³ß´ç
        Size bgSize = background->getContentSize();

        // ¼ÆËãËõ·Å±ÈÀý£¬ÈÃ±³¾°Í¼ÆÌÂúÕû¸öÆÁÄ»
        float scaleX = visibleSize.width / bgSize.width;
        float scaleY = visibleSize.height / bgSize.height;

        // È¡×î´óËõ·Å±ÈÀý£¬±£Ö¤±³¾°Í¼ÍêÈ«¸²¸ÇÆÁÄ»
        float scale = std::max(scaleX, scaleY);

        background->setScale(scale);

        // Ìí¼Ó±³¾°Í¼£¬²ã¼¶×îµÍ
        this->addChild(background, 0);
    }

    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (!closeItem ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (!label)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);
    }

    // ¿¨ÅÆÍ¼Æ¬
    auto sp = Sprite::create("number/big_red_A.png");
    if (!sp)
    {
        CCLOG("Failed to load sprite number/big_red_A.png");
    }
    else
    {
        CCLOG("Loaded sprite successfully");
        sp->setPosition(visibleSize.width / 2 + origin.x, 
            visibleSize.height / 2 + origin.y);
        this->addChild(sp, 2);
    }

    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
