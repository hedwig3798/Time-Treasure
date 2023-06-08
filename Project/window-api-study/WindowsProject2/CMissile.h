#pragma once
#include "pch.h"
#include "CObject.h"

#include "Texture.h"
#include "TextureManager.h"

class CMissile :
    public CObject
{
private:
    float m_fTheta;
    OBJECT_DIR  m_dir;
    float m_fLifeTiem;
   
    ///�ؽ��ķ� �� �̹��� �߰�
    Texture* m_pMissileTexture[4];
    int m_iIndex;

public:
    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(OBJECT_DIR _vDir)
    { 
        m_dir = _vDir;
    }


public:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;

    // ��ü���� ���� �����ڸ� ȣ���� ��, Ŭ�� ����
    virtual CMissile* Clone() { return new CMissile(*this); }

public:
    virtual void OnCollisionEnter(CCollider* _pOther);

public:
    CMissile();
    ~CMissile();
};