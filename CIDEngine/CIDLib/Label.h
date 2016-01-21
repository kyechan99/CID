#pragma once
#include "GraphicAdmin.h"
#include "Node.h"
#include "CID.h"

class Label : public Node
{
private:
	std::string msg;

public:
	static Label* create(std::string Text, D3DXCOLOR color);

	virtual void update();
	virtual void render();
	virtual void release();

	bool initWithString(std::string Text, D3DXCOLOR color);

};
