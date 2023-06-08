#pragma once
#include "pch.h"
#include "CObject.h"
#include "Texture.h"
#include "TextureManager.h"

class CDrain
{
};



class CDrain :public CObject
{
public:

	//�׸����� �� �ؽ���
	Texture* m_DrainTexture[3];
	int m_iIndex;
	// 	//�ִϸ��̼����� �� �ؽ���
	// 	Texture* m_pTextureAnimation;

	bool m_bIsOn;
	bool m_bIsPast;


	virtual void Update();
	virtual void Render(HDC _dc);
	//�ʼ�
	virtual CDrain* Clone() { return new CDrain(*this); }

public:
	CDrain();
	~CDrain();

};


