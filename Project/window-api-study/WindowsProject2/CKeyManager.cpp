#include "pch.h"
#include "CKeyManager.h"

#include "CGameProcess.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,	//LEFT,
	VK_RIGHT,	//RIGHT,
	VK_UP,		//UP,
	VK_DOWN,	//DOWN,
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	
	VK_MENU,	// ALT
	VK_CONTROL,	// CTRL
	VK_LSHIFT,	// LSHIFT
	VK_SPACE,	// SPACE BAR
	VK_RETURN,	// ENTER
	VK_ESCAPE,	// ESC

	VK_LBUTTON,
	VK_RBUTTON,
};

CKeyManager::CKeyManager()
{

}

CKeyManager::~CKeyManager()
{

}

void CKeyManager::Initialize()
{
	// Ű�� ��� ���¸� false�� ����
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyManager::Update()
{
	// ������ ��Ŀ�� �˾Ƴ���
	//HWND hMainWnd = CCore::GetInstance()->GetMainHWnd();

	// ���� ��Ŀ�� �Ǿ� �ִ� �������� �ڵ鰪�� �˷��ش�
	// ���� �츮�� ������ �ִ� ��������� �ڵ��� ������ ���� ������ nullptr�� ��ȯ�ȴ�
	HWND hWnd = GetFocus();

	// ������ ��Ŀ�� ���� �� Ű �̺�Ʈ ����
	// ������ â�� ��Ŀ�� ������ ���� �� �������� �ʴ´�
	if (nullptr != hWnd)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			// Ű�� �����ִ�
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				if (m_vecKey[i].bPrevPush)
				{
					// �������� ���� �־���.
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					// ������ �������� �ʾҴ�.
					m_vecKey[i].eState = KEY_STATE::TAP;
				}

				m_vecKey[i].bPrevPush = true;
			}

			// Ű�� �ȴ����ִ�
			else
			{
				if (m_vecKey[i].bPrevPush)
				{
					// ������ ���� �־���.
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					// �������� �������� �ʾҴ�.
					m_vecKey[i].eState = KEY_STATE::NONE;
				}

				m_vecKey[i].bPrevPush = false;
			}
		}
	}

	// ������ ��Ŀ�� ��������
	// �̰��� ������ ������ �ٸ� â�� ��Ŀ�̵� ���¿����� Ű�� �Էµǰ� �ȴ�
	else
	{
		// ���࿡ ������ ��Ŀ���� ������ ���¶�� ��� Ű�� ���¸� AWAY�� NONE ���·� ��ȯ�ϰ� bPrevPush�� false�� ����
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecKey[i].bPrevPush = false;

			if (m_vecKey[i].eState == KEY_STATE::TAP || m_vecKey[i].eState == KEY_STATE::HOLD)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (m_vecKey[i].eState == KEY_STATE::AWAY)
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
}
