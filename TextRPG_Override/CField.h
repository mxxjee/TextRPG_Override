#pragma once
#include "CScene.h"
#include "CDungeon.h"

class CField :
    public CScene
{

public:
    CField();
    ~CField() override;


public:
    virtual void	Initialize() override;
    virtual void	Update()	override;
    virtual void	Release()	override;
    virtual void	Render()	override;
};

