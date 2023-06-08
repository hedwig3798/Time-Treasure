#pragma once

#include <windows.h>

/// <summary>
/// ��ã�⸦ ����Ѵ�.
/// 
/// 2023.05.22 LeHideKGIT
/// </summary>
class CPathManager
{
	SINGLE(CPathManager);
private:
	wchar_t		m_szContentPath[255];

public:
	void Initialize();
	const wchar_t* GetContentPath() { return m_szContentPath; }

};

