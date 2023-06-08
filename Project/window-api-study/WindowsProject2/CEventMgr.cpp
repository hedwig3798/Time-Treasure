#include "pch.h"
#include "CEventMgr.h"

#include "CObject.h"
#include "CScene.h"
#include "CTile.h"
#include "CLever.h"
#include "CSceneManager.h"

CEventMgr::CEventMgr()
{

}

CEventMgr::~CEventMgr()
{

}

void CEventMgr::Update()
{
	// ============================================
	// ���� �����ӿ��� ����ص� Dead Object���� �����Ѵ�
	// ============================================
	for (auto obj : m_vecDead)
	{
		delete obj;
	}
	//for (size_t i = 0; i < m_vecDead.size(); i++)
	//{
	//	delete m_vecDead[i];
	//}
	m_vecDead.clear();

	// ==========
	// Evnet ó��
	// ==========

	for (size_t i = 0; i < m_vecEvent.size(); i++)
	{
		Excute(m_vecEvent[i]);
	}

	m_vecEvent.clear();
}

// func.cpp���� ����� �̺�Ʈ���� ó���˴ϴ�
void CEventMgr::Excute(const tEvent& _eve)
{
	switch (_eve.eEven)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : Object Adress
		// wParam : Group Type
		CObject* pNewObj = (CObject*)_eve.lParam;
		GROUP_TYPE eType = (GROUP_TYPE)_eve.wParam;

		CSceneManager::GetInstance()->GetCurScene()->AddObject(pNewObj, eType);
	}
	break;
	// �ٷ� �����ϸ� ���� �����ӿ��� �ش� ������Ʈ�� ���� �ϰ� �ִ� ��ü���� ���� �޸𸮿� �����ϱ� ������
	// �ش� �̺�Ʈ���� ���� �����ӿ��� ������ �����̶�� �ٸ� ��ü�� �˷��־�� �Ѵ�
	case EVENT_TYPE::DELETE_OBJECT:
	{
		// lParam : Object Adress
		// Object�� Dead ���·� ����
		// �������� ������Ʈ���� ��Ƶд�.
		CObject* pDeadObj = (CObject*)_eve.lParam;
		pDeadObj->SetDead();
		m_vecDead.insert(pDeadObj);
	}
	break;
	case EVENT_TYPE::SCENE_CHANGE:
		// lParam : Next Scene Type
		CSceneManager::GetInstance()->ChangeScene((SCENE_TYPE)_eve.lParam);
		break;
	case EVENT_TYPE::TRIGGER_ON:
	{
		CTile* pTriggerTile = (CTile*)_eve.lParam;
		CSceneManager::GetInstance()->GetCurScene()->TriggerEvent(pTriggerTile->GetTriggerNumber(), GROUP_TYPE::TILE);
	}
	break;
	case EVENT_TYPE::LEVERTRIGGER_ON:
	{
		CLever* pLever = (CLever*)_eve.lParam;
		CSceneManager::GetInstance()->GetCurScene()->TriggerEvent(pLever->GetTriggerNumber(), GROUP_TYPE::LEVER);
	}
		break;
	default:
		break;
	}
}
