#pragma once

#include "CID.h"

#define BLACK D3DCOLOR_XRGB(0, 0, 0)
#define WHITE D3DCOLOR_XRGB(255,255,255)
#define BLUE D3DCOLOR_XRGB(0,191,255)
#define LIGHTBLUE D3DCOLOR_XRGB(191,239,255)
#define GINBLUE D3DCOLOR_XRGB(0,0,205)
#define BROWN D3DCOLOR_XRGB(139,69,19)
#define RED D3DCOLOR_XRGB(255,0,0)
#define GREY  D3DCOLOR_XRGB(190, 190, 190)
#define DIMGREY  D3DCOLOR_XRGB(105,105,105)
#define GREEN D3DCOLOR_XRGB(0,100,0)
#define LIGHTGREEN D3DCOLOR_XRGB(124,252,0)



#define Vec2(x, y) D3DXVECTOR2(x, y)
#define Rect(x, y, w, h) DRECT(x, y, w, h)

#define CREATE_SCENE(scene)\
	static scene * create()\
	{\
		scene * temp = new scene(); \
		if (!temp->init())\
		{\
			delete temp; \
			temp = nullptr; \
			return NULL; \
		}\
		return temp; \
	}
class Size
{
public:
	float weight;
	float height;

public:
	Size(){};

	template <typename T>
	Size(T weight, T height)
	{
		this->weight = weight;
		this->height = height;
	};

	~Size(){};
};

class Node
{
private:
	std::vector<Node*> v_childs;

public:
	Node();
	~Node();

public:
	LPDIRECT3DTEXTURE9	m_npTexture;
	D3DXIMAGE_INFO		m_nInfo;

	//!< ��� �⺻ ���
	RECT m_rect;
	int m_zOrder;
	int m_opacity;
	float m_scale;
	bool m_visible;
	float m_rotation;
	D3DCOLOR m_color;
	Size m_contentSize;
	D3DXVECTOR2 m_position;
	D3DXVECTOR2 m_anchorPoint;

public:
	/**
	@brief : ������ ���Ϳ� �߰�
	@param node : �߰��� ���
	*/
	void addChild(Node* node);

	/**
	@brief : ��ġ ��ǥ ����
	@param x : x ��ǥ
	@param y : y ��ǥ
	*/
	void setPosition(int x, int y)
	{
		m_position.x = x;
		m_position.y = y;
	}

	/**
	@brief : ��ġ ��ǥ ����
	@param vec : xy ��ǥ
	*/
	void setPosition(D3DXVECTOR2 vec)
	{
		m_position = vec;
	}

	/**
	@brief : ��ġ ��ǥ ����
	@param x : x ��ǥ
	*/
	void setPositionX(int x)
	{
		m_position.x = x;
	}
	
	/**
	@brief : ��ġ ��ǥ ����
	@param y : y ��ǥ
	*/
	void setPositionY(int y)
	{
		m_position.y = y;
	}

	/**
	@brief : ��Ŀ ��ǥ ����
	@param x : x ��ǥ
	@param y : y ��ǥ
	*/
	void setAnchorPoint(int x, int y)
	{
		m_anchorPoint.x = x;
		m_anchorPoint.y = y;
	}

	/**
	@brief : ��Ŀ ��ǥ ����
	@param vec : xy ��ǥ
	*/
	void setAnchorPoint(D3DXVECTOR2 vec)
	{
		m_anchorPoint = vec;
	}

	/**
	@brief : �� ����
	@param color : ����
	*/
	void setColor(D3DCOLOR color)
	{
		m_color = color;
	}

	/**
	@brief : ������ ����
	@param rect : xy �������� �簢��
	*/
	template <typename T>
	void setRect(T x, T y)
	{
		m_rect.right = x, m_rect.bottom = y;
	}

	/**
	@brief : ������ ����
	@param rect : �簢��
	*/
	void setRect(RECT rect)
	{
		m_rect = rect;
	}

	/**
	@brief : ȸ�� ����
	@param rect : ȸ�� ��
	*/
	template <typename T>
	void setRotation(T rot)
	{
		m_rotation = rot;
	}

	/**
	@brief : ũ�� ����
	@param rect : ũ��
	*/
	template <typename T>
	void setScale(T scale)
	{
		m_scale = scale;
	}

	/**
	@brief : z��ġ ����
	@param zOrder : z��ġ
	*/
	void setZOrder(int zOrder)
	{
		m_zOrder = zOrder;
	}

	/**
	@brief : ������ ����
	@param opacity : �������� ����
	*/
	template <typename T>
	void setOpacity(T opacity)
	{
		m_opacity = (int)opacity;
	}

	/**
	@brief : �������� ����
	@param visible : true ������, false �Ⱥ���
	*/
	void setVisible(bool visible)
	{
		m_visible = visible;
	}

	/**
	@brief : ��ġ ��ǥ ���
	@return m_position : �� ��ġ ��ǥ
	*/
	D3DXVECTOR2 getPosition()
	{
		return m_position;
	}

	/**
	@brief : ��ġ ��ǥ ���
	@return m_position.x : �� x ��ǥ
	*/
	float getPositionX()
	{
		return m_position.x;
	}

	/**
	@brief : ��ġ ��ǥ ���
	@return m_position.y : �� y ��ǥ
	*/
	float getPositionY()
	{
		return m_position.y;
	}

	/**
	@brief : ��Ŀ ����Ʈ ���
	@return m_anchorPoint : �� ��Ŀ ���� ��ǥ
	*/
	D3DXVECTOR2 getAnchorPoint()
	{
		return m_anchorPoint;
	}

	/**
	@brief : ��Ŀ ����Ʈ ���
	@return m_anchorPoint.x : �� ��Ŀ x ��ǥ
	*/
	float getAnchorPointX()
	{
		return m_anchorPoint.x;
	}

	/**
	@brief : ��Ŀ ����Ʈ ���
	@return m_anchorPoint.y : �� ��Ŀ y ��ǥ
	*/
	float getAnchorPointY()
	{
		return m_anchorPoint.y;
	}

	/**
	@brief : ������ �ִ� �� ���
	@return m_color : ������ �ִ� ��
	*/
	D3DCOLOR getColor()
	{
		return m_color;
	}

	/**
	@brief : �簢�� ������ ���
	@return m_rect : �簢��
	*/
	RECT getRect()
	{
		return m_rect;
	}

	/**
	@brief : �簢�� ������ ���
	@return m_rect.right : ���� ������
	*/
	float getRectX()
	{
		return m_rect.right;
	}

	/**
	@brief : �簢�� ������ ���
	@return m_rect.right : ���� ������
	*/
	float getRectY()
	{
		return m_rect.bottom;
	}

	/**
	@brief : ȸ���� �� ���
	@return m_rotation : ȸ���� ��
	*/
	float getRotate()
	{
		return m_rotation;
	}

	/**
	@brief : ������ �ִ� ������ �� ���
	@return m_scale : ������ ��
	*/
	float getScale()
	{
		return m_scale;
	}

	/**
	@brief : ��� �ǰ� �ִ��� ���� ���
	@return m_visible : true ����� , false �����X
	*/
	bool getVisible()
	{
		return m_visible;
	}

public:
	virtual bool init();
	virtual void update();
	virtual void render();
	virtual void release();

	D3DXMATRIX matrix();
};

RECT DRECT(int x, int y, int w, int h);
