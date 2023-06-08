///poison Ÿ�� 3�� �����
///3�� �� �ϳ��� �������� ? 
///CThron �� ����ϰ� ������
#include "pch.h"

#include "CPoison.h"
#include "CPoisonTile.h"
#include "TextureManager.h"
#include <random>

///update������ ������, 
void CPoisonTile::Update()
{
}

///�ִϸ��̼� ������ �ʴ´�. �׷��� render�Ѵ�
void CPoisonTile::Render(HDC _dc)
{
	Vector2	vPos = GetPos();
	Vector2 vScale = GetScale();
	int w = pPoisonTexture[m_iIndex]->Width();
	int h = pPoisonTexture[m_iIndex]->Height();
	int x = 0;
	int y = 0;
	TransparentBlt(_dc
		, (int)(vPos.x + vScale.x / 4)
		, (int)(vPos.y + vScale.y / 4)
		, (int)(vScale.x / 2)
		, (int)(vScale.y / 2)
		, pPoisonTexture[m_iIndex]->GetDC()		///�����ڿ� �ִ� rand�Լ��� ���� m_iIndex�� 0,1,2�� �������� ��������
		, x
		, y
		, w
		, h
		, RGB(255, 0, 255));
}

///������
CPoisonTile::CPoisonTile()
	:m_bIsOn(false)
	,m_bIsPast(false)

{
	///���Ǹ� �Ѵ�. ������ ������Ͽ� �ߴ�. 
	///���࿡ �߰�ȣ �ȿ� �����ߴٸ�, ���⼭�� �� �� �ִµ�, ������ ������Ͽ� �߱� ������ �߰�ȣ �κ� ������ �Ⱦ�����
	pPoisonTexture[0] = TextureManager::GetInstance()->LoadTexture(L"Poision1", L"texture\\poisiontile1.bmp");	//1��

	pPoisonTexture[1] = TextureManager::GetInstance()->LoadTexture(L"Poision2", L"texture\\poisiontile2.bmp");	//2��

	pPoisonTexture[2] = TextureManager::GetInstance()->LoadTexture(L"Poision3", L"texture\\poisiontile3.bmp");	//3��

	///�����ڿ��� rand�Լ��� ���, rand�Լ��� ���Ǵ� <random>�� �ִ�
	m_iIndex = rand() % 3;

}


//�Ҹ���
CPoisonTile::~CPoisonTile()
{
}
