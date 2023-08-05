#include "MainScene.h"
#include "GameScene.h"
#include "AudioEngine.h"


//using namespace CocosDenshion;
USING_NS_CC;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg = Sprite::create("map.png");
	bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    bg->setScale(1.19, 4);
	addChild(bg);

	auto title = Label::createWithTTF("Marge Game","fonts/HelloKitty.ttf",75);
	title->setPosition(Point(visibleSize.width/2, visibleSize.height*3/4));
	addChild(title);

	auto normalSprite = Sprite::create("000.png");
	auto selectSprite = Sprite::create("001.png");
	auto closeItem = MenuItemSprite::create(normalSprite,selectSprite,NULL,CC_CALLBACK_0(MainScene::nextscene,this));
	closeItem->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    closeItem->setScale(0.7, 1);
	auto menu = Menu::createWithItem(closeItem);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);
    AudioEngine::play2d("Menu.mp3", true, 0.1f);
    //AudioEngine::preload("move.mp3");

    return true;
}


void MainScene::nextscene()
{
    AudioEngine::play2d("move.mp3", false, 0.5f);
	Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5, GameScene::createScene()));
}

void MainScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
