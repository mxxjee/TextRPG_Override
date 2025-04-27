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

	//1.�÷��̾ü ����
	m_pPlayer = new CPlayer;
	
	while (true)
	{
		cout << "������ �����ϼ��� (1.���� 2.������ 3.���� 4.�ҷ�����) : ";
		cin >> iInput;

		switch (EJOB(iInput))
		{
		case EJOB::WARRIOR:
			m_pPlayer->Initialize("����", 100, 10);
			return;

		case EJOB::MAGE:
			m_pPlayer->Initialize("������", 100, 10);
			return;

		case EJOB::THIEF:
			m_pPlayer->Initialize("����", 100, 10);
			return;

		case EJOB::LOAD:
		{
			//�ε� �Ѵٸ�, ������ �ҷ����� ���� ��ü�� ����������.
			m_pShop = new CShop(SHOP_ITEM_COUNT);

			/*�ҷ����� �����ߴٸ�, ������ m_pShop��ȯ �� �ٽü����ϵ���*/
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
	

	//���� ������ �ҷ����⸦ ���� �ʾҴٸ�,
	// (shop�� ���� �����̶��) shop��ü ����
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
		cout << "1.����� 2.���� 3.���� 4.���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pNext = new CField;
			m_pNext->Initialize();
			break;

		case 2:
			m_pNext = m_pShop; //shop�� ������ �ʱ�ȭ���� �����Ƿ�, �̸������� shop�� �ּҰ���Ű����
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

			if (m_pNext != m_pShop)	  //shop�� �����ؾ��ϴ� ��ü.
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
