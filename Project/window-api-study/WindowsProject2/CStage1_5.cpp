#include "pch.h"
#include "CStage1_5.h"

CStage1_5::CStage1_5(HWND hWnd, HDC hDC, POINT screenRes) : CScene(hWnd, hDC, screenRes)
{
	m_eNextScene = SCENE_TYPE::STAGE_1_6;
}

CStage1_5::~CStage1_5()
{

}

void CStage1_5::Enter(bool _isPast)
{
	// �÷��̾� �߰�
	m_bIsPast = true;
	CPlayer* pObj = new CPlayer;
	pObj->SetName(L"Player");
	pObj->SetScale(Vector2(100.f, 100.f));
	pObj->SetBoardPos(POINT{ 4 ,5 });
	AddObject(pObj, GROUP_TYPE::PLAYER);

	SetMonster(MONSTER_TYPE::SPIDER, 7, 4, !m_bIsPast);
	SetMonster(MONSTER_TYPE::SPIDER, 10, 4, !m_bIsPast);

	SetObject(GROUP_TYPE::LEVER, 10, 5, 15, true);
	SetObject(GROUP_TYPE::LEVER, 10, 5, 15, false);

	LoadTile(L"Tile\\S1\\Stage 1 Room 5 Present.tile", !m_bIsPast);
	LoadTile(L"Tile\\S1\\Stage 1 Room 5 Past.tile", m_bIsPast);

	SetTrap(TILE_TYPE::FIRE, 0, 6, true);
	SetTrap(TILE_TYPE::TRIGGER, 0, 16, true);

	SetDefaultCollision();
	SetUI(m_bIsPast);
}

bool CStage1_5::Exit()
{
	// ��� ������Ʈ ����
	DeleteAll();

	// �浹 ��Ʈ���� üũ ����
	CCollisionManager::GetInstance()->Reset();
	m_iLoadedTileCount = 0;
	return m_bIsPast;
}
