#pragma once
#include "CScene.h"
class CStage1_1 :
    public CScene
{
public:
	CStage1_1(HWND hWnd, HDC hDC, POINT screenRes);
	~CStage1_1();

	void Enter(bool _isPast) override;

	bool Exit() override;

	
};

