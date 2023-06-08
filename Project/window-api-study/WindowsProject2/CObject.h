#pragma once
class CCollider;
class Animator;

class CObject
{
public:
	virtual void Update() = 0;
	virtual void Finalupdate();
	virtual void Render(HDC _dc);

	void ComponentRender(HDC _dc, bool _CollisionOn);

	// ������Ʈ ������ �� �ʿ��� �Լ� ( ���� ���� �Լ�, �ڽ� Ŭ�������� ���� �ʿ� )
	virtual CObject* Clone() = 0;

public:
	// ��ġ, ũ�� ����
	virtual void SetPos(Vector2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vector2 _vScale) { m_vScale = _vScale; }
	Vector2 GetPos() { return m_vPos; }
	Vector2 GetScale() { return m_vScale; }

	// �̸� ���� �Ŀ� �ݸ������� �浹 ó���� �Ǿ��� ��, ��� ������Ʈ�� �̸��� Ȯ���ϰ� ����ó���� �� �� �ִ�.
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	// ������Ʈ ��������
	CCollider* GetCollider() { return m_pCollider; }
	Animator* GetAnimator() { return m_pAnimator; }

	// ���� ������Ʈ���� Ȯ���ϱ� ���� �Լ�
	bool IsDead() { return !m_bAlibe; }

public:
	// ������Ʈ ����
	void CreateCollider();
	void CreateAnimator();

	// �ݸ��� �̺�Ʈ �߻�
	virtual void OnCollision(CCollider* _pOther) {}
	virtual void OnCollisionEnter(CCollider* _pOther) {}
	virtual void OnCollisionExit(CCollider* _pOther) {}

private:
	// ���� �����ӿ� ���� ������Ʈ ����
	void SetDead() { m_bAlibe = false; }

public:
	CObject();									// �⺻ ������
	CObject(const CObject& _origin);			// ���� ������
	virtual ~CObject();	// �Ҹ���	
	bool		m_bActive;
	bool		m_CollisionOn;

private:
	Vector2		m_vPos;			// ��ġ
	Vector2		m_vScale;		// ũ��
	wstring		m_strName;		// ��ü �̸�
	bool		m_bAlibe;		// ��ü ����
	

	// Component
	CCollider*	m_pCollider;
	Animator*	m_pAnimator;


	friend class CEventMgr;
};
