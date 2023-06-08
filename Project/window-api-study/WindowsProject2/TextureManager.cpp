#include "pch.h"
#include "TextureManager.h"
#include "CPathManager.h"
#include "Texture.h"


TextureManager::TextureManager()
	:m_hDC(0)	//m_hDC�� ó�� ���鶧 0���� �����
				//�׸��� CGameProcess���� ���� m_hDC���� ������ ���̴�
{
	
}

TextureManager::~TextureManager()
{
	Safe_Delete_map(m_mapTexture);
}

///������Ʈ�鿡�� �ؽ�ó ������ �ε��� �� �ش� �ؽ�ó�� ������ map�� key�� �̸���
///_strRelativePath: content ������ ���� ��ο� ���� �̸�
Texture* TextureManager::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	//���� map���� �ش� �ؽ��� ������ �̹� �ε�� ���¶�� ��� �ؽ��� ���� ��ȯ
	Texture* pTexture = FindTexture(_strKey);
	if (nullptr != pTexture)
	{
		return pTexture;
	}

	//������ �ؽ��� ���� �ҷ��;��Ѵ�
	//CPathManager���� ��θ� ã�ƿ´�. strFilePath=L "Output\\bin\\contest"
	wstring strFilePath = CPathManager::GetInstance()->GetContentPath();

	//strFilePath���� ���� ��ο� ������ �ؽ��� ������ �̸��� �Ű������� �޾ƿԱ� ������ �߰����ָ� �ȴ�
	strFilePath += _strRelativePath;

	//�ؽ�ó ��ü�� �޸𸮸� �Ҵ�ް�
	//Texture�� Load() �Լ����� �̹��� ���� �������� Key�� ����� ����
	pTexture = new Texture(m_hDC);
	pTexture->Load(strFilePath);

	//map�� Key�� �ش� Texture�� �ּ� �Է�
	m_mapTexture.insert(make_pair(_strKey, pTexture));

	//�ε���� Texture�� ��ȯ
	return pTexture;
}

///map�� ������ Ű�� Texture�� �ִ��� Ȯ��
Texture* TextureManager::FindTexture(const wstring& _strkey)
{
	map<wstring, Texture*>::iterator iter = m_mapTexture.find(_strkey);

	if (iter == m_mapTexture.end())
	{
		return nullptr;
	}
	return (Texture*)iter->second;
}





