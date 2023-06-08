#include "pch.h"
#include "CStage2_3.h"

CStage2_3::CStage2_3(HWND hWnd, HDC hDC, POINT screenRes) : CScene(hWnd, hDC, screenRes)
{
	m_eNextScene = SCENE_TYPE::STAGE_2_4;
}

CStage2_3::~CStage2_3()
{

}

void CStage2_3::Enter(bool _isPast)
{
	// �÷��̾� �߰�
	m_bIsPast = false;
	CPlayer* pObj = new CPlayer;
	pObj->SetName(L"Player");
	pObj->SetScale(Vector2(100.f, 100.f));
	pObj->SetBoardPos(POINT{ 1 ,3 });
	AddObject(pObj, GROUP_TYPE::PLAYER);

	LoadTile(L"Tile\\S2\\Stage 2 Room 3 Present.tile", !m_bIsPast);
	LoadTile(L"Tile\\S2\\Stage 2 Room 3 Past.tile", m_bIsPast);

	SetTrap(TILE_TYPE::FIRE, 0, 16, true);
	SetTrap(TILE_TYPE::TRIGGER, 0, 16, true);

	SetDefaultCollision();
	SetUI(m_bIsPast);
}

bool CStage2_3::Exit()
{
	// ��� ������Ʈ ����	
	DeleteAll();

	// �浹 ��Ʈ���� üũ ����
	CCollisionManager::GetInstance()->Reset();
	m_iLoadedTileCount = 0;
	return m_bIsPast;
}
