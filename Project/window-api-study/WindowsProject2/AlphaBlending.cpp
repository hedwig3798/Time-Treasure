///fade in, out�� �� alphablend ���� (�߰�����, �ȵǴ��� �Լ� ���������� �غ���)
#include "pch.h"
#include "AlphaBlending.h"
#include <wingdi.h>
#include "Texture.h"


/// ���ĺ���
/// ����! Per-Pixel Alpha Blending�� �Ϸ���,
/// 1. ����ä���� �־�� ��. (32��Ʈ)
/// 2. Pre-Multiplied Alpha Image�̾�� ��.


AlphaBlending::AlphaBlending()
	:m_memdc(nullptr)
	, m_hbit(nullptr)
	, m_bitInfo(0)
{	
}





AlphaBlending::~AlphaBlending()
{

}



