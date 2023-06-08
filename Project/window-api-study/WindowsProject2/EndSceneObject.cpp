///������ �� ������Ʈ�� �����
#include "pch.h"
#include "EndSceneObject.h"

#include "CSceneManager.h"

#include "CTimeMgr.h"

#include "Texture.h"
#include "TextureManager.h"

#include "CTimeMgr.h"			
#include "Animator.h"
#include "Animation.h"
#include "SoundManager.h"

EndSceneObject::EndSceneObject()
	:m_endscenetime(0)
	, index(0)
{
	pTextureEndScene[0] = TextureManager::GetInstance()->LoadTexture(L"endscene1", L"texture\\ed_1.bmp");
	pTextureEndScene[1] = TextureManager::GetInstance()->LoadTexture(L"endscene2", L"texture\\ed_2.bmp");
	pTextureEndScene[2] = TextureManager::GetInstance()->LoadTexture(L"endscene3", L"texture\\ed_3.bmp");
	pTextureEndScene[3] = TextureManager::GetInstance()->LoadTexture(L"endscene4", L"texture\\ed_4.bmp");
	//pTextureEndScene[4] = TextureManager::GetInstance()->LoadTexture(L"endscene5", L"texture\\ed_5.bmp");
}

EndSceneObject::~EndSceneObject()
{
}

///Update�Լ��� ���� ����ǰ�, Render�Լ��� ���߿� ����ȴ�
void EndSceneObject::Update()
{

	//for�� �Ƚ�, �ð��� ���� index ����

	//�ð�����
	CTimeManager::GetInstance()->GetfDT();						///CTimeManager::GetInstance()�� ���� ����: ��ü(CTimeManagerŸ���� ��ü mgr)�� CTimeManager���� �����´�
	m_endscenetime += CTimeManager::GetInstance()->GetfDT();	/// float�� �����ϴϱ� GetfDT()�� �������� float���̴�
	//�����ð� ��� �� index ����
	if (m_endscenetime >= 1.0f)
	{
		index++;
		m_endscenetime = 0.f;
	}

	//index=3 �Ǹ�.... start ������ �Ѿ��. 
	if (index >= 4)
	{
		ChangeScene(SCENE_TYPE::CREDIT);
		SoundManager::GetInstance()->Stop(SOUND_CHANNAL::BGM);

	}

}

void EndSceneObject::Render(HDC _dc)
{
	///index�� 3���� ũ��, �迭�� out of range�� �Ǿ� pTextureCutScene[3]�� �����Ⱚ�� ���Եȴ�. �׷��� �׳� �״� ������ �߻��߾���
	///�̶� ����ó���� �ؼ�, update�� ����, finalupdate�� ����, render�� ����ȴ�
	/// update���� �ε��� ������Ű��, 3�� �Ǹ� changescene �ϴµ�, �ٷ� changescene �Ǵ� ���� �ƴ϶�, render�� �� changescene�� �Ͼ��
	/// ������ index(3���� ũ�ų� ���� ��)�� render�� �����ϸ� ������ �ȴ�, �� index�� �׸����� ������ �����
	/// �׷���, ����ó���� �ѰŴ� return;�� �ϸ�, �ƹ��͵� �Ⱥ����ϱ� ������ �Ȼ���Ŵ�
	if (index >= 4)
	{
		return;
	}

	TransparentBlt(
		_dc
		, (int)0
		, (int)0
		, (int)1920
		, (int)1080
		, pTextureEndScene[index]->GetDC()
		, (int)0
		, (int)0
		, (int)pTextureEndScene[index]->Width()			///���� ������ �ʰ�, �̸� �������� �Լ��� �ؽ��� �̹����� ��, ���� ���� �� �ִ�
		, (int)pTextureEndScene[index]->Height()
		, RGB(255, 0, 255)
	);

}


