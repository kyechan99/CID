#pragma once

#include "main.h"

#pragma warning(disable: 4996)

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
	AllocConsole();

	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	
	Manager manager;

	manager.init();

	manager.loop();

	manager.release();

	FreeConsole();
}
