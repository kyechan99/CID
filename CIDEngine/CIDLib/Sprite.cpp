#include "Sprite.h"

Sprite* Sprite::create(std::string path)
{
	Sprite* sprite = new Sprite();

	std::string src = "Resource/" + path;

	D3DXCreateTextureFromFileEx(
		GraphicAdmin::getInstance()->getDevice(),
		src.c_str(),
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		0x0000001,
		0x0000001,
		0x00FFFFFF,
		&sprite->m_nInfo,
		NULL,
		&sprite->m_npTexture
		);

	sprite->m_rect.right = sprite->m_nInfo.Width;
	sprite->m_rect.bottom = sprite->m_nInfo.Height;

	return sprite;
}

void Sprite::update()
{
	Node::update();
}

void Sprite::render()
{
	Node::render();
	
	if (m_visible)
	{
		GraphicAdmin::getInstance()->getSprite()->Begin(D3DXSPRITE_ALPHABLEND);
		GraphicAdmin::getInstance()->getSprite()->SetTransform(&matrix());
		GraphicAdmin::getInstance()->getSprite()->Draw(m_npTexture, &m_rect, NULL, NULL, m_color);
		GraphicAdmin::getInstance()->getSprite()->End();
	}
}

void Sprite::release()
{
	Node::release();
}
