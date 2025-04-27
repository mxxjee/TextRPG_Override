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
		cout << "저장하기 실패" << endl;
		system("pause");
	}

}

/*Load성공 했다면 true, 실패시 false반환
단지 인자로 받은 포인터들에게 값을 채워주는 역할
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
		cout << "불러올 파일이 없습니다." << endl;
		system("pause");
		return false;
	}
}
