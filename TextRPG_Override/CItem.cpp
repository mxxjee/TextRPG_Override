#include "pch.h"
#include "CItem.h"
#include <fstream>

CItem::CItem()
{
	memset(&m_ItmInfo, 0, sizeof(ITMINFO));
	m_ItmInfo.m_pName = nullptr;
}

CItem::~CItem()
{
	Release();
}

void CItem::Initialize()
{
	m_ItmInfo.m_pName = new char[MAXSTR];
}

void CItem::Initialize(const char* _pName, int _price, int _count)
{

	m_ItmInfo.m_pName = new char[MAXSTR];
	strcpy_s(m_ItmInfo.m_pName, MAXSTR, _pName);

	m_ItmInfo.iPrice = _price;
	m_ItmInfo.iCount = _count;


}

void CItem::Update()
{
}

void CItem::Release()
{
	SAFEDELETE_ARR(m_ItmInfo.m_pName);

}

void CItem::Render()
{
	cout << "아이템 이름 : " << m_ItmInfo.m_pName << endl;
	cout << "가격 : " << m_ItmInfo.iPrice << "\t개수 : " << m_ItmInfo.iCount << endl;

}

void CItem::Save(ofstream& _file)
{
	_file.write(reinterpret_cast<char*>(m_ItmInfo.m_pName), MAXSTR);
	_file.write(reinterpret_cast<char*>(&m_ItmInfo.iCount), sizeof(int));
	_file.write(reinterpret_cast<char*>(&m_ItmInfo.iPrice), sizeof(int));

}

void CItem::Load(ifstream& _file)
{
	m_ItmInfo.m_pName = new char[MAXSTR];

	_file.read(reinterpret_cast<char*>(m_ItmInfo.m_pName), MAXSTR);
	_file.read(reinterpret_cast<char*>(&m_ItmInfo.iCount), sizeof(int));
	_file.read(reinterpret_cast<char*>(&m_ItmInfo.iPrice), sizeof(int));

}
