#include "pch.h"
#include "CPlayer.h"
#include "CSaveManager.h"


CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{

}

void CPlayer::Initialize(const char* _pName, int _iHp, int _iAttack)
{
	__super::Initialize(_pName, _iHp, _iAttack);
	CSaveManager::GetInstance().SetPlayer(this);
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
}

void CPlayer::Render()
{
	__super::Render();
}

void CPlayer::Save(ofstream& _file)
{
	__super::Save(_file);
	cout << "CPlayer 저장완료" << endl;
	system("pause");
}

void CPlayer::Load(ifstream& _file)
{
	__super::Load(_file);
	cout << "CPlayer 불러오기 완료" << endl;
	system("pause");
}
