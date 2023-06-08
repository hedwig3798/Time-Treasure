#include "pch.h"
#include "CTimeMgr.h"
#include "CGameProcess.h"


CTimeManager::CTimeManager()
	:m_llcurCount{}
	, m_llPrevCount{}
	, m_llFrequency{}
	, m_dDT(0.)
	, m_iCallCount(0)
{

}

CTimeManager::~CTimeManager()
{

}

void CTimeManager::Initialize()
{
	// ���� ī��Ʈ
	QueryPerformanceCounter(&m_llPrevCount);

	// �ʴ� ī��Ʈ Ƚ�� (õ��)
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeManager::Update()
{
	QueryPerformanceCounter(&m_llcurCount);

	// ���� �������� ī���ð� ���� ������ ī���� ���� ���̸� ���Ѵ�.
	m_dDT = (double)(m_llcurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;

	// ����ī��Ʈ ���� ���簪���� ���� (�������� ����� ���ؼ�)
	m_llPrevCount = m_llcurCount;

	// ���࿡ �ߴ����� ��� �˻��ϴ� ����� ���¶�� �ð��� �帣�� ���� �����ϱ� ���� ������ ��ó����
#ifdef _DEBUG
	if (m_dDT > (1. / 60.))
		m_dDT = (1. / 60.);
#endif
}

void CTimeManager::Render()
{
	++m_iCallCount;
	m_dAcc += m_dDT;	// DT ����

	if (m_dAcc >= 1.)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.;
		m_iCallCount = 0;
	}
}
