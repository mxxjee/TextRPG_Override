#pragma once
#include "CScene.h"
#include "CItem.h"
class CShop :
    public CScene
{
private:
	CItem*	m_pItems;
	int		ItemCount;

public:
	CShop();
	CShop(int _Count);
	virtual ~CShop() override;

public:
	virtual void	Initialize() override;

	virtual void	Update()	override;
	virtual void	Release()	override;
	virtual void	Render()	override;


public:
	void		Save(ofstream& _file) override;
	void		Load(ifstream& _file) override;

};

