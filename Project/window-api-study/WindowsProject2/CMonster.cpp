#include "pch.h"
#include "CMonster.h"

#include "CTimeMgr.h"
#include "CCollider.h"

#include "Texture.h"	
//#include "CResMgr.h"	
#include "TextureManager.h"

#include "CTile.h"


CMonster::CMonster()
{
	CreateCollider();
	GetCollider()->SetOffsetPos(Vector2(0.f, 0.f));
	GetCollider()->SetScale(Vector2(40.f, 40.f));
}

CMonster::~CMonster()
{
}

void CMonster::Update()
{

}

void CMonster::Render(HDC _dc)
{

}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	

	if (pOtherObj->GetName() == L"Missile_Player")
	{

	}
	if (pOtherObj->GetName() == L"Tile")
	{
		CTile* pTile;
		pTile = dynamic_cast<CTile*>(pOtherObj);
		if (pTile->GetTileType() == (int)TILE_TYPE::WALL)
		{
			// �� Ÿ�� �浹 ó��

		}
		if (pTile->GetTileType() == (int)TILE_TYPE::FATAL)
		{
			// ���� Ÿ�� �浹 ó��

		}
		if (pTile->GetTileType() == (int)TILE_TYPE::TRAP)
		{
			// ���� Ÿ�� �浹 ó��

		}
		if (pTile->GetTileType() == (int)TILE_TYPE::FIRE)
		{
			// ���� Ÿ�� �浹 ó��

		}
		if (pTile->GetTileType() == (int)TILE_TYPE::POSION)
		{
			// ���� Ÿ�� �浹 ó��

		}
		if (pTile->GetTileType() == (int)TILE_TYPE::SCENE_CHANGE)
		{
			// ���� Ÿ�� �浹 ó��

		}
	}
}