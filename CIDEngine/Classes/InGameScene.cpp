#include "InGameScene.h"
#include "../CIDLib/Sprite.h"
#include "../CIDLib/SoundAdmin.h"
#include "../CIDLib/GraphicAdmin.h"

bool InGame::init()
{
	SoundAdmin::getInstance()->playBackgroundMusic("Resource/bg.mp3");

	sprite = Sprite::create("Resource/cid_icon4.png");
	sprite->setPosition(Vec2(1000, 100));
	this->addChild(sprite);

	return true;
}

void InGame::update()
{
}
