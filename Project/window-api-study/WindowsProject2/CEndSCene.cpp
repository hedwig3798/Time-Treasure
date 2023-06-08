///endscene ������Ʈ�� �ҷ��ͼ� endscene �����
#include "pch.h"
#include "CEndSCene.h"
#include "EndSceneObject.h"

class EndSceneObject;

CEndSCene::CEndSCene(HWND hWnd, HDC hDC, POINT screenRes):CScene(hWnd,hDC,screenRes)	
{
}

CEndSCene::~CEndSCene()
{
}

void CEndSCene::Update() 
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
///���̴ϱ� ���ڴ� ����ߵǴ� �� �˾Ҵµ� �ƴϴ�. ������ �־���Ѵ�
void CEndSCene::Enter(bool _isPast)	
{
	SoundManager::GetInstance()->Play(SOUND::BACKGROUND_ENDING, SOUND_CHANNAL::BGM);

	//���� ������Ʈ �߰�
	EndSceneObject* pEndSceneObject = new EndSceneObject;
	AddObject(pEndSceneObject, GROUP_TYPE::DEFAULT);

}

bool CEndSCene::Exit()
{
	SoundManager::GetInstance()->Stop(BGM);
	//��� ������Ʈ ����
	DeleteAll();
	return false;	///���� �������� ����
}