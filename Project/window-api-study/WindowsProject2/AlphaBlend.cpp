///fade in, out�� �� alphablend ���� (�߰�����, �ȵǴ��� �Լ� ���������� �غ���)
#include "pch.h"
//#include "AlphaBlend.h"
//
//AlphaBlenD::AlphaBlenD()
//{
//	BITMAP BitmapInfo;
//	HDC MemDC;
//	HBITMAP MyBitmap, OldBitmap;
//	BLENDFUNCTION bf;
//	MemDC = CreateCompatibleDC(hdc);
//}
//
////_AlphaBlend: hdc���� BitMap���� ������ ��Ʈ���� �������ϰ� ����մϴ�. _Alpha �Ű������� ����� ������ �����ϴµ� ���˴ϴ�.
//void AlphaBlenD::_AlphaBlend(HDC hdc, HINSTANCE hInst, int x, int y, int BitMap, unsigned char _Alpha)
//{
//	MyBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(BitMap));// pre-multiplied alpha
//	OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);
//	GetObject(MyBitmap, sizeof(BITMAP), &BitmapInfo);
//	BitBlt(hdc, x, y, BitmapInfo.bmWidth, BitmapInfo.bmHeight, MemDC, 0, 0, SRCCOPY);
//
//
//	// Blend Function
//	bf.BlendOp = AC_SRC_OVER;
//	bf.BlendFlags = 0;
//	bf.AlphaFormat = AC_SRC_ALPHA;
//	bf.SourceConstantAlpha = (BYTE)_Alpha;	// ��ü ���İ��� �����ϸ�, pre-multiplied�� �ݿ��ȴ�.
//
//	AlphaBlend(hdc, x, y, BitmapInfo.bmWidth, BitmapInfo.bmHeight, MemDC, 0, 0, BitmapInfo.bmWidth, BitmapInfo.bmHeight, bf); // blend function
//
//	SelectObject(MemDC, OldBitmap);
//	//DeleteObject(MyBitmap);
//	//DeleteDC(MemDC);
//
//}
//
//
//
//AlphaBlenD::~AlphaBlenD()
//{
//	DeleteObject(MyBitmap);
//	DeleteDC(MemDC);
//}
#include "AlphaBlend.h"
