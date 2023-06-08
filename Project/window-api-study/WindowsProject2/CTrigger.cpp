#include "pch.h"
#include "CTrigger.h"

CTrigger::CTrigger()
{
	CreateCollider();
	GetCollider()->SetOffsetPos(Vector2(0.f, 0.f));
	GetCollider()->SetScale(Vector2(50.f, 50.f));
}

CTrigger::~CTrigger()
{
}

void CTrigger::Update()
{
}

void CTrigger::OnCollisionEnter(CCollider* _pOther)
{
	// Ʈ���ſ� ���� ��� ���� ������Ʈ �ߵ�
	if (_pOther->GetObj()->GetName() == L"Player")
	{
		for (size_t i = 0; i < m_vecTraps.size(); i++)
		{
			m_vecTraps[i]->SetTriggered(true);
		}
	}
}

void CTrigger::OnCollisionExit(CCollider* _pOther)
{
	// Ʈ���ſ� ���� ��� ���� ������Ʈ ����
	if (_pOther->GetObj()->GetName() == L"Player")
	{
		for (size_t i = 0; i < m_vecTraps.size(); i++)
		{
			m_vecTraps[i]->SetTriggered(false);
		}
	}
}

void CTrigger::AddTrap(CTrap* _trap)
{
	m_vecTraps.push_back(_trap);
}

