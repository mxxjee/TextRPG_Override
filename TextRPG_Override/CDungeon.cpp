#include "pch.h"
#include "CDungeon.h"
#include "CMonster.h"

CDungeon::CDungeon()
	:m_pMonster(nullptr),m_iLevel(0)
{
}

CDungeon::~CDungeon()
{
	Release();
}

void CDungeon::Initialize()
{
	const char* pName[3] = { "초급","중급","고급" };
	switch (m_iLevel)
	{
	case 1:
	case 2:
	case 3:
		m_pMonster = new CMonster;
		m_pMonster->Initialize(pName[m_iLevel-1], m_iLevel*30, m_iLevel*3);
		break;

	default:
		break;
	}
}

void CDungeon::Update()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();
		cout << "1.공격 2.도망 :";
		cin >> iInput;

		switch (iInput)
		{

		case 1:
			m_pPlayer->Battle(m_pMonster);

			if (m_pMonster->IsDie())
			{
				cout << "승리" << endl;
				system("pause");
				return;
			}

			if (m_pPlayer->IsDie())
			{
				cout << "패배" << endl;
				m_pPlayer->Respawn();
				system("pause");
				return;
			}
			break;

		case 2:
			return;

		default:
			break;
		}

	}
}

void CDungeon::Release()
{
	SAFEDELETE(m_pMonster);
}

void CDungeon::Render()
{
}
