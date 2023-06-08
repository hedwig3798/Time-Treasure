#include "pch.h"
#include "CScene_Tool.h"

#include "CKeyManager.h"
#include "CTile.h"
#include "CGameProcess.h"

//#include "CResMgr.h"
#include "TextureManager.h"

#include "CSceneManager.h"
#include "CPathManager.h"
#include "SoundManager.h"

#include "resource.h"
// �Ͻ����� �г� UI
#include "CPanelUI.h"
#include "CBtnUI.h"
#include "CContinue.h"
#include "CReStart.h"
#include "CMainMenu.h"
// �ΰ��� �ȿ��� UI
#include "CMiniMap.h"
#include "CStone.h"
#include "CPreferences.h"
#include "CPoison.h"
#include "CClock.h"
#include "CClockConut.h"
#include "CPoisonCount.h"
// CScene_Tool Ŭ���� ���� ( �߰� : �̰��� )
CScene_Tool::CScene_Tool(HWND hWnd, HDC hDC, POINT screenRes) : CScene(hWnd, hDC, screenRes)
{
	m_hScreenDC = hDC;
	m_hWnd = hWnd;
	m_ScreenRes = screenRes;
}

CScene_Tool::~CScene_Tool()
{

}
bool CScene_Tool::Exit()
{
	SoundManager::GetInstance()->Stop(BGM);
	return false;
}

// �� ������ ������Ʈ ( �߰� : �̰��� )
void CScene_Tool::Update()
{
	// �θ��� update()�Լ��� ȣ��
	CScene::Update();

	SetTileIdx();

// 	if (CKeyManager::GetInstance()->GetKeyState(KEY::ENTER) == KEY_STATE::TAP)
// 	{
// 		// �̺�Ʈ ��� ( �߰� : �̰��� )
// 		ChangeScene(SCENE_TYPE::START);
// 	}
	if (CKeyManager::GetInstance()->GetKeyState(KEY::LSHIFT) == KEY_STATE::TAP)
	{
		// Ÿ�� �����ϱ� ( �߰� : �̰��� )
		SaveTileData();
	}
	if (CKeyManager::GetInstance()->GetKeyState(KEY::CTRL) == KEY_STATE::TAP)
	{
		// Ÿ�� �ҷ����� ( �߰� : �̰��� )
		LoadTileDate();
	}
}

void CScene_Tool::Enter(bool _isPast)
{
	// Ÿ�� ����
	CreateTile(13, 9, 2, true);

}
 
// ���콺 ��ġ�� ���� Ÿ�� �� �����ϱ� ( �߰� : �̰��� )
void CScene_Tool::SetTileIdx()
{
	static int CopyNumber = 0;

	// ���콺 ��ǥ�� ã�� Ÿ�� ũ�⸸ŭ ������ Ÿ�� �迭 ��ġ ã��
	Vector2 vMousePos = CKeyManager::GetInstance()->GetMousePos();

	int iTileX = (int)GetTileX();
	int iTileY = (int)GetTileY();

	int iCol = (int)vMousePos.x / BOARD_TILE;
	int iRow = (int)vMousePos.y / BOARD_TILE;

	// ���콺 ��ǥ�� Ÿ�� ��ǥ ��ġ ������� ����ó��
	if (vMousePos.x < 0.f || iTileX <= iCol
		|| vMousePos.y < 0.f || iTileY <= iRow)
	{
		return;
	}

	UINT iIdx = iRow * iTileX + iCol;

	// ��Ŭ�� ���� �� ���콺 ��ǥ ã�Ƽ� Ÿ�� �ε��� ���ϱ� ( �߰� : �̰��� )
	if (CKeyManager::GetInstance()->GetKeyState(KEY::LBTN) == KEY_STATE::TAP)
	{
		const vector<CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		((CTile*)vecTile[iIdx])->AddImgIdx();
	}
	
	// ��Ŭ�� ���� �� ���콺 ��ǥ ã�Ƽ� Ÿ�� �ε��� ���� ( �߰� : �̰��� )
	if (CKeyManager::GetInstance()->GetKeyState(KEY::RBTN) == KEY_STATE::TAP)
	{
		const vector<CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		((CTile*)vecTile[iIdx])->MinusImgIdx();
	}

	// ���콺 ��ġ�� �ִ� Ÿ�� ������ C�� ������ ��, �ش� Ÿ�� �ݶ��̴� ���� �� ���� ( �߰� : �̰��� )
	if (CKeyManager::GetInstance()->GetKeyState(KEY::L) == KEY_STATE::TAP)
	{
		const vector<CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		((CTile*)vecTile[iIdx])->CheckCollider();
	}

	// ���콺 ��ġ�� �ִ� Ÿ�� ������ R�� ������ ��, �ش� Ÿ�� Ÿ�� �ε��� ��ȣ ���� ( �߰� : �̰��� )
	if (CKeyManager::GetInstance()->GetKeyState(KEY::R) == KEY_STATE::TAP)
	{
		const vector<CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		CopyNumber = ((CTile*)vecTile[iIdx])->GetImgIdx();
	}

	// ���콺 ��ġ�� �ִ� Ÿ�� ������ T�� ������ ��, �ش� Ÿ�� �ε��� ��ȣ �ٿ��ֱ� ( �߰� : �̰��� )
	if (CKeyManager::GetInstance()->GetKeyState(KEY::T) == KEY_STATE::TAP)
	{
		const vector<CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		((CTile*)vecTile[iIdx])->SetImgIdx(CopyNumber);
	}

	// ���콺 ��ġ�� �ִ� Ÿ�� ������ H�� ������ ��, �ش� Ÿ�� Ÿ�� ���ϱ� ( �߰� : �̰��� )
	if (CKeyManager::GetInstance()->GetKeyState(KEY::H) == KEY_STATE::TAP)
	{
		const vector<CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		((CTile*)vecTile[iIdx])->AddTileType();
	}

	// ���콺 ��ġ�� �ִ� Ÿ�� ������ N�� ������ ��, �ش� Ÿ�� Ʈ���� �ѹ� ���ϱ� ( �߰� : �̰��� )
	if (CKeyManager::GetInstance()->GetKeyState(KEY::N) == KEY_STATE::TAP)
	{
		const vector<CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		((CTile*)vecTile[iIdx])->AddTriggerNumber();
	}

	// ���콺 ��ġ�� �ִ� Ÿ�� ������ M�� ������ ��, �ش� Ÿ�� Ʈ���� �ѹ� ���ϱ� ( �߰� : �̰��� )
	if (CKeyManager::GetInstance()->GetKeyState(KEY::M) == KEY_STATE::TAP)
	{
		const vector<CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		((CTile*)vecTile[iIdx])->AddTriggerDir();
	}
}

// �����쿡�� �������ִ� �Լ��� ���� ����ü �����ϰ� ���� �����ϱ� ( �߰� : �̰��� )
void CScene_Tool::SaveTileData()
{
	wchar_t szName[256] = {};

	OPENFILENAME ofn = {};

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = m_hWnd;
	ofn.lpstrFile = szName;
	ofn.nMaxFile = sizeof(szName);
	ofn.lpstrFilter = L"ALL\0*.*\0Tile\0*.tile\0";				// ALL\0*. �� ALL�� �����ϴ� �ƹ� �̸��� �͵� �ǰ� �ƹ� Ȯ���ڿ��� �ȴ�
	ofn.nFileExtension = 0;
	ofn.lpstrFileTitle = nullptr;								// ���� ������ Ÿ��Ʋ ����
	ofn.nMaxFileTitle = 0;

	wstring strTIleFolder = CPathManager::GetInstance()->GetContentPath();
	strTIleFolder += L"tile";
	
	ofn.lpstrInitialDir = strTIleFolder.c_str();
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	
	// Modal
	// ������ ������ �� ���� ����� �ּҰ� szName�� ���� �迭�� ����
	if (GetSaveFileName(&ofn))
	{
		SaveTile(szName);
	}
}

// �����쿡�� �������ִ� �Լ��� ���� ����ü �����ϰ� ���� �ҷ����� ( �߰� : �̰��� )
void CScene_Tool::LoadTileDate()
{
	wchar_t szName[256] = {};

	// �� ����ü�� �����쿡�� �������ִ� ����ü��
	// �����쿡�� ���� �ҷ����� �����ϴ� ������ �Լ��� ���޵Ǵ� ����ü�̴�
	// https://learn.microsoft.com/ko-kr/windows/win32/api/commdlg/ns-commdlg-openfilenamea?redirectedfrom=MSDN&devlangs=cpp&f1url=%3FappId%3DDev16IDEF1%26l%3DKO-KR%26k%3Dk(COMMDLG%252FOPENFILENAME)%3Bk(OPENFILENAME)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue
	OPENFILENAME ofn = {};

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = m_hWnd;
	ofn.lpstrFile = szName;
	ofn.nMaxFile = sizeof(szName);
	ofn.lpstrFilter = L"ALL\0*.*\0Tile\0*.tile\0";				// ALL\0*. �� ALL�� �����ϴ� �ƹ� �̸��� �͵� �ǰ� �ƹ� Ȯ���ڿ��� �ȴ�
	ofn.nFileExtension = 0;
	ofn.lpstrFileTitle = nullptr;								// ���� ������ Ÿ��Ʋ ����
	ofn.nMaxFileTitle = 0;

	wstring strTIleFolder = CPathManager::GetInstance()->GetContentPath();
	strTIleFolder += L"tile";

	ofn.lpstrInitialDir = strTIleFolder.c_str();
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// Modal
	// ������ ������ �� ��ü ����� �ּҰ� szName�� ���� �迭�� ����
	if (GetOpenFileName(&ofn))
	{
		wstring strFilePath = szName;
		
		// ��� ��� = ��ü ��� - ���� ���
		size_t iAbsLen = wcslen(CPathManager::GetInstance()->GetContentPath());
		size_t iFullLen = strFilePath.length();
		
		wstring strRelativePath = strFilePath.substr(iAbsLen, iFullLen - iAbsLen);

		LoadTile(strRelativePath, true);
	}
}

// �� �� Ÿ�� ��ȯ�ϰ� �����ϱ� ( �߰� : �̰��� )
void CScene_Tool::SaveTile(const wstring& _strFilePath)
{
	// Ŀ�� ������Ʈ
	FILE* pFile = nullptr;

	// �� ��° ���� w�� ����, r�� �б�, rb, wb�� ������ �����ͷ� �аڴ�
	// �ƽ�Ű �ڵ� �߿� ESC = 27�� ���࿡ r�� �дٰ� 27�� ������ �״�� Ż���ϴ� ������ �߻��� ���� �ֱ� ������ rb, wb�� ����
	// ���� ����� ������ ��� ���� ����̱� ������ ������ �����ȴ�
	_wfopen_s(&pFile, _strFilePath.c_str(), L"wb");
	assert(pFile);

	// ������ ����
	// Ÿ�� ���μ��� ���� ����
	UINT xCount = GetTileX();
	UINT yCount = GetTileY();
	UINT TileTypeNumber = GetTileTypeNumber();

	fwrite(&xCount, sizeof(UINT), 1, pFile);
	fwrite(&yCount, sizeof(UINT), 1, pFile);
	fwrite(&TileTypeNumber, sizeof(UINT), 1, pFile);

	// ��� Ÿ�ϵ��� ���������� ������ �����͸� �����ϰ� ��
	const vector<CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);

	for (size_t i = 0; i < vecTile.size(); i++)
	{
		((CTile*)vecTile[i])->Save(pFile);
	}

	fclose(pFile);
}






// Tile Count ������ â ���ν��� ( �߰� : �̰��� )
// ======================
// Tile Count Window Proc
// ======================
INT_PTR __stdcall TileCountProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			// GetDlgItemInt�� �ؽ�Ʈ �ڽ� �ȿ� �ִ� ���ڿ� �����͸� int������ �ٲ㼭 ��ȯ���� ���̴�
			UINT iXCount = GetDlgItemInt(hDlg, IDC_EDIT1, nullptr, false);
			UINT iYCount = GetDlgItemInt(hDlg, IDC_EDIT2, nullptr, false);
			UINT TileFileNumber = GetDlgItemInt(hDlg, IDC_EDIT3, nullptr, false);

			CScene* pCurScene = CSceneManager::GetInstance()->GetCurScene();

			// ToolScene Ȯ��
			// pCurScene�� TooScene�̸� ToolScene ��ȯ, �ƴϸ� nullptr ��ȯ
			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
			assert(pToolScene);

			pToolScene->DeleteGroup(GROUP_TYPE::TILE);
			pToolScene->CreateTile(iXCount, iYCount, TileFileNumber, true);

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}