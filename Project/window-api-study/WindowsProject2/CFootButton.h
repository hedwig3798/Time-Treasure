///������ ���� ��ư �����

#pragma once
#include "pch.h"
#include "CObject.h"
#include "Texture.h"
#include "TextureManager.h"

#include "CCollider.h" ///�浹üũ

class CCollider;
class Texture;

class CFootButton :public CObject
{
public:
	CFootButton(bool _isPast);
	~CFootButton();

	//�׸����� �� �ؽ��� 4�� �ʿ��ϴ�
	Texture* m_pTexture;
	int m_iIndex;
	// 	//�ִϸ��̼����� �� �ؽ���
	// 	Texture* m_pTextureAnimation;


	bool m_bIsOn;	//��Ҵ� �ȹ�Ҵ�
	bool m_bIsPast;

	

	//�� ������Ʈ�� ����
	//FOOTBUTTON_STATE m_FootButtonState;

	//���º�ȭ ������ �߰��ؾߵǳ�??


	virtual void Update();
	virtual void Render(HDC _dc);
	virtual CFootButton* Clone() { return new CFootButton(*this); }

	void IsOn()
	{
		m_bIsOn = true;	//��Ҵ�
	}
	void SetIsOn(bool _setbool)
	{
		if (m_bIsOn)
			m_bIsOn = false;
		else
			m_bIsOn = true;
	}
	bool GetIsOn() { return m_bIsOn; }
	void OnCollisionEnter(CCollider* _pOther) /*override*/;		///override�� �ְ� ����� ���� ����?, �����Ƕ�°͸� �˰� ����
};

