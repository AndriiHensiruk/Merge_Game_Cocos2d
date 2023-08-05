#ifndef _GAME__SCENE__
#define _GAME__SCENE__

#include "cocos2d.h"
#include "CardSprite.h"
#define GAME_ROWS 4
#define GAME_COLS 4
USING_NS_CC;
using namespace std;

class GameScene:public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void createCardSprite();
	CREATE_FUNC(GameScene);

	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void judgegame();
	void judgemove();
	void endScene();
	void restartgame();
	void endgame();
	void regame();

	LayerColor* colorBack;
	LayerColor* layerTiled;
	LayerColor* scorelayer;
	LayerColor* bestlayer;
	LayerColor* endlayer;
	int map[4][4];
	Vec2 startpt, endpt;
	bool m_startMove;
	bool ismoveleft;
	bool ismoveright;
	bool ismoveup;
	bool ismovedown;
	bool m_sound_clear;
	int score;
	int bestScore;
	int labelfontsize;
	int bestfontsize;
	Label* restartBtn;
	Label* endBtn;
	Label* cancerBtn;
	Label* Score;
	Label* title;
	Label* labelscore;
	Label* Best;
	Label* bestscore;
	MenuItemImage* endmenu;
	MenuItemLabel* restartmenu;
	MenuItemLabel* exitmenu;
	MenuItemLabel* cancermenu;
	Sprite* endsprite;
	
};

#endif