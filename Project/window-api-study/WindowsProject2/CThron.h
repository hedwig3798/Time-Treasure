#pragma once
#include "CObject.h"
#include "Texture.h"
#include "TextureManager.h"
#include "CCollider.h"

class CCollider;
class Texture;

class CThron :
    public CObject
{
public:
    CThron(bool _isPast);
    ~CThron();

    void Update() override;
    void Render(HDC _dc) override;
    virtual CThron* Clone() { return (CThron*)this; }
    void IsOn()
    {
        m_bIsOn = true;
    }
    void SetIsOn(bool _setbool)
    {
        if (m_bIsOn)
            m_bIsOn = false;
        else
            m_bIsOn = true;
    }
    bool GetIsOn() { return m_bIsOn; }

    ///virtual ���� �ڽĿ��� �� �Լ��� ����Ѵ�(�ڽ�Ŭ�������� ������ �� �� �ִ�)
    ///virtual�� ������, �� �Լ��� �ڽĿ��� ������� �ʴ´�
    ///override�� �پ�������, �θ�Ŭ������ �� �Լ��� virtual�� �پ��ִٴ� ��
   
    ///���⿣ virtual �Ⱥپ���. �̸���, CThronŬ������ �ڽ�Ŭ������ �������� �ڽ�Ŭ�������� OnCollisionEnter�Լ��� ������ ���� �ʴ´ٴ� ���̴�
    ///������, �ڿ� override �پ������ϱ�, CThronŬ������ �θ�Ŭ������ CObjectŬ������ OnCollisionEnter�Լ��� virtual�� �پ����� �� �� �ִ�
    void OnCollisionEnter(CCollider* _pOther) override;
    void OnCollisionExit(CCollider* _pOther) override;

    bool m_bIsPast;
private:
    Texture* m_pTexture;

    bool m_bIsOn;
};

