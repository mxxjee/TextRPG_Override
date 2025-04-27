#pragma once

class CCharacter;
class CScene;

typedef struct tagSaveInfo
{
	CCharacter* m_pPlayer;
	CScene* m_pShop;
}SAVEINFO;



class CSaveManager
{
private:
	CSaveManager();
	~CSaveManager();

private:
	SAVEINFO	m_SaveInfo;
	static CSaveManager* m_pManager;

public:
	static CSaveManager& GetInstance();

public:
	void	SetPlayer(CCharacter* _pPlayer) { m_SaveInfo.m_pPlayer = _pPlayer;}
	void	SetShop(CScene* _shop) { m_SaveInfo.m_pShop = _shop; }
	void	Destroy();


public:
	void	Save();
	bool	Load(CCharacter* _LoadPlayer, CScene* _LoadShop);
};

