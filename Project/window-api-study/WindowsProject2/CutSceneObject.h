#pragma once
#include "CObject.h"
#include "Texture.h"


class Texture;

class CutSceneObject: public CObject	///CObject�� ����� �޾����Ƿ�, Object�� �ƴ� �ٸ� ������ ���� �Լ� �� �� ����. �׷��� CScene_Start�� �ִ� Exit�Լ� ������
{
private:
	Texture* pTextureCutScene[4];		//�ٸ� Ŭ�������� ������ �ʿ� �����Ƿ� private�� �д�
	int index;
	float m_cutscenetime;

public:
	virtual void Update();
	virtual void Render(HDC _dc);
	
	virtual CutSceneObject* Clone() {return this;}
	///������Ʈ ������ �� �ʿ��� �Լ� ( ���� ���� �Լ�, �ڽ� Ŭ�������� ���� �ʿ� )	virtual CObject* Clone() = 0; 
	///�θ�Ŭ������ �Լ� �߿� ���������Լ��� �ִ� ���, �װ͵� ���� �� ������ ����� �ڽ�Ŭ������ ��������Ŭ����(�ƴϸ�, �߻�Ŭ����)�� ���� �ʴ´�.
	/// ���� ���������Լ��� �������ϸ�, �ڽ�Ŭ������ ��������Ŭ������ �Ǵµ� ��������Ŭ������ ��ü�� ���� �� ��� 
	/// CCutScene.cpp��	CutSceneObject* pCutSceneObject = new CutSceneObject; ���� ������ �������̴�


public:
	CutSceneObject();
	~CutSceneObject();

};

