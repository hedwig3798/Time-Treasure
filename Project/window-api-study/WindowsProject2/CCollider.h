#pragma once

class CObject;

class CCollider
{
private:
	static UINT g_iNextID;

	CObject* m_pOwner;			// Collider�� �����ϰ� �ִ� ������Ʈ
	Vector2	m_vOffsetPos;		// ������Ʈ�� ���� ������� ��ġ
	Vector2	m_vFinalPos;		// finalupdate ���� �� ������ ���� ���
	Vector2	m_vScale;			// �浹ü ũ��

	UINT	m_iID;				// �浹ü ������ ID ��
	UINT	m_iCol;				
	

public:
	void SetOffsetPos(Vector2 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(Vector2 _vScale) { m_vScale = _vScale; }

	Vector2 GetOffsetPos() { return m_vOffsetPos; }
	Vector2 GetScale() { return m_vScale; }
	Vector2 GetFinalPos() { return m_vFinalPos; }

	CObject* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }

public:
	void Finalupdate();
	void Render(HDC _dc);

public:
	// �浹 ���� �Լ�
	void OnCollision(CCollider* _pOther);					// �浹 ���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionEnter(CCollider* _pOther);				// �浹 ���� ��
	void OnCollisionExit(CCollider* _pOther);				// �浹 ���� ��


	CCollider& operator=(CCollider& _origin) = delete;		// �ش� ���۷���Ʈ�� ����

public:
	CCollider();
	CCollider(const CCollider& _origin);
	~CCollider();

	friend class CObject;
};

