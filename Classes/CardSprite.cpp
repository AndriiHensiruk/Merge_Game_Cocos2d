#include "CardSprite.h"

//List for working with created class objects
Vector <CardSprite*> *(CardSprite::card) = new Vector<CardSprite*> ();

Vector<CardSprite*> *CardSprite::getcard()
{
	return CardSprite::card;
}

//generating a random sprite for the card
bool CardSprite::initCardSprite()
{
	bool ret=false;
	if(Sprite::init())
	{
	
		int n = rand()%7;
		bk = Sprite::create(StringUtils::format("%d.png", n)); //selection by sprite name
		c_number = n;	//saving the card number for verification 
		bk->setPosition(Point(49, 50));
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

//method of moving objects, the numbers were chosen according to the size of the cells
void CardSprite::moveTo(int r, int c)
{
	this->m_row = r;
	this->m_col = c;
	this->setPosition(Point(96*m_col+4*(m_col+1),96*m_row+4*(m_row+1)));
}


