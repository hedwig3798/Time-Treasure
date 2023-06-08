#include "pch.h"
#include "CStage1_2.h"

CStage1_2::CStage1_2(HWND hWnd, HDC hDC, POINT screenRes) : CScene(hWnd, hDC, screenRes)
{
	m_eNextScene = SCENE_TYPE::STAGE_1_3;
}

CStage1_2::~CStage1_2()
{

}

void CStage1_2::Enter(bool _isPast)
{
	// �÷��̾� �߰�
	m_bIsPast = false;
	CPlayer* pObj = new CPlayer;
	pObj->SetName(L"Player");
	pObj->SetScale(Vector2(100.f, 100.f));
	pObj->SetBoardPos(POINT{ 5 ,5 });
	AddObject(pObj, GROUP_TYPE::PLAYER);

	LoadTile(L"Tile\\S1\\Stage1 Room 2 Present.tile", !m_bIsPast);
	LoadTile(L"Tile\\S1\\Stage1 Room 2 Past.tile", m_bIsPast);

	SetObject(GROUP_TYPE::LEVER, 9, 5, 15, false);
	SetTrap(TILE_TYPE::FIRE, 0, 6, true);
	SetTrap(TILE_TYPE::TRIGGER, 0, 16, true);

	SetDefaultCollision();
	SetUI(m_bIsPast);
}

bool CStage1_2::Exit()
{
	// ��� ������Ʈ ����
	DeleteAll();

	// �浹 ��Ʈ���� üũ ����
	CCollisionManager::GetInstance()->Reset();
	m_iLoadedTileCount = 0;
	return m_bIsPast;
}
