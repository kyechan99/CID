#pragma once

#include "CID.h"
#include "Scene.h"
#include "../Classes/HelloWorldScene.h"

class SceneAdmin : public CSingleton<SceneAdmin>
{
private:
	int m_sceneNum = 0;
	Scene* m_curScene;
	Scene* m_scene[10];

public:
	void init();
	void update();

public:
	void replaceScene(Scene* scene);
	void pushScene(Scene* scene);
	void popScene();

	int getSceneNum()
	{
		return m_sceneNum;
	}

	Scene* getScene()
	{
		return m_curScene;
	}


};