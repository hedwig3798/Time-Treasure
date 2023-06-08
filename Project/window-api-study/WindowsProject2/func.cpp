#include "pch.h"
#include "func.h"
#include "CEventMgr.h"


// ������Ʈ ���� �̺�Ʈ�� ����ϴ� �Լ��Դϴ�.
// ������ ������Ʈ�� �ּҿ� ������Ʈ Ÿ���� �Ű� ������ �Է����־�� �մϴ�.
void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eGroup;

	CEventMgr::GetInstance()->AddEvent(evn);
}

// ������Ʈ ���� �̺�Ʈ�� ����ϴ� �Լ��Դϴ�.
// ������ ������Ʈ�� �ּҸ� �Ű� ������ �Է����־�� �մϴ�.
void DeleteObject(CObject* _pObj)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;

	CEventMgr::GetInstance()->AddEvent(evn);
}

// ���� �����ϴ� �̺�Ʈ�� ����ϴ� �Լ��Դϴ�.
// ���� ������ ���� Ÿ���� �Ű� ������ �Է����־�� �մϴ�.
void ChangeScene(SCENE_TYPE _eNext)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::SCENE_CHANGE;
	evn.lParam = (DWORD_PTR)_eNext;

	CEventMgr::GetInstance()->AddEvent(evn);
}

// Ʈ���� �߻��ϴ� �̺�Ʈ�� ����ϴ� �Լ��Դϴ�
void TriggerOn(CTile* _ptile)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::TRIGGER_ON;
	evn.lParam = (DWORD_PTR)_ptile;

	CEventMgr::GetInstance()->AddEvent(evn);
}

// Ʈ���� �߻��ϴ� �̺�Ʈ�� ����ϴ� �Լ��Դϴ�
void LeverTriggerOn(CLever* _ptile)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::LEVERTRIGGER_ON;
	evn.lParam = (DWORD_PTR)_ptile;

	CEventMgr::GetInstance()->AddEvent(evn);
}

