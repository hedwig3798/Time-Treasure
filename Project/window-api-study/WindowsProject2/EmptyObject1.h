#pragma once
#include "pch.h"
#include "CObject.h"
#include "Texture.h"
#include "TextureManager.h"


class EmptyObject1 :public CObject
{
public:
	
	//�׸����� �� �ؽ���
	Texture* m_pTexture[4];
	int m_iIndex;
// 	//�ִϸ��̼����� �� �ؽ���
// 	Texture* m_pTextureAnimation;
	
	bool LeverOnOff; //�����ؼ� �̸� �״�ν��. �ٸ� �浹�� ����� ������ Ŭ���� �����ڿ��� �ʱ�ȭ�ؾ��ϴ°� ǥ���� ���̴�, ������ ������Ͽ�, �ʱ�ȭ�� cpp����



public:
	bool m_bIsOn;
	bool m_bIsPast;


public:
	//�� ������Ʈ�� ����
	EMPTYOBJECT_STATE m_EmptyObjCurrentState;

	//���º�ȭ ������ �߰��ؾߵǳ�??

public:
	virtual void Update();
	virtual void Render(HDC _dc);
	//�ʼ�
	virtual EmptyObject1* Clone() { return new EmptyObject1(*this); }
	//�浹�� �����ȴٸ�
	virtual void OnCollisionEnter(CCollider* _pOther);

public:
	EmptyObject1();
	~EmptyObject1();

};

