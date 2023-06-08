#pragma once
#include "pch.h"
#include "CObject.h"
#include "Texture.h"
#include "TextureManager.h"


class EmptyObject :public CObject
{
public:
	
	//�׸����� �� �ؽ���
	Texture* m_pTexture;

	virtual void Update();
	virtual void Render(HDC _dc);
	//�ʼ�
	virtual EmptyObject* Clone() { return new EmptyObject(*this); }
	int m_iIndex;
public:
	EmptyObject();
	~EmptyObject();

};

