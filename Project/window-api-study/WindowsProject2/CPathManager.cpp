#include "pch.h"

#include "CPathManager.h"


CPathManager::CPathManager()
	: m_szContentPath{}
{

}

CPathManager::~CPathManager()
{

}

void CPathManager::Initialize()
{
	// ���� ��� : D:\GA5th1Q_Project\TimeTravel\5_Project\window-api-study\Output\bin		// release
	// ���� ��� : D:\GA5th1Q_Project\TimeTravel\5_Project\window-api-study\Output\bin_debug	// debug
	GetCurrentDirectory(255, m_szContentPath);

	int iLen = (int)wcslen(m_szContentPath);

	// ���� ������
	// Debug�� ������ ��쿡�� \\Output\\bin.Debug�� ����Ǵ�
	// \\Output ���� �����ϱ� ����
	for (int i = iLen - 1; 0 <= i; --i)
	{
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}

	// ��� : D:\GA5th1Q_Project\TimeTravel\5_Project\window-api-study\Output\

	// \\Output\\bin\\content�� ���ڿ� �Է�
	// ������ ���ҽ� texture�� sound�� ���еǾ� �ִµ� �̴� �� ������Ʈ���� �����Ѵ�
	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");
}