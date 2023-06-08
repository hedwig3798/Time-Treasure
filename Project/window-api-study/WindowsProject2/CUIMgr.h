#pragma once

class CUI;

class CUIMgr
{
	SINGLE(CUIMgr);
private:
	CUI* m_pFocusedUI;
public:
	void Update();
	void SetFocusedUI(CUI* _pUI);
	void ReStart();
	void Start();
	void MainMenu();
	void PlayerDio();
	void Continue();
private:
	// �θ� UI ������ ������ Ÿ���� �� UI �� ã�Ƽ� ��ȯ�Ѵ�. 
	CUI* GetTargetedUI(CUI* _pParentUI);
	CUI* GetFocusedUI();
};