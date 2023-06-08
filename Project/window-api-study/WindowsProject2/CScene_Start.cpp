#include "pch.h"
#include "CScene_Start.h"

#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "Texture.h"
#include "CPathManager.h"
#include "CCollisionManager.h"

#include "CGameProcess.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CBoard.h"
#include "CEventMgr.h"

#include "SoundManager.h"
// �ΰ��� ���� ������Ʈ
#include "CTrap.h"
#include "CTrigger.h"
#include "CTrapArrow.h"
#include "CLever.h"
// IU �ΰ��� ������Ʈ 
#include "CMiniMap.h"
#include "CStone.h"
#include "CPoison.h"
#include "CPoisonCount.h"
#include "CClock.h"
#include "CClockConut.h"
#include "CPreferences.h"
#include "StageRelics.h"
#include "CDoor.h"
// Preferences�� �г� ������Ʈ
#include "CPanelUI.h"
#include "CBtnUI.h"
#include "CContinue.h"
#include "CReStart.h"
#include "CMainMenu.h"
// �ΰ��� ���� ������Ʈ
#include "CSpider.h"
#include "CGuardian.h"
#include "CTimeGuardian.h"

CScene_Start::CScene_Start(HWND hWnd, HDC hDC, POINT screenRes) : CScene(hWnd, hDC, screenRes)
{
	m_eNextScene = SCENE_TYPE::STAGE_1_1;
}

CScene_Start::~CScene_Start()
{
}

// ������Ʈ ����
void CScene_Start::Enter(bool _isPast)
{
	SoundManager::GetInstance()->Play(SOUND::BACKGROUND_INGAME, SOUND_CHANNAL::BGM);

	m_bIsPast = false;
	CPlayer* pObj = new CPlayer;
	pObj->SetName(L"Player");
	pObj->SetScale(Vector2(100.f, 100.f));
	pObj->SetBoardPos(POINT{ 1 ,5 });
	AddObject(pObj, GROUP_TYPE::PLAYER);

	StageRelics* pStageRelics = new StageRelics;
	pStageRelics->SetName(L"StageRelics");
	pStageRelics->SetPos(Vector2{ (BOARD_TILE / 2) + (BOARD_TILE * (BOARD_PENDING + 5)), (BOARD_TILE / 2) + (BOARD_TILE * (BOARD_PENDING + 1)) });
	pStageRelics->SetScale(Vector2(100.f, 100.f));
	pStageRelics->SetBoardPos(POINT{ 0 ,0 });
	AddObject(pStageRelics, GROUP_TYPE::RELICS);

	LoadTile(L"Tile\\S0\\Stage 0.tile", !m_bIsPast);
	LoadTile(L"Tile\\S0\\Stage 0.tile", m_bIsPast);

	CCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::TILE);
}

bool CScene_Start::Exit()
{
	// ��� ������Ʈ ����
	DeleteAll();
	SoundManager::GetInstance()->Stop(EFFECT);
	// �浹 ��Ʈ���� üũ ����
	CCollisionManager::GetInstance()->Reset();
	m_iLoadedTileCount = 0;
	return m_bIsPast;
}
