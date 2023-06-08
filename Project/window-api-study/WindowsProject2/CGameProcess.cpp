#include "pch.h"
#include "CGameProcess.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyManager.h"
#include "CScene.h"
#include "CSceneManager.h"
#include "CPathManager.h"
#include "CCollisionManager.h"
#include "CEventMgr.h"
#include "CUIMgr.h"
#include "SoundManager.h"
//#include "CResMgr.h"
#include "TextureManager.h"

CGameProcess::CGameProcess()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, m_memDC(0)
	, m_arrBrush{}
	, m_arrPen{}
{

}

CGameProcess::~CGameProcess()
{
	// DC ��ȯ
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);

	// �� ����
	for (int i = 0; i < (UINT)PEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}
}

void CGameProcess::CreateBrushPen()
{
	// hollow brush
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_arrBrush[(UINT)BRUSH_TYPE::RED] = CreateSolidBrush(RGB(255,0,0));

	// red Pen
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	m_arrPen[(UINT)PEN_TYPE::PUPLE] = CreatePen(PS_SOLID, 2, RGB(148, 0, 211));
	m_arrPen[(UINT)PEN_TYPE::YELLOW] = CreatePen(PS_SOLID, 2, RGB(255, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::WHITE] = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	m_arrPen[(UINT)PEN_TYPE::ORENGE] = CreatePen(PS_SOLID, 2, RGB(255, 165, 0));
}


// init ����
// 1. ������ �ڵ�� ������ ũ�⸦ ������ x, y��ǥ�� ���� POINT�� �Ű������� �޾ƿͼ� �����Ѵ�. 
// ( �̶� CCore�� Mgr Ŭ�������� �̹� �̱��� ���Ͽ��� static���� �����߱� ������,
//  ������ ������ �޸𸮰� ���� �ִ� ���¿��� ��ü�� ������ �ʿ䰡 ���� ���� ���� ������ ::GetInstance()�� �ش� ��ü�� �ּҸ� ������ �� �ִ�. )
// 2. �ػ󵵿� �°� ������ ũ�� ����
// 3. ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����
// 4. ��Ʈ���� SelectObject�� �����Ѵ�
// 5. Manager �ʱ�ȭ
// 5-1. CPathMgr : ���ҽ� ������ ������ ��θ� wstring���� ����
// 5-2. CTimeMgr : �ð� ����
// 5-3. CKeyMgr : �Է� Ű ����
// 5-4. CSceneMgr : ������ ���� ����� ���� �� ����
// 5-5 CCollisionMgr : ����μ��� ����
int CGameProcess::Initialize(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

// 	// �ػ󵵿� �°� ������ ũ�� ����
 	//RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
 	//AdjustWindowRect(&rt, WS_BORDER , true);										// ������ â ����
 	//SetWindowPos(m_hWnd, nullptr,100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);		//

	// �츮 ������ â�� hdc�� ��������
	m_hDC = GetDC(m_hWnd);

	// ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);													// m_hDC�� ȣȯ�Ǵ� DC ����

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);								// m_memDC�� m_hBit�� ������Ʈ�� ���� �Ǿ���
	DeleteObject(hOldBit);

	// ���� ��� �� �� �� �귯�� ����
	// CreateBrushPen();

	// 
	SoundManager::GetInstance()->Init();
	SoundManager::GetInstance()->Loading();
	// Manager �ʱ�ȭ
	CPathManager::GetInstance()->Initialize();
	CTimeManager::GetInstance()->Initialize();
	CKeyManager::GetInstance()->Initialize();
	//CResMgr::GetInstance()->m_hDC = m_hDC;
	TextureManager::GetInstance()->m_hDC = m_hDC;
	// ���� �߰��� ��� 
	// CSceneMgr�� Init�Լ��� �� �߰�!
	// define.h���� SCENE_TYPE �߰�!
	// CSene Ŭ������ �ڽ� Ŭ������ ���� �Ŀ� Enter()�Լ����� �ʿ� ��ġ�� ������Ʈ ����!
	// 
	// ������Ʈ�� �߰��� ���
	// ���࿡ ������Ʈ�� ���� ���� ��쿡 CObjectŬ������ �ڽ� Ŭ������ �����ϰ�
	// define.h���� GROUP_TYPE �߰�!
	// ������Ʈ �����ڿ��� ������Ʈ�� Collider�� Animation�� �ٿ��� �� �ֽ��ϴ�
	// ���� Collider�� �߰��� ��쿡 OnCollision�Լ�(3��)���� ����� �� �ֽ��ϴ�
	CSceneManager::GetInstance()->Initialize(m_hWnd, m_memDC, m_ptResolution);
	CCollisionManager::GetInstance()->Initialize();

	return S_OK;
}


// update ����
// 1. TimeMgr, KeyMgr
// 2. Scene update -> CurScene(���� ��)�� Object*->update
// 3. Scene fianlupdate -> CurScene(���� ��)�� Object*->finalupdate ����
// 4. Collision -> �ݸ��� �浹 üũ �� -> (�浹���� ���) Object*->OnCollision �Լ� ����
// 
// render ����
// 5. ȭ�� Ŭ����
// 6. Scene render -> CurScene(���� ��)�� Object*->render ����
// 7. BitBlt���� ���� ������ �ν��Ͻ��� HDC�� �׷��ش�
// 
// Event
// 8. EventMgr update -> Object���� �����ϰų�, �����ϰų�, CurScene(���� ��)�� ������ ���
void CGameProcess::Progress()
{
	// ==============
	// Manager Update
	// ==============
	CTimeManager::GetInstance()->Update();
	CKeyManager::GetInstance()->Update();

	// =============
	// SCene Update
	// =============
	CSceneManager::GetInstance()->Update();

	// �浹üũ
	CCollisionManager::GetInstance()->Update();

	// UI �̺�Ʈ üũ
	CUIMgr::GetInstance()->Update();

	// =========
	// Rendering
	// =========
	// ȭ�� Clear
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneManager::GetInstance()->Render(m_memDC);

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y
		, m_memDC, 0, 0, SRCCOPY);

	// =============
	// �̺�Ʈ ����ó��
	// =============
	CEventMgr::GetInstance()->Update();

}