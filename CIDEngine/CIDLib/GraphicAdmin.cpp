#include "GraphicAdmin.h"
#include "../Include/Define.h"

GraphicAdmin::GraphicAdmin()
{
}

GraphicAdmin::~GraphicAdmin()
{
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CREATE:
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void GraphicAdmin::init()
{
	CID::CIDLog("GraphicAdmin", "winAPI init");

	wc =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		MsgProc,
		0L,
		0L,
		GetModuleHandle(NULL),
		NULL,
		NULL,
		NULL,
		NULL,
		D_WINDOW_NAME,
		NULL
	};
	RegisterClassEx(&wc);

	hWnd = CreateWindow(
		D_WINDOW_NAME,
		D_WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		D_WINDOW_WIDTH,
		D_WINDOW_HEIGHT,
		NULL,
		NULL,
		wc.hInstance,
		NULL
		);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);


	CID::CIDLog("GraphicAdmin", "d3d Init");


	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = D_WINDOW_WIDTH;
	d3dpp.BackBufferHeight = D_WINDOW_HEIGHT;

	g_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT, 
		D3DDEVTYPE_HAL, 
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, 
		&g_pd3dDevice
		);

	createFont();
	createSprite();
}

void GraphicAdmin::createSprite()
{
	if (!SUCCEEDED(D3DXCreateSprite(g_pd3dDevice, &g_pSprite)))
	{
		MessageBox(NULL, "Error : creating the Sprite", NULL, NULL);
	}
}

void GraphicAdmin::createFont()
{
	//!< ÆùÆ® °æ·Î c:\windows\fonts\ 
	if (!SUCCEEDED(D3DXCreateFont(g_pd3dDevice, 30, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, NULL, NULL, NULL, "¸¼Àº°íµñÃ¼", &g_pFont)))
	{
		MessageBox(NULL, "Error : creating the Font", NULL, NULL);
	}
}

void GraphicAdmin::renderStart()
{
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	g_pd3dDevice->BeginScene();
}

void GraphicAdmin::drawText(std::string Text, int x, int y, D3DXCOLOR color)
{
	RECT size;
	size.top = y;
	size.left = x;
	size.right = 0;
	size.bottom = 0;

	g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	g_pFont->DrawTextA(g_pSprite, Text.c_str(), -1, &size, DT_NOCLIP, color);

	g_pSprite->End();
}

void GraphicAdmin::renderEnd()
{
	g_pd3dDevice->EndScene();
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GraphicAdmin::release()
{
	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	if (g_pD3D != NULL)
		g_pD3D->Release();

	if (g_pSprite != NULL)
		g_pSprite->Release();

	if (g_pFont != NULL)
		g_pFont->Release();
}
