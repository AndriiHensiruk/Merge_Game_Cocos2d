#include "CardSprite.h"

Vector <CardSprite*> *(CardSprite::card) = new Vector<CardSprite*> ();

Vector<CardSprite*> *CardSprite::getcard()
{
	return CardSprite::card;
}

bool CardSprite::initCardSprite()
{
	bool ret=false;
	if(Sprite::init())
	{
	
		int n = rand()%7;
		bk = Sprite::create(StringUtils::format("%d.png", n));
		c_number = n;
		
		bk->setPosition(Point(48, 50));
		bk->setScale(0.4, 0.5);
		addChild(bk);

		ret = true;
	}
	return ret;
}

CardSprite* CardSprite::createCardSprite()
{
	auto c = new CardSprite;
	c->initCardSprite();
	c->autorelease();
	card->pushBack(c);
	return c;
}

void CardSprite::moveTo(int r, int c)
{
	this->m_row = r;
	this->m_col = c;
	this->setPosition(Point(96*m_col+4*(m_col+1),96*m_row+4*(m_row+1)));
}


