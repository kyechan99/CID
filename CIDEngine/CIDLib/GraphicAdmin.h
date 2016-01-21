#pragma once
#include "CID.h"

class GraphicAdmin : public CSingleton<GraphicAdmin>
{
private:

public:
	GraphicAdmin();
	~GraphicAdmin();

public:
	HWND hWnd;
	WNDCLASSEX wc;
	LPD3DXFONT g_pFont;
	LPDIRECT3D9	g_pD3D;
	LPD3DXSPRITE g_pSprite;
	LPDIRECT3DDEVICE9	g_pd3dDevice;

public:
	void init();
	void createSprite();
	void createFont();
	void renderStart();

	void drawText(std::string text, int x, int y, D3DXCOLOR color);
	void renderEnd();
	void release();

public:
	LPDIRECT3DDEVICE9 getDevice()
	{
		return g_pd3dDevice;
	}

	LPD3DXSPRITE getSprite() 
	{
		return g_pSprite;
	}

	LPD3DXFONT getFont()
	{
		return g_pFont;
	}
};