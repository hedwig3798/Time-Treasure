////����� �״��, ������ ��� �ٲ۴�

#include "pch.h"
#include "Animation.h"
#include "Texture.h"
#include "Animator.h"
#include "CObject.h"
#include "CTimeMgr.h"

Animation::Animation()
	:m_pAnimator(nullptr)
	, m_pTexture(nullptr)
	, m_iCurrentFrame(0)
	, m_fAccountTime(0.f)
	, m_bFinish(false)
	, m_fScale(1.0f)		///1.0f�� ����Ʈ��
	///m_fScale�� ������ â�� ũ�⸦ �ø��ų�(���Ѵ�), ���̴µ�(������), 
	/// Animation�� �� ���� Animator�κ��� �޾ƿ´�
{
}

Animation::~Animation()
{
}

void Animation::Update()
{

}

void Animation::Render(HDC _dc)
{
	if (m_bFinish)
		return;
	if (m_fScale <= 0)
	{
		return;
	}
	CObject* pObject = m_pAnimator->GetObj();
	Vector2 vPos = pObject->GetPos();

	vPos += m_vectorFrame[m_iCurrentFrame].vOffset;	// Object Position�� Offset��ŭ �߰� �̵���ġ

	
	///m_fScale�� ������ â�� ũ�⸦ �ø��ų�(���Ѵ�), ���̴µ�(������), 
	///Animation�� �� ���� Animator�κ��� �޾ƿ´�
	TransparentBlt(		
		_dc																				///������ â	
		, (int)(vPos.x - m_vectorFrame[m_iCurrentFrame].vSilce.x / (2.f * m_fScale))	 
		, (int)(vPos.y - m_vectorFrame[m_iCurrentFrame].vSilce.y / (2.f * m_fScale))	 
		, (int)(m_vectorFrame[m_iCurrentFrame].vSilce.x / m_fScale)						 
		, (int)(m_vectorFrame[m_iCurrentFrame].vSilce.y / m_fScale)						//object -> animator -> animation ���� fScale ���� ���޵ȴ�
		, m_pTexture->GetDC()															///������ �ؽ��� �̹��� ��ǥ �� ũ��, m_pTexture->GetDC()	: ������ �ؽ��� �̹��� ��ǥ �� ũ��
		, (int)(m_vectorFrame[m_iCurrentFrame].vLeftTop.x)
		, (int)(m_vectorFrame[m_iCurrentFrame].vLeftTop.y)
		, (int)(m_vectorFrame[m_iCurrentFrame].vSilce.x)
		, (int)(m_vectorFrame[m_iCurrentFrame].vSilce.y)
		, RGB(255, 0, 255));															///�������� ó���� ���� ��Ʈ���� RGB ���Դϴ�. Magenta ����� �߾�

	//������ �ؽ��� �̹����� ������ â�� �׸��ٰ� �����ϰ� �Ѿ��
	///fScale�� ������ �ؽ��ĸ� �׸� ��ġ(������ â) ���� �����ϰ�, ������ �ؽ��Ŀ��� ���������ʴ´�(���� �� �ƴ϶�, ������ �Ŵϱ� �׷��Ŵ�)

}

void Animation::FinalUpdate()
{
	if (m_bFinish)
		return;

	m_fAccountTime += CTimeManager::GetInstance()->GetfDT();

	if (m_fAccountTime > m_vectorFrame[m_iCurrentFrame].fDuration)
	{
		m_iCurrentFrame++;

		if (m_vectorFrame.size() <= m_iCurrentFrame)
		{
			m_iCurrentFrame = 0;
			m_bFinish = true;
			m_fAccountTime = 0.f;
			return;
		}

		m_fAccountTime = m_fAccountTime - m_vectorFrame[m_iCurrentFrame-1].fDuration;
	}
}

void Animation::Create(Texture* _pTexture, Vector2 _vLeftTop, Vector2 _vSilceSize, Vector2 _vStep, float _fDuration, UINT _iFrameCount, float _fScale)
{
	m_pTexture = _pTexture;
	m_fScale = _fScale;				///Animation Ŭ������ ��������� create�Լ��� ���ڸ� �����ϴ� ���: this ������ �̿��Ѵ�
									///Ŭ������ ����Լ���, this��� �Ű������� �Ͻ������� ���ԵǾ��ִ�. this�� ������(�ڱ� �ڽ��� ��ü�� ����Ű�� ������)�̴�  

	tAnimFrm AnimationFrame = {};
	for (UINT i = 0; i < _iFrameCount; i++)
	{
		AnimationFrame.fDuration = _fDuration;
		AnimationFrame.vSilce = _vSilceSize;
		AnimationFrame.vLeftTop = _vLeftTop + _vStep * i;

		//���� �� �Է��ϰ� vector�迭�� �Է�
		m_vectorFrame.push_back(AnimationFrame);
	}
}