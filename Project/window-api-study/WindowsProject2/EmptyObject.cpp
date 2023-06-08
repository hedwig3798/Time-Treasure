//��������� �� �� ������Ʈ
//�ؽ��� �޾Ƽ� ���� �־��ٰ���, �⺻�� �ؽ��� �޾Ƽ� ��������
#include "pch.h"
#include "EmptyObject.h"

//�����Լ� ���������
//#include <random>

// �ִϸ��̼� ����� ������
// #include "Animator.h"
// #include "Animation.h"


//�⺻ ������
///������Ʈ �߰��� ��
//�ؽ��� �޴´�
//�ؽ����� �ʱ���´� �����ڿ��� �����Ѵ�
EmptyObject::EmptyObject()
{
	//�ִϸ��̼Ǿ��� �ʴ� �ؽ���
	//�ҷ��� �ؽ��Ĵ� �����ڿ� �����Ѵ�, ������ ������Ͽ� �ߴ�
	m_pTexture = TextureManager::GetInstance()->LoadTexture(L"EmptyObject1", L"texture\\decodrain.bmp");	//1��

	///�����ڿ��� rand�Լ��� ���, rand�Լ��� ���Ǵ� <random>�� �ִ�

	m_iIndex = rand() % 3;

	///------------------------------------------------------------
}


//������Ʈ�� ������ �־���Ѵ�
void EmptyObject::Update()
{

}


//�ִϸ��̼� ����� �������� render
void EmptyObject::Render(HDC _dc)
{
	Vector2 vPos = GetPos();
	Vector2 vScale = GetScale();
	int w = m_pTexture->Width();
	int h = m_pTexture->Height();
	int x = 0;
	int y = 0;
	TransparentBlt(_dc
		, (int)(vPos.x + vScale.x / 4)
		, (int)(vPos.y + vScale.y / 4)
		, (int)(vScale.x / 2)
		, (int)(vScale.y / 2)
		, m_pTexture->GetDC()
		, x
		, y
		, w
		, h
		, RGB(255, 0, 255));
}





EmptyObject::~EmptyObject()
{
}
