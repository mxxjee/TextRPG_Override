#pragma once
#include "CObj.h"
#include "Struct.h"

class CItem :
    public CObj
{
public:
	CItem();
	virtual ~CItem() override;

protected:
    ITMINFO m_ItmInfo;


public:
	virtual void	Initialize() override;
	void	Initialize(const char* _pName, int _price, int _count);
	
	virtual void	Update()	override;
	virtual void	Release()	override;
	virtual void	Render()	override;

public:
	virtual	void	Save(ofstream& _file);
	virtual void	Load(ifstream& _file);
};

