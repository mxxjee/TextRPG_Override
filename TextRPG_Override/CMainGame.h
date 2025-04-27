#pragma once
#include "CScene.h"


class CMainGame
	:public CScene
{
private:
	/**/
	CScene* m_pShop;		//
public:
	CMainGame();
	~CMainGame() override;

private:
	void			SelectJob();
public:
	virtual void	Initialize() override;
	virtual void	Update()	override;
	virtual void	Release()	override;
	virtual void	Render()	override;


};

