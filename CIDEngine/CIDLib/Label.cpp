#include "Label.h"

Label* Label::create(const std::string Text, D3DXCOLOR color)
{
	Label* label = new Label();

	label->initWithString(Text, color);

	return label;
}

void Label::update()
{
	Node::update();
}

void Label::render()
{
	Node::render();

	if (m_visible)
	{
		/*RECT size;
		size.top = getPositionY();
		size.left = getPositionX();
		size.right = 0;
		size.bottom = 0;

		setRect(size);*/

		GraphicAdmin::getInstance()->getSprite()->Begin(D3DXSPRITE_ALPHABLEND);

		GraphicAdmin::getInstance()->getSprite()->SetTransform(&matrix());

		GraphicAdmin::getInstance()->getFont()->DrawTextA(
			GraphicAdmin::getInstance()->getSprite(),
			msg.c_str(),
			-1,
			&getRect(),
			DT_NOCLIP,
			getColor());

		GraphicAdmin::getInstance()->getSprite()->End();
	}
}

void Label::release()
{
	Node::release();
}


bool Label::initWithString(std::string Text, D3DXCOLOR color)
{
	RECT size;
	size.top = getPositionY();
	size.left = getPositionX();
	size.right = 0;
	size.bottom = 0;

	setRect(size);
	setColor(color);

	msg = Text;


	GraphicAdmin::getInstance()->getSprite()->Begin(D3DXSPRITE_ALPHABLEND);

	GraphicAdmin::getInstance()->getSprite()->SetTransform(&matrix());

	GraphicAdmin::getInstance()->getFont()->DrawTextA(
		GraphicAdmin::getInstance()->getSprite(),
		msg.c_str(),
		-1,
		&getRect(),
		DT_NOCLIP,
		getColor());

	GraphicAdmin::getInstance()->getSprite()->End();

	return true;
}