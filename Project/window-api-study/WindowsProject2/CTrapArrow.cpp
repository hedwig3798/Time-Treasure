///arrow�� ȭ�� �߻���ġ��
#include "pch.h"
#include "CTrapArrow.h"

//�⺻ �����ڿ��� �ʱ�ȭ
CTrapArrow::CTrapArrow()	

{
	
}

void CTrapArrow::Update()
{
}

void CTrapArrow::Render(HDC _dc)
{
	


}

void CTrapArrow::CreateMissile()
{
	Vector2 vMissilePos = GetPos();
	CMissile* pMissile = new CMissile;
	pMissile->SetName(L"Missile_Player");
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vector2(25.f, 25.f));
	pMissile->SetDir(GetDir());
	CreateObject(pMissile, GROUP_TYPE::PROJ_MONSTER);
}


CTrapArrow::~CTrapArrow()
{
}
