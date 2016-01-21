#pragma once

#include "../CIDLib/CID.h"
#include "../CIDLib/Scene.h"
#include "../CIDLib/Sprite.h"

class InGame : public Scene
{
private:
	Sprite* sprite;

public:
	static Scene* createScene();

	virtual bool init();

	void update();

	CREATE_SCENE(InGame);
};