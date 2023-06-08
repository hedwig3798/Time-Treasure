//��������� ���� Drain
#include "pch.h"
#include "CDrain.h"

//�����Լ� ���������
#include <random>

// �ִϸ��̼� ����� ������
// #include "Animator.h"
// #include "Animation.h"


//�⺻ ������
///������Ʈ �߰��� ��
//�ؽ��� �޴´�
//�ؽ����� �ʱ���´� �����ڿ��� �����Ѵ�
CDrain::CDrain()
	:m_bIsOn(false)		//������Ʈ ��������
	, m_bIsPast(false)	//�������
	, m_iIndex(0)
{
	//�ִϸ��̼Ǿ��� �ʴ� �ؽ���
	//�ҷ��� �ؽ��Ĵ� �����ڿ� �����Ѵ�, ������ ������Ͽ� �ߴ�
	m_DrainTexture[0] = TextureManager::GetInstance()->LoadTexture(L"EmptyObject1", L"texture\\Green.bmp");	//1��
	m_DrainTexture[1] = TextureManager::GetInstance()->LoadTexture(L"EmptyObject2", L"texture\\OR.bmp");	//2��
	m_DrainTexture[2] = TextureManager::GetInstance()->LoadTexture(L"EmptyObject3", L"texture\\Red.bmp");	//3��

	///�����ڿ��� rand�Լ��� ���, rand�Լ��� ���Ǵ� <random>�� �ִ�
	m_iIndex = rand() % 3;	//�迭�� ũ�� 4�� ��Ҵ�
}


//������Ʈ�� ������ �־���Ѵ�
void CDrain::Update()
{

}


//�ִϸ��̼� ����� �������� render
void CDrain::Render(HDC _dc)
{
	Vector2 vPos = GetPos();
	Vector2 vScale = GetScale();
	int w = m_DrainTexture[m_iIndex]->Width();
	int h = m_DrainTexture[m_iIndex]->Height();
	int x = 0;
	int y = 0;
	TransparentBlt(_dc
		, (int)(vPos.x + vScale.x / 4)
		, (int)(vPos.y + vScale.y / 4)
		, (int)(vScale.x / 2)
		, (int)(vScale.y / 2)
		, m_DrainTexture[m_iIndex]->GetDC()
		, x
		, y
		, w
		, h
		, RGB(255, 0, 255));
}





CDrain::~CDrain()
{
}
