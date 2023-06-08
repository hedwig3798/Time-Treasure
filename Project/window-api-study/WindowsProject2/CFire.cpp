///fire�� 4���⿡�� �����ϱ� �ִϸ��̼� 4���� �ʿ��ϴ�(�÷��̾� �������� fire trap�� �ִ� ������ up, down, left, right ��������
///ũ��� �ִϸ��̼� ���� �� �ٲ� �� �����ϱ�, 4���� �ִϸ��̼� �����
#include "pch.h"
#include "CFire.h"

#include "CTimeMgr.h"
#include "CCollider.h"
#include "SelectGDI.h"

CFire::CFire(OBJECT_DIR _dir)				// �߰�
	: m_fTheta((float)PI / 2.f)
	, m_dir(_dir)							// �߰�
	, m_fLifeTiem(5.5f)
	, TriggerOn(true)
{
	CreateCollider();
	GetCollider()->SetScale(Vector2(0.f, 0.f));


	switch (m_dir)							// �߰�
	{
	case OBJECT_DIR::UP:
	{
		//down: ���� �÷��̾��� �Ʒ����� ���´�
		Texture* pFireTexture4 = TextureManager::GetInstance()->LoadTexture(L"fire_down", L"texture\\fire_down.bmp");	//down���� ������ ��
		CreateAnimator();
		GetAnimator()->CreateAnimation(L"FIRE_1_DOWN_START", pFireTexture4, Vector2(0.f, 0.f), Vector2(120.0f, 240.f), Vector2(120.0f, 0.f), 0.2f, 2);
		GetAnimator()->CreateAnimation(L"FIRE_1_DOWN_LOOP", pFireTexture4, Vector2(120.0f * 2, 240.f + 1), Vector2(120.0f, 240.f), Vector2(120.0f, 0.f), 0.2f, 4);
		GetAnimator()->Play(L"FIRE_1_DOWN_LOOP", true);
	}
	break;
	case OBJECT_DIR::LEFT:
	{
		////right: ���� �÷��̾��� �����ʿ��� ���´�
		Texture* pFireTexture3 = TextureManager::GetInstance()->LoadTexture(L"fire_right", L"texture\\fire_right.bmp");	//right���� ������ ��
		CreateAnimator();
		GetAnimator()->CreateAnimation(L"FIRE_1_RIGHT_START", pFireTexture3, Vector2(0.f, 0.f), Vector2(240.0f, 120.f), Vector2(0.f, 120.f), 0.2f, 2);
		GetAnimator()->CreateAnimation(L"FIRE_1_RIGHT_LOOP", pFireTexture3, Vector2(240.f + 1.f, 120.f * 2), Vector2(240.0f - 1.f, 120.f), Vector2(0.f, 120.f), 0.2f, 4);
		GetAnimator()->Play(L"FIRE_1_RIGHT_LOOP", true);
	}
	break;
	case OBJECT_DIR::RIGHT:
	{
		//left: ���� �÷��̾��� ���ʿ��� ���´�
		Texture* pFireTexture2 = TextureManager::GetInstance()->LoadTexture(L"fire_left", L"texture\\fire_left.bmp");	//left���� ������ ��
		CreateAnimator();
		GetAnimator()->CreateAnimation(L"FIRE_1_LEFT_START", pFireTexture2, Vector2(0.f, 0.f), Vector2(240.0f, 120.f), Vector2(0.f, 120.f), 0.2f, 2);
		GetAnimator()->CreateAnimation(L"FIRE_1_LEFT_LOOP", pFireTexture2, Vector2(0.0f, 120.f * 2), Vector2(240.0f, 120.f), Vector2(0.f, 120.f), 0.2f, 4);
		GetAnimator()->Play(L"FIRE_1_LEFT_LOOP", true);
	}
	break;
	case OBJECT_DIR::DOWN:
	{
		//up: ���� �÷��̾��� ������ ���´�
		Texture* pFireTexture1 = TextureManager::GetInstance()->LoadTexture(L"fire_up", L"texture\\fire_up.bmp");	//up���� ������ ��
		CreateAnimator();
		GetAnimator()->CreateAnimation(L"FIRE_1_UP_START", pFireTexture1, Vector2(0.f, 0.f), Vector2(120.0f, 240.f), Vector2(120.0f, 0.f), 0.2f, 2);
		GetAnimator()->CreateAnimation(L"FIRE_1_UP_LOOP", pFireTexture1, Vector2(120.0f * 2, 0.f), Vector2(120.0f, 240.f), Vector2(120.0f, 0.f), 0.2f, 4);
		GetAnimator()->Play(L"FIRE_1_UP_LOOP", true);
	}
	break;
	}
	///�����ڿ��� Update, Render�����ʴ´�. �����ڿ����� 4���� �� �ϳ��� �����ϰ�, ������ �ۿ��� Update, Render �Ѵ�
}

CFire::~CFire()
{
}

void CFire::Update()
{
	Vector2 vScale = GetScale();

	GetCollider()->SetScale(vScale);
}

void CFire::Render(HDC _dc)
{

}

void CFire::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Monster")
	{
		DeleteObject(this);
	}
}
