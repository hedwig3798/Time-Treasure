///������ ���� ��ư �����
#include "pch.h"
#include "CFootButton.h"
//��������� �� �� ������Ʈ
//�ؽ��� �޾Ƽ� ���� �־��ٰ���, �⺻�� �ؽ��� �޾Ƽ� ��������


//�⺻ ������
///������Ʈ �߰��� ��
//�ؽ��� �޴´�
//�ؽ����� �ʱ���´� �����ڿ��� �����Ѵ�
CFootButton::CFootButton(bool _isPast)
	:m_bIsPast(_isPast)	//0:����, 1:����
	, m_bIsOn(false)		//0:�ȹ�Ҵ�, 1:��Ҵ� 
	, m_iIndex(0)
{
	//�ִϸ��̼Ǿ��� �ʴ� �ؽ���
	//�ҷ��� �ؽ��Ĵ� �����ڿ� �����Ѵ�, ������ ������Ͽ� �ߴ�
	m_pTexture = TextureManager::GetInstance()->LoadTexture(L"CurrentFootButtonOFF", L"texture\\foothold.bmp");	//1�� (����, �ȹ�)	 (0, 0)
	CreateCollider();
	GetCollider()->SetScale(Vector2{100, 100});
	GetCollider()->SetOffsetPos(Vector2{ 60, 60 });
}


//������Ʈ�� ������ �־���Ѵ�
void CFootButton::Update()
{
}


//�ִϸ��̼� ����� �������� render
void CFootButton::Render(HDC _dc)
{
	Vector2 vPos = GetPos();
	Vector2 vScale = GetScale();
	int w = m_pTexture->Width();
	int h = m_pTexture->Height();

	int x = 0;
	int y = 0;

	//���¿� ���� 4���� �ʿ��ϴ�
	///��, x,y�� �״�� 0�� ���� ���� �ʾƵ� �ȴ�
	if ((m_bIsOn == false) && (m_bIsPast == false))	//(����, �ȹ�)	(0, 0)
	{
	}
	else if ((m_bIsOn == true) && (m_bIsPast == false))	//2�� (����, ��)	(0, 1)
	{
		x = w / 2;
	}
	else if ((m_bIsOn == false) && (m_bIsPast == true))	//3�� (����, �ȹ�) (1, 0) 
	{
		y = h / 2;
	}

	else if ((m_bIsOn == true) && (m_bIsPast == true))	//4�� (����, ��) ( 1, 1)
	{
		x = w / 2;
		y = h / 2;
	}

	TransparentBlt(_dc
		, (int)(vPos.x + vScale.x / 4)
		, (int)(vPos.y + vScale.y / 4)
		, (int)(vScale.x / 2)
		, (int)(vScale.y / 2)
		, m_pTexture->GetDC()
		, x
		, y
		, w/2
		, h/2
		, RGB(255, 0, 255));
}


///�浹üũ�ϰ�, �� �ȿ� if�� �Ű�
///�浹 �ϸ� m_bIsOn==true, �׻��°� �����Ǵٰ�
///�ٽ� ������ m_bIsOn==false, �ǰ� �� ���°� �����ȴ�
///���� ������ �ݺ��ȴ�

//�浹�Լ� ����� CLever.cpp �����ߴµ�, ������ �ִµ� �÷��̾ �ͼ� �߻��ϴ� �浹�̴�. (�÷��̾ �̵��ؼ� �߻��ϴ� �浹�� �����ؾ���)
void CFootButton::OnCollisionEnter(CCollider* _pOther)
{
	///������ ��´ٰ� ����,���簡 �ٲ��� �ʴ´�. ����, ����� CLever���� �����Ǿ���
	if (_pOther->GetObj()->GetName() == L"Player")
	{
		m_bIsOn = true;	//��
	}
}

CFootButton::~CFootButton()
{


}


