#pragma once
#include "CObj.h"
#include "Struct.h"

class CCharacter :
    public CObj
{
public:
	CCharacter();
	~CCharacter() override;
protected:
    INFO    m_tInfo;

public:
	virtual void	Initialize() override;
	virtual void	Update()	override;
	virtual void	Release()	override;
	virtual void	Render()	override;

public:
	virtual	void	Save(ofstream& _file);
	virtual void	Load(ifstream& _file);

public:
	virtual void	Initialize(const char* _pName, int _iHp, int _iAttack);

public:
	void		SetDamage(int _iDmg) { m_tInfo.iHp -= _iDmg; }
	void		Respawn() { m_tInfo.iHp = 100; }
public:
	bool		IsDie() { return m_tInfo.iHp <= 0; }
	void		Battle(CCharacter* Other);
public:
	const		INFO& GetInfo() const { return m_tInfo; }

};

