//��������� �� �� ������Ʈ
//�ؽ��� �޾Ƽ� ���� �־��ٰ���, �⺻�� �ؽ��� �޾Ƽ� ��������
#include "pch.h"
#include "EmptyObject1.h"

//�����Լ� ���������
//#include <random>


// �ִϸ��̼� ����� ������ (CLever.cpp ����)
// #include "Animator.h"
// #include "Animation.h"

//�浹����
#include "CCollider.h"




//�⺻ ������
///������Ʈ �߰��� ��
//�ؽ��� �޴´�
//�ؽ����� �ʱ���´� �����ڿ��� �����Ѵ�
EmptyObject1::EmptyObject1()
	:m_bIsOn(false)		//������Ʈ ��������
	, m_bIsPast(false)	//�������
	, m_EmptyObjCurrentState(EMPTYOBJECT_STATE::DEFAULT1)
	, m_iIndex(0)

	,LeverOnOff(false)	//�����ؼ� �̸� �״�ν��. �ٸ� �浹�� ����� ������ Ŭ���� �����ڿ��� �ʱ�ȭ�ؾ��ϴ°� ǥ���� ���̴�, ������ ������Ͽ�, �ʱ�ȭ�� cpp����

{
	//�ִϸ��̼Ǿ��� �ʴ� �ؽ���
	//�ҷ��� �ؽ��Ĵ� �����ڿ� �����Ѵ�, ������ ������Ͽ� �ߴ�
	m_pTexture[0] = TextureManager::GetInstance()->LoadTexture(L"EmptyObject1", L"texture\\Green.bmp");	//1��
	m_pTexture[1] = TextureManager::GetInstance()->LoadTexture(L"EmptyObject2", L"texture\\OR.bmp");	//2��
	m_pTexture[2] = TextureManager::GetInstance()->LoadTexture(L"EmptyObject3", L"texture\\Red.bmp");	//3��
	m_pTexture[3] = TextureManager::GetInstance()->LoadTexture(L"EmptyObject4", L"texture\\wh.bmp");	//4��

	///�����ڿ��� rand�Լ��� ���, rand�Լ��� ���Ǵ� <random>�� �ִ�
	//m_iIndex = rand() % 4;	//�迭�� ũ�� 4�� ��Ҵ�

	///------------------------------------------------------------
	
	
// 	
// 	//�ִϸ��̼����� �� �ؽ���(�⺻: �÷��̾�)
// 	Texture* m_pTextureAnimation = TextureManager::GetInstance()->LoadTexture(L"DEFAULT", L"texture\\player_IDLE_Right.bmp");
// 
// 	//�ִϸ��̼����� ����� ������(������Ʈ ������ ���ÿ� �ִϸ��̼��� ���۵Ǿ���ϹǷ� �����ڿ� ��������)
// 	//�ִϸ��̼� �����ϱ�
// 	CreateAnimator();
// 	//DEFAULT���� �ִϸ��̼�
// 	// ��ü 68x142 / ������������ϴ� ĳ���� 60x136	(�⺻: �÷��̾�)
// 	GetAnimator()->CreateAnimation(L"DEFAULT",m_pTextureAnimation, Vector2(0.f, 0.f), Vector2(68.0f, 142.f), Vector2(68.f, 0.f), 0.3f, 2);
// 	if (m_bIsPast)
// 	{
// 		GetAnimator()->Play(L"DEFAULT");
// 	else
// 	{
// 	}
// 		GetAnimator()->Play(L"Prev_Lever_Off");
// 	}
}


//������Ʈ�� ������ �־���Ѵ�
void EmptyObject1::Update()
{

}


//�ִϸ��̼� ����� �������� render
void EmptyObject1::Render(HDC _dc)
{
	Vector2 vPos = GetPos();
	Vector2 vScale = GetScale();
	int w = m_pTexture[m_iIndex]->Width();
	int h = m_pTexture[m_iIndex]->Height();
	int x = 0;
	int y = 0;
	TransparentBlt(_dc
		, (int)(vPos.x + vScale.x / 4)
		, (int)(vPos.y + vScale.y / 4)
		, (int)(vScale.x / 2)
		, (int)(vScale.y / 2)
		, m_pTexture[m_iIndex]->GetDC()
		, x
		, y
		, w
		, h
		, RGB(255, 0, 255));
}


// �浹�Լ� ����� CLever.cpp �����ߴµ�, ������ �ִµ� �÷��̾ �ͼ� �߻��ϴ� �浹�̴�. (�÷��̾ �̵��ؼ� �߻��ϴ� �浹�� �����ؾ���)
// void EmptyObject1::OnCollisionEnter(CCollider* _pOther)
// {
// 	if (_pOther->GetObj()->GetName() == L"Whip_Player")
// 	{
// 		LeverTriggerOn(this);	///this���� ������ ����
// 
// 		if (LeverOnOff)				//LeverOnOff(false�����ؼ� �̸� �״�ν��. �ٸ� �浹�� ����� ������ Ŭ���� �����ڿ��� �ʱ�ȭ�ؾ��ϴ°� ǥ���� ���̴�
// 			LeverOnOff = false;
// 		else
// 			LeverOnOff = true;
// 	}
// }



EmptyObject1::~EmptyObject1()
{
}
