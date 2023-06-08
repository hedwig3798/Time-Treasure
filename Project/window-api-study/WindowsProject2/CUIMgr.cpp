#include "pch.h"
#include "CUIMgr.h"

#include "CSceneManager.h"
#include "CScene.h"
#include "CUI.h"
#include "CKeyManager.h"

CUIMgr::CUIMgr()
	: m_pFocusedUI(nullptr)
{
 
}

CUIMgr::~CUIMgr()
{

}

void CUIMgr::Update()
{
	// 1. FocusedUI Ȯ�� 
	m_pFocusedUI = GetFocusedUI();

	if (!m_pFocusedUI)
		return;
	CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();
	const vector<CObject*>& vecUI = pCurScene->GetGroupObject(GROUP_TYPE::UI);	

	bool bLbtnTap = CKeyManager::GetInstance()->GetKeyState(KEY::LBTN) == KEY_STATE::TAP;
	bool bLbtnAway = CKeyManager::GetInstance()->GetKeyState(KEY::LBTN) == KEY_STATE::AWAY;

	for (size_t i = 0; i < vecUI.size(); ++i)
	{
		// �θ� UI ����, �ڽ� UI �� �� ���� Ÿ���� �� UI �����ȴ�.
		CUI* pUI = (CUI*)vecUI[i];

		pUI = GetTargetedUI(pUI);

		if (nullptr != pUI)
		{
			pUI->MouseOn();

			if (bLbtnTap)
			{
				pUI->MouseLbtnDown();
				pUI->m_bLbtnDown = true;
			}
			else if (bLbtnAway)
			{
				pUI->MouseLbtnup();

				if (pUI->m_bLbtnDown)
				{
					pUI->MouseLbtnClicked();
				}

				//���� ��ư ����, ���Ǵ� üũ�� �ٽ� �����Ѵ�.
				pUI->m_bLbtnDown = false;
			}
		}
	}
}

CUI* CUIMgr::GetFocusedUI()
{
	CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();
	vector<CObject*>& vecUI = pCurScene->GetUIGroup();
	bool bLbtnTap = CKeyManager::GetInstance()->GetKeyState(KEY::LBTN) == KEY_STATE::TAP;

	// ���� ��Ŀ���� UI�� �޾Ƶΰ� ����Ǿ��� �� Ȯ���Ѵ�.
	CUI* pFocusedUI = m_pFocusedUI;
	if (bLbtnTap)
	{
		return pFocusedUI;
	}

	//���� ��ư Tap �� �߻��ߴٴ� ����.
	vector<CObject*>::iterator targetiter = vecUI.end();
	vector<CObject*>::iterator iter = vecUI.begin();
	for (; iter != vecUI.end(); ++iter)
	{
		if (((CUI*)*iter)->IsMouseOn())
		{
			targetiter = iter;
		}
	}

	//�̹��� Focus �� UI�� ����.
	if (vecUI.end() == targetiter)
	{
		return nullptr;
	}

	pFocusedUI = (CUI*)*targetiter;

	// ���ͳ����� �ǵڷ� ���� ��ü 

	vecUI.erase(targetiter);
	vecUI.push_back(pFocusedUI);

	return pFocusedUI;
}

void CUIMgr::SetFocusedUI(CUI* _pUI)
{
	// �̹� ��Ŀ�� ���� ��� or ��Ŀ���� ��ü��û�� ���
	if (m_pFocusedUI == _pUI || nullptr == _pUI)
	{
		m_pFocusedUI = _pUI;
		return;
	}

	m_pFocusedUI = _pUI;

	CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();
	vector<CObject*>& vecUI = pCurScene->GetUIGroup();

	vector<CObject*>::iterator iter = vecUI.begin();

	for (; iter != vecUI.end(); ++iter)
	{
		if (m_pFocusedUI == *iter)
		{
			break;
		}
	}

	// ���ͳ����� �ǵڷ� ���� ��ü 
	vecUI.erase(iter);
	vecUI.push_back(m_pFocusedUI);
}



CUI* CUIMgr::GetTargetedUI(CUI* _pParentUI)
{
	
	bool bLbtnAway = CKeyManager::GetInstance()->GetKeyState(KEY::LBTN) == KEY_STATE::AWAY;
	
	//1. �θ� UI ����, ��� �ڽĵ��� �˻��Ѵ�.
	CUI* pTargetUI = nullptr;

	static list<CUI*> queue;
	static vector<CUI*> vecNoneTarget;

	queue.clear();
	vecNoneTarget.clear();

	queue.push_back(_pParentUI);

	while (!queue.empty())
	{
		// ť���� ������ �ϳ� ������

		CUI* pUI = queue.front();
		queue.pop_front();

		// ť���� ������ UI�� TargetUI ���� Ȯ��
		// Ÿ�� UI�� ��, �� �켱 ������ ���� ����� �� ���� ������ �ڽ� UI
		if (pUI->IsMouseOn())
		{
			if (nullptr != pTargetUI)
			{
				vecNoneTarget.push_back(pTargetUI);
			}
			pTargetUI = pUI;
		}
		else
		{
			vecNoneTarget.push_back(pUI);
		}

		const vector<CUI*>& vecChild =  pUI->GetChildUI();
		for (size_t i = 0; i < vecChild.size(); ++i)
		{
			queue.push_back(vecChild[i]); 
		}
	}

	// ���� ��ư ���� ������ üũ�� �ٽ� �����Ѵ�.
	if (bLbtnAway)
	{	
		for (size_t i = 0; i <vecNoneTarget.size(); ++i)
		{
		vecNoneTarget[i]->m_bLbtnDown = false;
		}
	}
	// 2. Ÿ�� UI �� ��, �� �켱������ ���� ������ �� ���� ������ �ڽ� UI

	return pTargetUI;
}

void CUIMgr::ReStart()
{

}

void CUIMgr::Start()
{
}

void CUIMgr::MainMenu()
{

}



void CUIMgr::PlayerDio()
{

}

void CUIMgr::Continue()
{
}
