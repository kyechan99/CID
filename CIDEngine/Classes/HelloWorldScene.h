#pragma once

#include "InGameScene.h"
#include "../CIDLib/CID.h"
#include "../CIDLib/Scene.h"
#include "../CIDLib/Sprite.h"
#include "../CIDLib/Label.h"
#include "../CIDLib/SoundAdmin.h"
#include "../CIDLib/GraphicAdmin.h"
#include "../CIDLib/Manager.h"

class HelloWorld : public Scene
{
private:
	Sprite* sprite;
	float startTime;
	Label* label;

public:
	bool init();

	void update();

	CREATE_SCENE(HelloWorld);
};