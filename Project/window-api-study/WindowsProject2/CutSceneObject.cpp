///�ƽſ� �� ������Ʈ�� �����
#include "pch.h"
#include "CutSceneObject.h"

//#include "CScene.h"
//#include "CScene_Title.h"
#include "CSceneManager.h"

#include "CTimeMgr.h"

#include "Texture.h"
#include "TextureManager.h"

#include "CTimeMgr.h"			
#include "Animator.h"
#include "Animation.h"

CutSceneObject::CutSceneObject()
	:m_cutscenetime(0)
	, index(0)
{
	
	//texture �ε�
	pTextureCutScene[0] = TextureManager::GetInstance()->LoadTexture(L"cutscene1", L"texture\\op_1.bmp");
	pTextureCutScene[1] = TextureManager::GetInstance()->LoadTexture(L"cutscene2", L"texture\\op_2.bmp");
	pTextureCutScene[2] = TextureManager::GetInstance()->LoadTexture(L"cutscene3", L"texture\\op_3.bmp");
	pTextureCutScene[3] = TextureManager::GetInstance()->LoadTexture(L"cutscene4", L"texture\\op_4.bmp");
}

CutSceneObject::~CutSceneObject()
{

}

///Update�Լ��� ���� ����ǰ�, Render�Լ��� ���߿� ����ȴ�
void CutSceneObject::Update()
{

	//for�� �Ƚ�, �ð��� ���� index ����

	//�ð�����
	CTimeManager::GetInstance()->GetfDT();		///CTimeManager::GetInstance()�� ���� ����: ��ü(CTimeManagerŸ���� ��ü mgr)�� CTimeManager���� �����´�
	m_cutscenetime += CTimeManager::GetInstance()->GetfDT();/// float�� �����ϴϱ� GetfDT()�� �������� float���̴�
	//�����ð� ��� �� index ����
	if (m_cutscenetime >= 1.0f)
	{
		index++;
		m_cutscenetime = 0.f;
	}

	//index=3 �Ǹ�.... start ������ �Ѿ��. 
	if (index >= 4)
	{
		ChangeScene(SCENE_TYPE::START);
	}

}

void CutSceneObject::Render(HDC _dc)
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
		, pTextureCutScene[index]->GetDC()
		, (int)0
		, (int)0
		, (int)pTextureCutScene[index]->Width()			///���� ������ �ʰ�, �̸� �������� �Լ��� �ؽ��� �̹����� ��, ���� ���� �� �ִ�
		, (int)pTextureCutScene[index]->Height()
		, RGB(255, 0, 255)
	);

}
