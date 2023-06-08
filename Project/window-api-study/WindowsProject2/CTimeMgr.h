#pragma once


class CTimeManager
{
public:
	static CTimeManager* GetInstance()
	{
		static CTimeManager mgr;	///CTimeManagerŸ���� ��ü mgr�� �����. ��, mgr�� Instance(�ν��Ͻ�). �̱����� ���� mgr�� ã�Ⱑ ������� �����ϸ� �Ⱦ��°� ����
		return &mgr;
	}
private:
	CTimeManager();
	~CTimeManager();

public:
	void Initialize();
	void Update();
	void Render();

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }	

private:
	LARGE_INTEGER	m_llcurCount;
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llFrequency;

	double			m_dDT;	// ������ ������ �ð���
	double			m_dAcc;	// 1�� üũ�� ���� ���� �ð�
	UINT			m_iCallCount;	// �Լ� ȣ�� Ƚ�� üũ
	UINT			m_iFPS;		//�ʴ� ȣ�� Ƚ��
};