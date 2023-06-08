#pragma once

#include <windows.h>
#include "CScene.h"     // TILE Ŭ���� ( �߰� : �̰��� )

/// <summary>
/// ������ ���� �� Ŭ����
/// 
/// ���� ����� ��.. �� ��
/// 
/// 2023.05.22 LeHide2Cam
/// </summary>
class CScene_Tool : public CScene
{
public:
    CScene_Tool(HWND hWnd, HDC hDC, POINT screenRes);
    ~CScene_Tool();

public:
    virtual void Update();
    virtual void Enter(bool _isPast);
    virtual bool Exit();

public:
    void SetTileIdx();

    void SaveTileData();
    void LoadTileDate();
    void SaveTile(const wstring& _strFilePath);

private:
    HWND m_hWnd;
    HDC m_hScreenDC;
    POINT m_ScreenRes;
};