#include "pch.h"
#include "CStage1_1.h"

CStage1_1::CStage1_1(HWND hWnd, HDC hDC, POINT screenRes) : CScene(hWnd, hDC, screenRes)
{
	m_eNextScene = SCENE_TYPE::STAGE_1_2;
}

CStage1_1::~CStage1_1()
{

}

void CStage1_1::Enter(bool _isPast)
{
	
	// �÷��̾� �߰�
	m_bIsPast = false;
	CPlayer* pObj = new CPlayer;
	pObj->SetName(L"Player");
	pObj->SetScale(Vector2(100.f, 100.f));
	pObj->SetBoardPos(POINT{ 1 ,5 });
	AddObject(pObj, GROUP_TYPE::PLAYER);

	LoadTile(L"Tile\\S1\\Stage 1 Room 1 Present.tile", !m_bIsPast);
	LoadTile(L"Tile\\S1\\Stage 1 Room 1 Past.tile", m_bIsPast);

	SetTrap(TILE_TYPE::FIRE, 0, 6, true);
	SetTrap(TILE_TYPE::TRIGGER, 0, 6, true);

	SetDefaultCollision();

	SetUI(m_bIsPast);
}

bool CStage1_1::Exit()
{

	// ��� ������Ʈ ����
	DeleteAll();
	// �浹 ��Ʈ���� üũ ����
	CCollisionManager::GetInstance()->Reset();
	m_iLoadedTileCount = 0;
	return m_bIsPast;
}
