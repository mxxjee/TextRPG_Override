#include "pch.h"
#include "CField.h"
#include "CDungeon.h"


CField::CField()
{
}

CField::~CField()
{
	Release();
}

void CField::Initialize()
{
	
}

void CField::Update()
{
	int iInput = 0;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1.�ʱ� 2.�߱�. 3.��� 4.���ܰ� : ";
		cin >> iInput;

		switch (iInput)
		{
		
		case 1:
		case 2:
		case 3:
		{
			CDungeon* m_pDungeon = new CDungeon;
			m_pDungeon->SetLevel(iInput);


			m_pNext = m_pDungeon;
		}
			break;

		case 4:
			return;
		default:
			break;
		}

		if (m_pNext)
		{
			m_pNext->SetPlayer(m_pPlayer);
			m_pNext->Initialize();
			m_pNext->Update();
			SAFEDELETE(m_pNext);		//�������� ���ð��, ��������
		}
	}
}

void CField::Release()
{
	
}

void CField::Render()
{
}
