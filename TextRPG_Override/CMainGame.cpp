#include "pch.h"
#include "CMainGame.h"
#include "CPlayer.h"
#include "Enum.h"

#include "CField.h"
#include "CShop.h"
#include "CSaveManager.h"

CMainGame::CMainGame()
	:m_pShop(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::SelectJob()
{
	int iInput = 0;

	//1.플레이어객체 생성
	m_pPlayer = new CPlayer;
	
	while (true)
	{
		cout << "직업을 선택하세요 (1.전사 2.마법사 3.도적 4.불러오기) : ";
		cin >> iInput;

		switch (EJOB(iInput))
		{
		case EJOB::WARRIOR:
			m_pPlayer->Initialize("전사", 100, 10);
			return;

		case EJOB::MAGE:
			m_pPlayer->Initialize("마법사", 100, 10);
			return;

		case EJOB::THIEF:
			m_pPlayer->Initialize("도적", 100, 10);
			return;

		case EJOB::LOAD:
		{
			//로드 한다면, 상점을 불러오기 위해 객체를 생성해주자.
			m_pShop = new CShop(SHOP_ITEM_COUNT);

			/*불러오기 실패했다면, 생성한 m_pShop반환 후 다시선택하도록*/
			if (!CSaveManager::GetInstance().Load(m_pPlayer, m_pShop))
			{
				SAFEDELETE(m_pShop);
				continue;
			}
			
		}
			return;

		default:
			break;
		}

	}
}

void CMainGame::Initialize()
{
	SelectJob();
	

	//만약 위에서 불러오기를 하지 않았다면,
	// (shop이 최초 생성이라면) shop객체 생성
	if (!m_pShop)
	{
		m_pShop = new CShop(SHOP_ITEM_COUNT);
		m_pShop->Initialize();
	}

	

	
}

void CMainGame::Update()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1.사냥터 2.상점 3.저장 4.종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pNext = new CField;
			m_pNext->Initialize();
			break;

		case 2:
			m_pNext = m_pShop; //shop은 나가도 초기화되지 않으므로, 미리생성된 shop의 주소가리키도록
			break;

		case 3:
			CSaveManager::GetInstance().Save();
			continue;
			break;

		case 4:
			return;
		default:
			break;
		}
		
		if (m_pNext)
		{
			m_pNext->SetPlayer(m_pPlayer);
			m_pNext->Update();

			if (m_pNext != m_pShop)	  //shop은 지속해야하는 객체.
				SAFEDELETE(m_pNext);


		}

	}
}

void CMainGame::Release()
{
	if (m_pNext != m_pShop)
		SAFEDELETE(m_pNext);


	SAFEDELETE(m_pShop);
	SAFEDELETE(m_pPlayer);

	CSaveManager::GetInstance().Destroy();
}

void CMainGame::Render()
{
}
