#include "pch.h"
#include "CShop.h"
#include "CSaveManager.h"
#include <fstream>


CShop::CShop()
	:m_pItems(nullptr), ItemCount(0)
{
}

CShop::CShop(int _Count)
	:ItemCount(_Count), m_pItems(nullptr)
{
}

CShop::~CShop()
{
	Release();
	
}

void CShop::Initialize()
{
	m_pItems = new CItem[ItemCount];
	
	const char* pNames[3] = { "초급 무기","중급 무기","고급 무기" };
	
	for (int i = 0; i < ItemCount; ++i)
	{
		m_pItems[i].Initialize(pNames[i], (i + 1) * 100 ,(rand() % 5 + 1));
	}

	CSaveManager::GetInstance().SetShop(this);

}



void CShop::Update()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		Render();
		m_pPlayer->Render();

		cout << "1.구매 2.나가기 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			break;

		case 2:
			return;
		default:
			break;
		}
	}
}

void CShop::Release()
{
	SAFEDELETE_ARR(m_pItems);
}

void CShop::Render()
{
	cout << "====================Shop====================" << endl;
	for (int i = 0; i < ItemCount; ++i)
	{
		m_pItems[i].Render();
		cout << endl;
	}

	
}

void CShop::Save(ofstream& _file)
{
	_file.write(reinterpret_cast<char*>(&ItemCount), sizeof(int));

	for (int i = 0; i < ItemCount; ++i)
	{
		m_pItems[i].Save(_file);
	}

	


}

void CShop::Load(ifstream& _file)
{
	_file.read(reinterpret_cast<char*>(&ItemCount), sizeof(int));

	m_pItems = new CItem[ItemCount];

	for (int i = 0; i < ItemCount; ++i)
	{
		m_pItems[i].Load(_file);
	}

	cout << "CShop 불러오기 완료" << endl;
	system("pause");



}
