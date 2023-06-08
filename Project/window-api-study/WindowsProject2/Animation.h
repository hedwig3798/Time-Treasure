////����� �״��, ������ ��� �ٲ۴�
#pragma once
class Animator;
class Texture;

struct tAnimFrm		///tAnimFrm �� �ִϸ��̼� ������ ����ü
{
	Vector2 vLeftTop;	//�»�� ��ǥ
	Vector2	vSilce;		///�ڸ����� �ִϸ��̼� 1������(����ϳ�) ũ��
	Vector2 vOffset;	///�� ������ �������� ����= �� �������� �»�� x��ǥ ����
	float fDuration;	//���� ���������� �Ѿ�� �ð�(�� ����)
};


class Animation
{
private:
	wstring				m_strName;
	Animator* m_pAnimator;
	Texture* m_pTexture;			//Animation�� ����ϴ� �ؽ���
	vector<tAnimFrm>	m_vectorFrame;		//��� ������ ����
	int					m_iCurrentFrame;	//���� ������
	float				m_fAccountTime;		//�ð� ����
	float				m_fScale;

	bool				m_bFinish;			//��� ���� ���޿���

public:
	const wstring& GetName() { return m_strName; }
	bool IsFinish() { return m_bFinish; }
	
	void SetFrame(int _iFrameIdx)	///�ٽ� ó�� ���������� ���ư��� �ϴ� �Լ�
	{
		m_bFinish = false;	//
		m_iCurrentFrame = _iFrameIdx;	//
		m_fAccountTime = 0.f;
	}

	tAnimFrm& GetFrame(int _iIdx) { return m_vectorFrame[_iIdx - 1]; }
	int GetMaxFrame() { return (int)m_vectorFrame.size(); }

private:
	void SetName(const wstring& _strName) { m_strName = _strName; }

public:
	void Update();
	void Render(HDC _dc);
	void FinalUpdate();
	void Create(Texture* _pTexture, Vector2 _vLeftTop, Vector2 _vSilceSize, Vector2 _vStep, float _fDuration, UINT _iFrameCount, float _fScale = 1.0f);
	


public:
	Animation();
	~Animation();

	friend class Animator;		///Animator�� Animation�� �����Ѵ�
};

