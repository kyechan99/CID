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

	//!< 노드 기본 기능
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
	@brief : 노드관리 벡터에 추가
	@param node : 추가할 노드
	*/
	void addChild(Node* node);

	/**
	@brief : 위치 좌표 설정
	@param x : x 좌표
	@param y : y 좌표
	*/
	void setPosition(int x, int y)
	{
		m_position.x = x;
		m_position.y = y;
	}

	/**
	@brief : 위치 좌표 설정
	@param vec : xy 좌표
	*/
	void setPosition(D3DXVECTOR2 vec)
	{
		m_position = vec;
	}

	/**
	@brief : 위치 좌표 설정
	@param x : x 좌표
	*/
	void setPositionX(int x)
	{
		m_position.x = x;
	}
	
	/**
	@brief : 위치 좌표 설정
	@param y : y 좌표
	*/
	void setPositionY(int y)
	{
		m_position.y = y;
	}

	/**
	@brief : 앵커 좌표 설정
	@param x : x 좌표
	@param y : y 좌표
	*/
	void setAnchorPoint(int x, int y)
	{
		m_anchorPoint.x = x;
		m_anchorPoint.y = y;
	}

	/**
	@brief : 앵커 좌표 설정
	@param vec : xy 좌표
	*/
	void setAnchorPoint(D3DXVECTOR2 vec)
	{
		m_anchorPoint = vec;
	}

	/**
	@brief : 색 설정
	@param color : 색깔
	*/
	void setColor(D3DCOLOR color)
	{
		m_color = color;
	}

	/**
	@brief : 사이즈 설정
	@param rect : xy 사이즈의 사각형
	*/
	template <typename T>
	void setRect(T x, T y)
	{
		m_rect.right = x, m_rect.bottom = y;
	}

	/**
	@brief : 사이즈 설정
	@param rect : 사각형
	*/
	void setRect(RECT rect)
	{
		m_rect = rect;
	}

	/**
	@brief : 회전 설정
	@param rect : 회전 수
	*/
	template <typename T>
	void setRotation(T rot)
	{
		m_rotation = rot;
	}

	/**
	@brief : 크기 설정
	@param rect : 크기
	*/
	template <typename T>
	void setScale(T scale)
	{
		m_scale = scale;
	}

	/**
	@brief : z위치 설정
	@param zOrder : z위치
	*/
	void setZOrder(int zOrder)
	{
		m_zOrder = zOrder;
	}

	/**
	@brief : 불투명도 설정
	@param opacity : 불투명의 정도
	*/
	template <typename T>
	void setOpacity(T opacity)
	{
		m_opacity = (int)opacity;
	}

	/**
	@brief : 보여질지 설정
	@param visible : true 보여짐, false 안보임
	*/
	void setVisible(bool visible)
	{
		m_visible = visible;
	}

	/**
	@brief : 위치 좌표 얻기
	@return m_position : 현 위치 좌표
	*/
	D3DXVECTOR2 getPosition()
	{
		return m_position;
	}

	/**
	@brief : 위치 좌표 얻기
	@return m_position.x : 현 x 좌표
	*/
	float getPositionX()
	{
		return m_position.x;
	}

	/**
	@brief : 위치 좌표 얻기
	@return m_position.y : 현 y 좌표
	*/
	float getPositionY()
	{
		return m_position.y;
	}

	/**
	@brief : 앵커 포인트 얻기
	@return m_anchorPoint : 현 앵커 설정 좌표
	*/
	D3DXVECTOR2 getAnchorPoint()
	{
		return m_anchorPoint;
	}

	/**
	@brief : 앵커 포인트 얻기
	@return m_anchorPoint.x : 현 앵커 x 좌표
	*/
	float getAnchorPointX()
	{
		return m_anchorPoint.x;
	}

	/**
	@brief : 앵커 포인트 얻기
	@return m_anchorPoint.y : 현 앵커 y 좌표
	*/
	float getAnchorPointY()
	{
		return m_anchorPoint.y;
	}

	/**
	@brief : 설정되 있는 색 얻기
	@return m_color : 설정되 있는 색
	*/
	D3DCOLOR getColor()
	{
		return m_color;
	}

	/**
	@brief : 사각형 사이즈 얻기
	@return m_rect : 사각형
	*/
	RECT getRect()
	{
		return m_rect;
	}

	/**
	@brief : 사각형 사이즈 얻기
	@return m_rect.right : 가로 사이즈
	*/
	float getRectX()
	{
		return m_rect.right;
	}

	/**
	@brief : 사각형 사이즈 얻기
	@return m_rect.right : 세로 사이즈
	*/
	float getRectY()
	{
		return m_rect.bottom;
	}

	/**
	@brief : 회전된 값 얻기
	@return m_rotation : 회전된 값
	*/
	float getRotate()
	{
		return m_rotation;
	}

	/**
	@brief : 설정되 있는 스케일 값 얻기
	@return m_scale : 스케일 값
	*/
	float getScale()
	{
		return m_scale;
	}

	/**
	@brief : 사용 되고 있는지 유무 얻기
	@return m_visible : true 사용중 , false 사용중X
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
