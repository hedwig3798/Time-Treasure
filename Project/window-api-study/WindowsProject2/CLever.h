#pragma once
#include "CObject.h"


class CLever :
	public CObject
{
private:
	int TriggerNumber;
	bool LeverOnOff;
	bool IsCurrent;

public:
	virtual void Update();
	virtual void Render(HDC _dc);

	void TurnTime();

public:
	int GetTriggerNumber() { return TriggerNumber; }
	void SetTriggerNumber(int _TriggerNumber) { TriggerNumber = _TriggerNumber; }

	// ������Ʈ ������ �� �ʿ��� �Լ� ( ���� ���� �Լ�, �ڽ� Ŭ�������� ���� �ʿ� )
	virtual CLever* Clone() { return this; }

public:
	virtual void OnCollisionEnter(CCollider* _pOther);
	bool m_bIsPast;

public:
	CLever(bool _isPast);
	~CLever();
};