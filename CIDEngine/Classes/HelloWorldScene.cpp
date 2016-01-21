#include "HelloWorldScene.h"
#include <iostream>

bool HelloWorld::init()
{
	SoundAdmin::getInstance()->playBackgroundMusic("bg.mp3");
	
	Sprite* background = Sprite::create("background.png");
	background->setPosition(Vec2(0, 0));
	this->addChild(background);
	

	sprite = Sprite::create("cid_icon4.png");
	sprite->setPosition(Vec2(100, 100));
	this->addChild(sprite);

	label = Label::create("aaa", WHITE);
	label->setPosition(100, 0);
	label->setRotation(40);
	label->setColor(BLACK);
	this->addChild(label);


	std::cout << sprite->getPositionX() << std::endl;

	startTime = (float)timeGetTime() * 0.001f;


	return true;
}

void HelloWorld::update()
{
	sprite->setRotation(sprite->getRotate() - 10);

	//label->setRotation(label->getRotate() - 10);

	//label->setPositionX(label->getPositionX() - 10);

	float nowTime = (float)timeGetTime() * 0.001f;

	if (nowTime - startTime >= 10)
	{
		//CID::log("aaaa");
	}
}
