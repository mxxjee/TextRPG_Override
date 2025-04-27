#include "pch.h"
#include "CCharacter.h"
#include <fstream>

CCharacter::CCharacter()
{
	memset(&m_tInfo, 0, sizeof(INFO));
	m_tInfo.m_pName = nullptr;
}

CCharacter::~CCharacter()
{
	Release();
}

void CCharacter::Initialize()
{
	m_tInfo.m_pName = new char[MAXSTR];
}

void CCharacter::Initialize(const char* _pName, int _iHp, int _iAttack)
{

	m_tInfo.m_pName = new char[MAXSTR];
	strcpy_s(m_tInfo.m_pName, MAXSTR, _pName);
	m_tInfo.iAttack = _iAttack;
	m_tInfo.iHp = _iHp;

}

void CCharacter::Battle(CCharacter* Other)
{
	if (Other)
	{
		this->SetDamage(Other->m_tInfo.iAttack);
		Other->SetDamage(m_tInfo.iAttack);


	}
}

void CCharacter::Update()
{
}

void CCharacter::Release()
{
	SAFEDELETE_ARR(m_tInfo.m_pName);
}

void CCharacter::Render()
{
	cout << "============================================" << endl;
	cout << "�̸� : " << m_tInfo.m_pName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack <<endl;


}

void CCharacter::Save(ofstream& _file)
{
	if (_file.is_open())
	{
		_file.write(reinterpret_cast<char*>(m_tInfo.m_pName), MAXSTR);
		_file.write(reinterpret_cast<char*>(&m_tInfo.iHp), sizeof(int));
		_file.write(reinterpret_cast<char*>(&m_tInfo.iAttack), sizeof(int));
		cout << "Characater ����Ϸ�" << endl;
		system("pause");
	}

}

void CCharacter::Load(ifstream& _file)
{
	if (_file.is_open())
	{
		m_tInfo.m_pName = new char[MAXSTR];

		_file.read(reinterpret_cast<char*>(m_tInfo.m_pName), MAXSTR);
		_file.read(reinterpret_cast<char*>(&m_tInfo.iHp), sizeof(int));
		_file.read(reinterpret_cast<char*>(&m_tInfo.iAttack), sizeof(int));
		cout << "Characater �ҷ����� �Ϸ�" << endl;
		system("pause");
	}
}
