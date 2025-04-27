

#include "pch.h"
#include "CMainGame.h"

//Casting 사용하지 않고 virtual함수만 사용하여 TextRPG구현.
//+상점기능 추가( 초급/중급/상급 무기 출력까지만)


int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned)time(NULL));


	CObj* m_pMainGame = new CMainGame;

	if (m_pMainGame)
		m_pMainGame->Initialize();

	m_pMainGame->Update();

	SAFEDELETE(m_pMainGame);

	return 0;
}
