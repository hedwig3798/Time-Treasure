#include "pch.h"
#include "CCollisionManager.h"

#include "CScene.h"
#include "CSceneManager.h"
#include "CObject.h"
#include "CCollider.h"

CCollisionManager::CCollisionManager()
	:m_arrCheck{}
{

}
CCollisionManager::~CCollisionManager()
{

}

void CCollisionManager::Initialize()
{
}

// 
void CCollisionManager::Update()
{
	for (UINT iRow = 0; iRow < (UINT)GROUP_TYPE::END; ++iRow)
	{
		for (UINT iCol = 0; iCol < (UINT)GROUP_TYPE::END; ++iCol)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				CollisionGroupUpdate((GROUP_TYPE)iRow, (GROUP_TYPE)iCol);
			}
		}
	}
}

// ���� �浹�Ǵ� ������Ʈ Ȯ��
void CCollisionManager::CollisionGroupUpdate(GROUP_TYPE e_Left, GROUP_TYPE _eRight)
{
	CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();
	map<ULONGLONG, bool>::iterator iter;

	vector<CObject*> vecLeft = pCurScene->GetGroupObject(e_Left);
	vector<CObject*> vecRight = pCurScene->GetGroupObject(_eRight);
	
	for (size_t i = 0; i < vecLeft.size(); i++)
	{
		// �浹ü�� �������� �ʴ� ���
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (size_t j = 0; j < vecRight.size(); j++)
		{
			// �浹ü�� ���ų�, �ڱ� �ڽŰ��� �浹�� ���
			if (nullptr == vecRight[j]->GetCollider()
				|| vecLeft[i] == vecRight[j])
				continue;

			CCollider* pLeftCol = vecLeft[i]->GetCollider();
			CCollider* pRightCol = vecRight[j]->GetCollider();


			// �� �浹ü ���� ���̵� ����
			COLLIDER_ID ID;
			ID.Left_id = pLeftCol->GetID();
			ID.Right_id = pRightCol->GetID();

			iter =  m_mapColInfo.find(ID.ID);

			// �浹 ������ �� ��� ������ ��� ��� (�ʱ� ���� : �浹���� �ʾҴ�)
			if (m_mapColInfo.end() == iter)
			{
				m_mapColInfo.insert(make_pair(ID.ID, false));
				iter = m_mapColInfo.find(ID.ID);
			}

			// �� �浹ü�� �浹�ϰ� �ֳ�?
			if (IsCollision(pLeftCol, pRightCol))
			{
				// ���� �浹 ���̴�.
				if (iter->second)
				{
					// �������� �浹 �ϰ� �־���.
					if (vecLeft[i]->IsDead() || vecRight[j]->IsDead())
					{
						// �� �� �ϳ��� ���� �����̶��, �浹 ���������ش�.
						pLeftCol->OnCollisionExit(pRightCol);
						pRightCol->OnCollisionExit(pLeftCol);
						iter->second = false;
					}
					else
					{
						pLeftCol->OnCollision(pRightCol);
						pRightCol->OnCollision(pLeftCol);
						iter->second = true;
					}
				}
				else
				{
					// �������� �浹���� �ʾҴ�. ( ó�� �浹�� ���� )
					// �� �� �ϳ��� ���� �����̶��, �浹���� ���� ������ ���
					if (!vecLeft[i]->IsDead() && !vecRight[j]->IsDead())
					{
						pLeftCol->OnCollisionEnter(pRightCol);
						pRightCol->OnCollisionEnter(pLeftCol);
						iter->second = true;
					}
				}
			}
			else
			{
				// ���� �浹�ϰ� ���� �ʴ�.
				if (iter->second)
				{
					// �������� �浹�ϰ� �־���.
					pLeftCol->OnCollisionExit(pRightCol);
					pRightCol->OnCollisionExit(pLeftCol);
					iter->second = false;
				}

			}
		}
	}
}

// �� �浹ü�� ���� �浹 �˻�
bool CCollisionManager::IsCollision(CCollider* _pLeftCol, CCollider* _pRightCol)
{
	// �� �� �ϳ��� Ȱ�� ������Ʈ�� �ƴϸ� �浹 ó�� ����
	if (!_pLeftCol->GetObj()->m_bActive || !_pRightCol->GetObj()->m_bActive)
	{
		return false;
	}
	Vector2 vLeftPos = _pLeftCol->GetFinalPos();
	Vector2 vLeftScale = _pLeftCol->GetScale();
	
	Vector2 vRightPos = _pRightCol->GetFinalPos();
	Vector2 vRightScale = _pRightCol->GetScale();

	// �� �ݸ����� ������ �� true
	if (abs(vRightPos.x - vLeftPos.x) < (vLeftScale.x + vRightScale.x) / 2.f
		&& abs(vRightPos.y - vLeftPos.y) < (vLeftScale.y + vRightScale.y) / 2.f)
	{
		return true;
	}

	return false;
}

void CCollisionManager::CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	// ��Ʈ �����ڸ� ���
	// �� ���� ���� �׷� Ÿ���� ������,
	// ū ���� ��(��Ʈ) �� ���

	UINT iRow = (UINT)_eLeft;
	UINT iCol = (UINT)_eRight;

	if (iCol < iRow)
	{
		iRow = (UINT)_eRight;
		iCol = (UINT)_eLeft;
	}

	// ���� �浹 ���¸� üũ�� ���¿��� �ٽ� �����ϸ� üũ �ƿ�
	if (m_arrCheck[iRow] & (1 << iCol))
	{
		m_arrCheck[iRow] &= ~(1 << iCol);
	}
	else
	{
		m_arrCheck[iRow] |= (1 << iCol);
	}

}
