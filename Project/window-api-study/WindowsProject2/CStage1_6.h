#pragma once
#include "CScene.h"
class CStage1_6 :
    public CScene
{
public:
	CStage1_6(HWND hWnd, HDC hDC, POINT screenRes);
	~CStage1_6();
	void Enter(bool _isPast) override;
	bool Exit() override;

};

