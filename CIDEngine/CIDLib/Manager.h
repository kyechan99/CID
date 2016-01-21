#pragma once

#include "CID.h"
#include "GraphicAdmin.h"
#include "SceneAdmin.h"

class Manager : public CSingleton<Manager>
{
private:

public:
	Manager();
	~Manager();

	void init();
	void loop();
	void release();

	void update();
	void render();

public:
	void replaceScene(Scene* scene);
	void pushScene(Scene* scene);
	void popScene();

};