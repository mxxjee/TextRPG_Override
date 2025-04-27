#include "pch.h"
#include "CSaveManager.h"
#include "CPlayer.h"
#include "CScene.h"

#include <fstream>

CSaveManager* CSaveManager::m_pManager = nullptr;

CSaveManager::CSaveManager()
{
	memset(&m_SaveInfo, 0, sizeof(SAVEINFO));
}

CSaveManager::~CSaveManager()
{
}

CSaveManager& CSaveManager ::GetInstance()
{
	if (!m_pManager)
		m_pManager = new CSaveManager;

	return *m_pManager;
}

void CSaveManager::Destroy()
{
	SAFEDELETE(m_pManager);
}

void CSaveManager::Save()
{
	ofstream writeFile;
	writeFile.open("../Data/Save.dat", ios_base::binary);

	if (writeFile.is_open())
	{
		if (m_SaveInfo.m_pPlayer)
			m_SaveInfo.m_pPlayer->Save(writeFile);

		if (m_SaveInfo.m_pShop)
			m_SaveInfo.m_pShop->Save(writeFile);

		writeFile.close();
	}

	else
	{
		cout << "�����ϱ� ����" << endl;
		system("pause");
	}

}

/*Load���� �ߴٸ� true, ���н� false��ȯ
���� ���ڷ� ���� �����͵鿡�� ���� ä���ִ� ����
*/
bool CSaveManager::Load(CCharacter* _LoadPlayer, CScene* _LoadShop)
{
	ifstream readFile;
	readFile.open("../Data/Save.dat", ios_base::binary);

	if (readFile.is_open())
	{
		if (_LoadPlayer)
		{
			_LoadPlayer->Load(readFile);
			SetPlayer(_LoadPlayer);
		}

		if (_LoadShop)
		{
			_LoadShop->Load(readFile);
			SetShop(_LoadShop);
		}

		readFile.close();
		return true;
	}

	else
	{
		cout << "�ҷ��� ������ �����ϴ�." << endl;
		system("pause");
		return false;
	}
}
