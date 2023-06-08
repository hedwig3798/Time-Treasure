#pragma once
#include "CCollisionManager.h"
#include "CPlayer.h"
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
// ���漱��
class CObject;

/// <summary>
/// Scene���� ��� �θ� �Ǵ� �ֻ��� Ŭ����
/// IScene�� ���� �̸����ٵ�..
/// 
/// 2023.05.22
/// </summary>

enum class MONSTER_TYPE
{
	SPIDER,
	GUARDIAN,
	TIMEGUARDIAN
};

class CScene
{
public:
	///�ƽŰ� ������ SceneŬ������ ����� �޾ұ� ������, ���� �Լ� ��ӹ޾Ƽ� ������ ������ ����, ���� ���� �����
	CScene(HWND hWnd, HDC hDC, POINT screenRes);
	virtual ~CScene();
	SCENE_TYPE m_eNextScene;
	SCENE_TYPE m_eNowScene;
public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	UINT GetTileX() { return m_iTileX; }
	UINT GetTileY() { return m_iTileY; }
	UINT GetTileTypeNumber() { return m_iTileTypeNumber; }

public:
	virtual void Update();
	virtual void Finalupdate();
	virtual void Render(HDC _dc);
	void TriggerEvent(int _TileTriggerNumber, GROUP_TYPE _ObjectType);
	void DeveloperMode(int ModeType);

public:
	// ���� ���Ե� ���� �Լ��� �ڽ� Ŭ�������� �����ؾߵ� �Լ��� ���� �˸��� �뵵�̴�
	virtual void Enter(bool _isPast) = 0;		// �ش� Scene�� ���� �� ȣ��
	virtual bool Exit() = 0;		// �ش� Scene�� Ż�� �� ȣ��

public:
	// �����θ� ����� ����� �ش� �Լ��� �ζ��� ó���Ǿ� �Լ� ȣ�� ������ ������ �ʾ� ���ɿ� ���̰� ���� ����.
	void AddObject(CObject* _pObj, GROUP_TYPE _eType) { m_arrObj[(UINT)_eType].push_back(_pObj); };

	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }
	int m_iLoadedTileCount;

	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();

	void CreateTile(UINT _iXCount, UINT _iYCount, UINT _TileFileNumber, bool _activate);
	void LoadTile(const wstring& _strRelativePath, bool _activate);

	vector<CObject*>& GetUIGroup() { return m_arrObj[(UINT)GROUP_TYPE::UI]; }// 05�� 21�� ������ �߰�

	void SetMonster(MONSTER_TYPE _eMonsterType, int _ptx, int _pty, bool activate, int _range = 0, bool horizen = false, bool _ismove = true);
	void SetObject(GROUP_TYPE _eObjectType, int _ptx, int _pty, int _TriggerNumber, bool _activate);
	void SetTrap(TILE_TYPE _eTileType, int _StartCount, int _EndCount, bool TrapOn);

	void SetDefaultCollision();

	void SetUI(bool _isPast);

public:
	vector<CObject*>	m_arrObj[(UINT)GROUP_TYPE::END];	// ������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	HWND m_hWnd;
	HDC m_hDC;
	POINT m_screenRes;
	bool m_bIsPast;
	bool CollisionVisible;

private:
	wstring				m_strName;			// Scene �̸�

	UINT				m_iTileX;			// Ÿ�� ���� ����
	UINT				m_iTileY;			// Ÿ�� ���� ����
	UINT				m_iTileTypeNumber;	// Ÿ�� Ÿ��

};