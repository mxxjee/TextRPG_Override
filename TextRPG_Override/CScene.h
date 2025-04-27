#pragma once
//#include "CObj.h"
#include "CCharacter.h"

class CScene :
    public CObj
{
public:
	CScene();
	~CScene() override;
protected:
	CCharacter*		m_pPlayer;			//플레이어 정보가필요
	CScene*			m_pNext;			//다음에 불러올씬

public:
	virtual void	Initialize() override;
	virtual void	Update()	override;
	virtual void	Release()	override;
	virtual void	Render()	override;

public:
	virtual void		Save(ofstream& _file) {}
	virtual void		Load(ifstream& _file) {}

public:
	void	SetPlayer(CCharacter* _Player) { m_pPlayer = _Player; }

};

