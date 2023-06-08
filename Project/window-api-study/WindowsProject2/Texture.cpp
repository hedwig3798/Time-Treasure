#include "pch.h"
#include "Texture.h"

Texture::Texture(HDC _dc)
	:m_memdc(nullptr)	///
	,m_hbit(nullptr)	///
	,m_bitInfo()
{
	m_memdc = CreateCompatibleDC(_dc);	/// _dc���� ȣȯ�� �Ǵ� dc���� �ϳ� ���� m_memdc�� �����Ѵ�. 
										///(m_memdc�� HDC�̴�(HDC�� DC�� handle��. handle�� DC�� ����Ŵ). handle�� ����Ű�� ��(DC)�� �Ҹ��ڰ� ����� �� �Բ� ������� �ʴ´�
}										///handle�� m_memdc�� �Ҹ��ڰ� ����� �� ���� �������

Texture::~Texture()
{
	//�Ҹ��� �� Ŭ���� ���ο� �ִ� ��������� ���� �Ҹ��� �ȿ� ���� �ʴ���, Ŭ������ �Ҹ�� �� ���� �Ҹ�ȴ�
	//������ Ŭ���� �ܺο� �ִ� ����(���� ��� _dc)�� �Ҹ���� �ʴ´�
	//�ַ� �����Ҵ��Ҷ� �����Ҵ�� ������ �Ҹ��ڿ� ���� ������ ������� �ʴ´�. 
	//�Ҹ��ڿ� delete ����� �������

	//�����丵 ������ Ŭ������ �Լ����� memdc�� ���� �����߱� ������, �� ���� �Ҹ��ڿ� �Ἥ �����߾��������
	//�����丵 �Ŀ��� _dc���� �״�� �޾ƿ��⶧����, �����ϸ� �ȵȴ�. (_dc�� �����ϴ� ��� �Լ��鿡 ������ �����)
	
	//Ŭ������ ���� �߰��� �͸� �Ҹ��ڿ� �Ἥ ���� ���־��Ѵ�. ��Ʈ�� �̹����� �߰��Ǿ�����, �̸� �����Ѵ�
	DeleteObject(m_hbit);
	DeleteDC(m_memdc);	///DeleteDC�� m_memdc�� ����Ű�� ���� DC�� �����Ѵ�(������ ����ߵ���, DC�� �Ҹ��ڰ� ����Ǿ ������� �ʱ⶧��)
						///m_memdc�� HDC�̹Ƿ�, DC�� handle���̴�. handle�� ����Ű�� DC���� �����ϴ°Ŵ�

	//�ؽ��� Ŭ������ HBITMAP�� ����ȴ�
	//�ؽ��� Ŭ������ TextureManager�� ����Ǿ� TextManager���� �����Ѵ�
	//���α׷��� "����"�� �� �Ҹ��ڰ� ����Ǿ� ��Ʈ���̹����� �����ȴ�
}



void Texture::Load(const wstring& _strFilePath)
{
	//�����쿡 ����� �Լ��� LoadImage �Լ��� ��Ʈ�� �ҷ��´�
	m_hbit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hbit);

	//������ ���� ��Ʈ�ʰ� ������ DC�� ���������, �����丵 �Ŀ��� Texture�� _dc�� �̹� �޾ƿͼ� �� Ŭ���� �ȿ� _dc�� ��Ʈ���� ���� �־ �� ������ �ʿ䰡 ����

	//DC�� ��Ʈ���� ���Ḹ �ϸ� �ȴ�. �̶� SelectObject �Լ� ����
	SelectObject(m_memdc, m_hbit);

	//��Ʈ�� ������ GetObject�Լ� ����
	GetObject(m_hbit, sizeof(BITMAP), &m_bitInfo);
}
