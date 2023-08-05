#ifndef _CARD__SPRITE_
#define _CARD__SPRITE_

#include "cocos2d.h"
using namespace std;
USING_NS_CC;

#define GAME_ROWS 4
#define GAME_COLS 4

class CardSprite:public cocos2d::Sprite
{
public:
	bool initCardSprite();
	static CardSprite *createCardSprite();
	CREATE_FUNC(CardSprite);
	static Vector<CardSprite*> *card;
	static Vector<CardSprite*> *getcard();
	void moveTo(int r, int c);
	void doubleNumber();
	int c_number;
	int m_col,m_row;
	Sprite* bk;
};

#endif