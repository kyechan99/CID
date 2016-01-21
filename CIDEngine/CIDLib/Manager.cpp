#include "Manager.h"

Manager::Manager()
{

}

Manager::~Manager()
{

}

void Manager::init()
{
	GraphicAdmin::getInstance()->init();

	SceneAdmin::getInstance()->init();
}

void Manager::loop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			update();
			render();
			Sleep(1);
		}
	}
}

void Manager::release()
{
	SceneAdmin::getInstance()->getScene()->release();

	GraphicAdmin::getInstance()->release();
}

void Manager::update()
{
	SceneAdmin::getInstance()->getScene()->update();
}

void Manager::render()
{
	GraphicAdmin::getInstance()->renderStart();

	SceneAdmin::getInstance()->getScene()->render();

	//GraphicAdmin::getInstance()->drawText("aaa", 1000, 100, WHITE);

	GraphicAdmin::getInstance()->renderEnd();
}

void Manager::replaceScene(Scene * scene)
{
	SceneAdmin::getInstance()->replaceScene(scene);
}

void Manager::pushScene(Scene * scene)
{
	SceneAdmin::getInstance()->pushScene(scene);
}

void Manager::popScene()
{
	SceneAdmin::getInstance()->popScene();
}