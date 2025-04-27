#pragma once
#include "CScene.h"
class CDungeon :
    public CScene
{
private:
    int         m_iLevel;
    CCharacter* m_pMonster;
public:
    CDungeon();
    ~CDungeon();

public:
    void        SetLevel(int _iLevel) { m_iLevel = _iLevel; }

public:
    virtual void	Initialize() override;
    virtual void	Update()	override;
    virtual void	Release()	override;
    virtual void	Render()	override;

};

