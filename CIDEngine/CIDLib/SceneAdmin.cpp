#include "SceneAdmin.h"

void SceneAdmin::init()
{
	if (m_curScene != NULL)
	{
		m_curScene->release();
		delete m_curScene;
		m_curScene = NULL;
	}

	m_curScene = HelloWorld::create();
}

void SceneAdmin::update()
{
	m_curScene->update();
}

void SceneAdmin::pushScene(Scene* scene)
{
	this->m_scene[m_sceneNum] = m_curScene;

	m_curScene->release();
	m_curScene = nullptr;
	m_curScene = scene;
	m_curScene->init();
	
	m_sceneNum++;
	this->m_scene[m_sceneNum] = scene;
}

void SceneAdmin::popScene()
{
	m_curScene->release();
	m_curScene = nullptr;

	m_sceneNum--;
	m_curScene = this->m_scene[m_sceneNum];

	m_curScene->init();
}

void SceneAdmin::replaceScene(Scene* scene)
{
	m_curScene->release();
	m_curScene = nullptr;
	m_curScene = scene;
	m_curScene->init();
}