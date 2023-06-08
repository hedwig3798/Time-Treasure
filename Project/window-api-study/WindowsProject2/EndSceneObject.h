#pragma once
#include "CObject.h"
#include "Texture.h"

class Texture;

class EndSceneObject: public CObject	
{
private:
	Texture* pTextureEndScene[4];
	int index;
	float m_endscenetime;


public:
	virtual void Update();
	virtual void Render(HDC _dc);

	virtual EndSceneObject* Clone() { return this; }
	///������Ʈ ������ �� �ʿ��� �Լ� ( ���� ���� �Լ�, �ڽ� Ŭ�������� ���� �ʿ� )	virtual CObject* Clone() = 0; 
	///�θ�Ŭ������ �Լ� �߿� ���������Լ��� �ִ� ���, �װ͵� ���� �� ������ ����� �ڽ�Ŭ������ ��������Ŭ����(�ƴϸ�, �߻�Ŭ����)�� ���� �ʴ´�.
	/// ���� ���������Լ��� �������ϸ�, �ڽ�Ŭ������ ��������Ŭ������ �Ǵµ� ��������Ŭ������ ��ü�� ���� �� ��� 
	/// CCutScene.cpp��	CutSceneObject* pCutSceneObject = new CutSceneObject; ���� ������ �������̴�


public:
	EndSceneObject();
	~EndSceneObject();


};

