#pragma once
///alt + c�� Ŭ������ �ϴ� �� �ƴ϶�, �Լ��� �ϴ� ���̴�

class AlphaBlending
{
public:
 //	void _AlphaBlend(HDC hdc, HINSTANCE hInst, int x, int y, int BitMap, unsigned char _Alpha);
	Texture* m_memdc;			//HDC�� DC�� handle���̴�, �� ���� �����ϴ� memdc
	Texture* m_hbit;			//HBITMAP�� ��(�� ��ü)�� �ּҰ�
	Texture* m_bitInfo;			//BITMAP�� �ʿ� �޸� �±�(���� ������ ����)

public:




public:
	AlphaBlending();
	~AlphaBlending();
};