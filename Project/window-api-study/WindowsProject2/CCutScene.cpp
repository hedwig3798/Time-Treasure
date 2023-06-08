///�ƽ� ������Ʈ�� �ҷ��ͼ� �ƽ��� �����
#include "pch.h"
#include "CCutScene.h"
#include "CutSceneObject.h"

class CutSceneObject;

CCutScene::CCutScene(HWND hWnd, HDC hDC, POINT screenRes) : CScene(hWnd, hDC, screenRes)	///cpp����, h���� CCutScene���� ���ڵ� ����, ���� �Ȱ��� 
{
	m_eNextScene = SCENE_TYPE::STAGE_1_1;
}

CCutScene::~CCutScene()
{

}

void CCutScene::Update() 
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; i++)
	{
		vector<CObject*>::iterator iter = m_arrObj[i].begin();

		for (; iter != m_arrObj[i].end();)
		{
			if ((*iter)->IsDead())
			{
				iter = m_arrObj[i].erase(iter);
				continue;
			}
			else if (!(*iter)->m_bActive)
			{
				iter++;
			}
			else
			{
				(*iter)->Update();
				iter++;
			}
		}
	}
}

//������Ʈ ����
void CCutScene::Enter(bool _isPast)
{
	//�ƽ� ������Ʈ �߰�
	CutSceneObject* pCutSceneObject = new CutSceneObject;
	AddObject(pCutSceneObject, GROUP_TYPE::DEFAULT);
}

bool CCutScene::Exit()
{
	// ��� ������Ʈ ����
	DeleteAll();
	return false;	///���翡�� �����ҰŴϱ� false�� ��ģ��.
}

