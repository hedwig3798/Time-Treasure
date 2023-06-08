#pragma once
#include "pch.h"
#include "CMonster.h"
//#include "CResMgr.h"
#include "TextureManager.h"

#include "Texture.h"
#include "CScene.h"

class CScene;
class Texture;

class CTimeGuardian :
	public CMonster
{
public:
	CTimeGuardian();
	~CTimeGuardian();
	virtual void Update();
	virtual CTimeGuardian* Clone() { return new CTimeGuardian(*this); }
	virtual void Render(HDC _dc);   //��� �߰�- ����
	void SetBoardPos(POINT _pt) { m_ptBoardPos = _pt; }

private:
	Texture* m_mTextureLeft;   // ��� �߰� - ����
	Texture* m_mTextureRight;   // ��� �߰� - ����

private:
	// ������ ������
	float m_fMoveDelay;
	float m_fMoveMent;
	float m_fStunDelay;

	const float m_fStunDelayRate = 10.0f;
	const float m_fMoveDelayRate = 1.0f;

	bool m_bIsTargeting;

	Vector2 m_vChasePos;

	OBJECT_DIR m_eCurrDir;
	OBJECT_DIR m_ePrevDir;
	bool m_bCanMove;
	bool m_bIsLeft;
	POINT m_ptBoardPos;
	MONSTER_STATE m_eCurrState;
	MONSTER_STATE m_ePrevState;

	void UpateState();
	void UpdateMove();
	void UpdateAnimation();

	virtual void OnCollisionEnter(CCollider* _pOther);
};

