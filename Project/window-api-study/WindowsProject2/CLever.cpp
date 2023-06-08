#include "pch.h"
#include "CLever.h"
#include "CCollider.h"

#include "TextureManager.h"
#include "CKeyManager.h"
#include "Texture.h"
#include "Animator.h"
#include "Animation.h"

#include "CSceneManager.h"
#include "CScene.h"

CLever::CLever(bool _isPast)
	:TriggerNumber(0)
	, LeverOnOff(false)
	, IsCurrent(true)
	, m_bIsPast(_isPast)
{
	CreateCollider();
	GetCollider()->SetScale(Vector2(50.f, 50.f));
	GetCollider()->SetOffsetPos(Vector2(0.f, 0.f));

	Texture* pTexture = TextureManager::GetInstance()->LoadTexture(L"Lever", L"texture\\rever.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Prev_Lever_On", pTexture, Vector2(0.f, 0.f), Vector2(64.f, 64.f), Vector2(64.f, 0.f), 0.3f, 1);
	GetAnimator()->CreateAnimation(L"Prev_Lever_Off", pTexture, Vector2(128.f, 0.f), Vector2(64.f, 64.f), Vector2(-64.f, 0.f), 0.3f, 1);

	GetAnimator()->CreateAnimation(L"Current_Lever_On", pTexture, Vector2(0.f, 64.f), Vector2(64.f, 64.f), Vector2(64.f, 0.f), 0.3f, 1);
	GetAnimator()->CreateAnimation(L"Current_Lever_Off", pTexture, Vector2(128.f, 64.f), Vector2(64.f, 64.f), Vector2(-64.f, 0.f), 0.3f, 1);

	if (m_bIsPast)
	{
		GetAnimator()->Play(L"Current_Lever_Off", true);
	}
	else
	{
		GetAnimator()->Play(L"Prev_Lever_Off", true);
	}
}

CLever::~CLever()
{
}

void CLever::Update()
{
}

void CLever::Render(HDC _dc)
{
	if (!m_bIsPast == true && LeverOnOff == false)
	{
		GetAnimator()->Play(L"Current_Lever_Off", true);
	}
	else if (!m_bIsPast == true && LeverOnOff == true)
	{
		GetAnimator()->Play(L"Current_Lever_On", true);
	}
	else if (!m_bIsPast == false && LeverOnOff == false)
	{
		GetAnimator()->Play(L"Prev_Lever_Off", true);
	}
	else if (!m_bIsPast == false && LeverOnOff == true)
	{
		GetAnimator()->Play(L"Prev_Lever_On", true);
	}
}

// �ð��� �ٲ� ������ ���� �ִϸ��̼� ����
void CLever::TurnTime()
{

}

// �÷��̾ ������ �۵� ��ų ��쿡 �ִϸ��̼� �� Trigger �̺�Ʈ ȣ��
void CLever::OnCollisionEnter(CCollider* _pOther)
{
	if (_pOther->GetObj()->GetName() == L"Whip_Player")
	{
		LeverTriggerOn(this);		///�и� func.h�� ���� ������Ͽ� ��õ����ʾҴµ�.. ��°�� ����??? -> pch.h�� �ֱ� ������ �����ϴ�

		if (LeverOnOff)
			LeverOnOff = false;
		else
			LeverOnOff = true;
	}
}