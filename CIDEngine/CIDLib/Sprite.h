#pragma once
#include "GraphicAdmin.h"
#include "Node.h"

class Sprite : public Node
{
private:

public:
	static Sprite* create(std::string path);

	virtual void update();
	virtual void render();
	virtual void release();

	RECT getBoundingBox()
	{
		//RECT rect;
		//rect.left = m_position.x - m_posit
		//getRect();
	}
};
