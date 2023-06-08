////����� �״��, ������ ��� �ٲ۴�
#include "pch.h"
#include "Animator.h"
#include "Animation.h"

Animator::Animator()
	:m_pOwner(nullptr)	//Animation ������ ������Ʈ�� �ּ�
	, m_pCurrentAnimation(nullptr)	//���� ������� Animaion�� �ּ�?
	, m_bRepeat(false)	//ó������ �ݺ���� ���Ѵ�. ������ ������ true�� �ٲ�� �ݺ����
	
{
}

Animator::~Animator()
{
	Safe_Delete_map(m_mapAnimation);	//�������̴���
}

///scale�� �߰��Ǿ���. 
						///1.0f�� ����Ʈ��
						///m_fScale�� ������ â�� ũ�⸦ �ø��ų�(���Ѵ�), ���̴µ�(������), �� ���� Animator�κ��� �޾ƿ´�
						///Animator�� �� ���� Object�κ��� �޾ƿ´�

///�ִϸ��̼� ����: texture�� ������ ������ �����
///�׷���  CreateAnimation���ڰ��� texture�������� ���� _pTexture�� �ִ°Ŵ�
void Animator::CreateAnimation(const wstring& _strName, Texture* _pTexture, Vector2 _vLeftTop, Vector2 _vSilceSize, Vector2 _vStep
	, float _fDuration, UINT _iFrameCount, float _scale )
{
	//���� �̸��� ����ϴ� �ִϸ��̼��� �ִ��� üũ(FindAnimation �Լ� ���)
	//���� �̸��� ����ϴ� �ִϸ��̼��� ���� ��� assert���� ���� üũ
	Animation* pAnimation = FindAnimation(_strName);
	assert(nullptr == pAnimation);	/// pAnimation==nullptr�� �ȵǳ�?
	///�ִϸ��̼� ������ �� ���� �̸��� ����ϴ� �ִϸ��̼� �ִ��� üũ�ϴ� ����, ���� �̸��� �ִϸ��̼� ã�� ������ texture���� �Ȱ���
	///�ٸ�, texture���� �ٸ��� �ִϸ��̼��� ����� ���� �ܰ�� �Ѿ �� �ִ�

	//�ִϸ��̼� ��ü�� ���� �� �̸�, ������Ʈ ���� ��ü, m_mapAnimation�� �̸��� ���� �������ֱ� ���� �ִϸ��̼��� map�� ���
	pAnimation = new Animation;
	pAnimation->SetName(_strName);	///SetName�� AnimaionŬ������ ���ǵǾ�����
	pAnimation->m_pAnimator = this;		///m_pAnimator�� Animation Ŭ������ ���ǵ� 

	m_mapAnimation.insert(make_pair(_strName, pAnimation));


	//�ִϸ��̼� ������ ������ ����, create�Լ��� �ִ� pTexture�� �ִϸ��̼ǿ� ����ϴ� texture�̴�
	pAnimation->Create(_pTexture, _vLeftTop, _vSilceSize, _vStep, _fDuration, _iFrameCount, _scale);
}


//�Ȱ��� �̸��� �ִϸ��̼� ã�� �Լ�
Animation* Animator::FindAnimation(const wstring& _strName)
{
	map<wstring, Animation*>::iterator iter;
	iter = m_mapAnimation.find(_strName);
	if (iter == m_mapAnimation.end())
		return nullptr;

	return iter->second;
}

///��������� ����Ѵ�
//���� ������� �ִϸ��̼� Update()
void Animator::Update()
{
			
}

//���� ������� �ִϸ��̼� render
void Animator::Render(HDC _dc)
{
	if (nullptr != GetCurrentAnimation())
	{
		GetCurrentAnimation()->Render(_dc);
	}
}


void Animator::FinalUpdate()
{
	if (nullptr != GetCurrentAnimation())
	{
		GetCurrentAnimation()->FinalUpdate();


		// �ִϸ��̼��� �ݺ� ���θ� üũ�� bRepeat�� true�̰� Animation ��ü���� �ִϸ��̼��� �������� üũ�ϴ� finish�� ���¸� �����ͼ�
		// Animation�� �������� 0���� �����ϰ� finish ������ false�� ����
		if (m_bRepeat && GetCurrentAnimation()->IsFinish())
		{
			GetCurrentAnimation()->SetFrame(0);
		}
	}
}

//���ڷ� ���� �̸��� �ִϸ��̼� ���
void Animator::Play(const wstring& _strName, bool _bRepeat)
{
	m_pCurrentAnimation = FindAnimation(_strName);
	m_bRepeat = _bRepeat;
	m_pCurrentAnimation->m_bFinish = false;
}