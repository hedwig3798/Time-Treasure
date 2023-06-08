#pragma once

#include "pch.h"

/// <summary>
/// ���� ������ �����
/// 
/// ���� ū Ʋ�� �̷�� Ŭ����
/// 
/// 2023.05.22 LeHide2Cam1CSCREEN
/// </summary>
class CGameProcess
{
public:
	CGameProcess();
	~CGameProcess();

public:
	int Initialize(HWND _hWnd, POINT _ptResoultion);
	void Progress();

public:
	HWND GetMainHWnd() { return m_hWnd; }


	/// ///////////////////////////////////////////////////////////////////////
	/// �� �Ʒ� �κ��� Graphics Engine���� ���� �� ��.
	/// TODO:LEHIDE
private:
	void CreateBrushPen();

public:
	HDC GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResolution; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }

private:
	HWND	m_hWnd;					// ���� ������ �ڵ�
	POINT	m_ptResolution;			// ���� ������ �ػ�
	HDC		m_hDC;					/// ��ũ�� DC (ȭ��)

	HBITMAP	m_hBit;
	HDC		m_memDC;

	HBRUSH	m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN	m_arrPen[(UINT)PEN_TYPE::END];
	/// ///////////////////////////////////////////////////////////////////////
};