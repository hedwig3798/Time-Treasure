#pragma once
#include "CObject.h"
#include "Texture.h"
#include "TextureManager.h"
#include "Animator.h"
#include "CThron.h"
class Texture;
class CThron;
class CFire :
    public CObject
{
private:
    float m_fTheta;
    OBJECT_DIR  m_dir;
    float m_fLifeTiem;

public:
    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(OBJECT_DIR _vDir)
    {
        m_dir = _vDir;
    }
    bool TriggerOn;


public:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;

    // ��ü���� ���� �����ڸ� ȣ���� ��, Ŭ�� ����
    virtual CFire* Clone() { return new CFire(*this); }

public:
    virtual void OnCollisionEnter(CCollider* _pOther);

public:
    CFire(OBJECT_DIR _dir);
    ~CFire();
};