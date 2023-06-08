#pragma once

class CScene;

class CSceneManager
{
	SINGLE(CSceneManager);
public:
	void Initialize(HWND hWnd, HDC hDC, POINT screenRes);
	void Update();
	void Render(HDC _dc);

	void SetCurScene(CScene* val)
	{
		m_pCurScene = val;
	}
public:
	CScene* GetCurScene() { return m_pCurScene; }

private:
	CScene* m_arrScene[(UINT)SCENE_TYPE::END];		// ��� �� ���
	CScene* m_pCurScene;							// ���� ��

private:
	void ChangeScene(SCENE_TYPE _eNext);
	friend class CEventMgr;
};
