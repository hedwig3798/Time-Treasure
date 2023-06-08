#pragma once

class CObject;		///Animator�� ������ ������Ʈ�� �����͸� ���� ����
class Animation;	//�ִϸ��̼� �������ϴϱ�
class Texture;		//�ؽ��� �ҷ��;��ϴϱ�

class Animator
{
	///Animator Ŭ�������� �� ���� 4�� ����
private:
	map<wstring, Animation*>	m_mapAnimation;			//��� Animation
	Animation*					m_pCurrentAnimation;	//���� ������� Animation
	
	CObject*					m_pOwner;	//Animator ���� ������Ʈ
	/// ������Ʈ�� ������Ʈ�� �����͸� �������ִ�.owner��� ǥ���� ��.�ڱ� �ڽ�(������Ʈ)�� �����ϰ� �ִٴ� ǥ���̴�
	///	������Ʈ�� �����ͼ� �� ������Ʈ�� �ּҸ� ������ �ִ�
	
	bool						m_bRepeat;	//�ݺ���� ����



public:
	///GetObject �Լ��¿� GetCurrentAnimation �Լ��� pOwner�� pCurrentAnimation�� ��ȯ
	CObject* GetObj() { return m_pOwner; }	
	

	///const ���� ��ġ��..? �����
	Animation* GetCurrentAnimation() const
	{
		return m_pCurrentAnimation;
	}


public:
	void CreateAnimation(const wstring& _strName, Texture* _pTexture, Vector2 _vLT, Vector2 _vSilceSize, Vector2 _vStep, float _fDuration, UINT _iFrameCount, float _scale = 1.0f);
	Animation* FindAnimation(const wstring& _strName);
	void Play(const wstring& _strName, bool _bRepeat);

	void Update();
	void Render(HDC _dc);
	void FinalUpdate();
	


public:
	Animator();
	~Animator();

	//������Ʈ�̱� ������ �ش� ������Ʈ���� private ������ ������ �� �ֵ��� friend class Object�� ���� 
	friend class CObject;
};



