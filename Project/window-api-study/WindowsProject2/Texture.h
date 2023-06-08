#pragma once

class TextureManager;
//class CResMgr;	//TextureManager ����� �����

class Texture		//texture ������ �����ϴ� Ŭ����, :�� �θ�, �ڽ�Ŭ���� ��Ÿ������ ���� ( class �ڽ�: public �θ�)
{
	//public �����ʴ� ����: �ٸ� ������� ���� ������� ���� ���ϰ� �Ϸ���
private:
	HBITMAP		m_hbit;				//HBITMAP�� ��(�� ��ü)�� �ּҰ�
	BITMAP		m_bitInfo;			//BITMAP�� �ʿ� �޸� �±�(���� ������ ����)
	HDC			m_memdc;			//HDC�� DC�� handle���̴�, �� ���� �����ϴ� memdc

public:
	void Load(const wstring& _strFilePath);

	///���� ������ �Լ� (�����κ�(����)�� ����¥�� �� �Լ�)�� h���Ͽ� ���� ���� �� ȿ�����̴�
	UINT Width() { return m_bitInfo.bmWidth; }
	UINT Height() { return m_bitInfo.bmHeight; }

	HDC GetDC() { return m_memdc; }		///������� �ʾ����� ���� �Ǿ���

public:
	Texture(HDC _dc);		//������ �� �޾Ҵ� ���ڴ� �����Ҷ� �ڷ��� �Ȱ��� �޴´�(�Լ��� �����)
	~Texture();
	//����� ������ virtual�� �Ƚᵵ �ȴ�

	///friend class�� ������ Ŭ������ private�� ���� �����ϴ�
	friend class TextureManager;
	//friend class CResMgr;	//TextureManager ����� �����
};

