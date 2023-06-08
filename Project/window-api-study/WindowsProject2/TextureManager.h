#pragma once

class Texture;

class TextureManager
{
	//�̱��� ���� ���
public:
	///�̱��� �ϴ� ����: data������ ������ mgr��ü�� �ּҰ��� GetInst�Լ��� �����ͼ�, 
	/// AnimalŬ������ ������ ��ü�� mgr�� a���� 10���� ����(�̱����� �Ἥ ��ü�� ������ �� �����ϴ� ���)
	/// mgr�� ������� ������� ������ 1���� �����ؾ��Ѵ�. �׷��� �̱������� ����°��̴�.
	///�̱����� ������Ͽ� �����Ѵ�
	static TextureManager* GetInstance()
	{
		static TextureManager TextureManagerSingleton;
		return &TextureManagerSingleton;
	}
	///��ü�� 1���� �����Ǿ�� �ϹǷ� private
private:
	TextureManager();
	~TextureManager();

	//public �Լ��鸸 ��Ҵ�
public:
	//��Ʈ�� �̹����� �ҷ��´�
	//�ʿ��� ��: ��Ʈ�� �̹����� ����� 
	Texture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	//��Ʈ�� �̹����� 1���� �ҷ��Դ��� Ȯ���Ѵ�
	Texture* FindTexture(const wstring& _strkey);

	//public �����鸸 ��Ҵ�
public:
	map<wstring, Texture* > m_mapTexture;	//map�� ������ Texture
	HDC m_hDC;	///DC�� �ڵ鰪. 
				///���� ����:  CGameProcess���� ���� m_hDC���� �����ϱ� ���ؼ��̴�
};


