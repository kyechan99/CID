#include "Node.h"

Node::Node()
{
	ZeroMemory(&m_position, (sizeof(m_position)));
	ZeroMemory(&m_anchorPoint, sizeof(m_anchorPoint));
	m_rect = Rect(0, 0, 0, 0);
	m_rotation = 0.0f;
	m_opacity = 100;
	m_contentSize = Size(0, 0);
	m_visible = true;
	m_color = WHITE;
	m_scale = 1;
}

Node::~Node()
{
}

bool Node::init()
{
	return true;
}

void Node::update()
{
	for (auto it : v_childs)
	{
		it->update();
	}
}

void Node::render()
{
	for (auto it : v_childs)
	{
		it->render();
	}
}

void Node::release()
{
	for (auto it : v_childs)
	{
		it->release();
		delete it;
	}
	v_childs.clear();
}

void Node::addChild(Node * node)
{
	v_childs.push_back(node);
}

D3DXMATRIX Node::matrix()
{
	m_contentSize.weight = getRect().right;
	m_contentSize.height = getRect().bottom;

	D3DXVECTOR2 anchor = D3DXVECTOR2(getRect().right * m_anchorPoint.x, getRect().bottom * m_anchorPoint.y);
	D3DXVECTOR2 scale = D3DXVECTOR2(m_scale, m_scale);
	D3DXVECTOR2 center = D3DXVECTOR2(getRect().right / 2 * m_scale, getRect().bottom / 2 * m_scale);
	D3DXVECTOR2 trans = D3DXVECTOR2(m_position.x - anchor.x, m_position.y - anchor.y);

	float rot = D3DXToRadian(m_rotation);

	D3DXMATRIX matrix;
	D3DXMatrixTransformation2D(&matrix, &anchor, 1, &scale, &center, rot, &trans);

	return matrix;
}

RECT DRECT(int x, int y, int w, int h)
{
	RECT rect;
	rect.left = x;
	rect.top = y;
	rect.right = w;
	rect.bottom = h;
	return rect;
}