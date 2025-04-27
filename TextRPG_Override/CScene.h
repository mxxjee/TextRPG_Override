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
	CCharacter*		m_pPlayer;			//�÷��̾� �������ʿ�
	CScene*			m_pNext;			//������ �ҷ��þ�

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

