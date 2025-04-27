#pragma once
#include "CCharacter.h"
class CPlayer :
    public CCharacter
{
public:
    CPlayer();
    ~CPlayer() override;

    //일단 현재로썬 플레이어클래스 독자적으로 가지는 기능이없지만,
    //자료형과 확장성을 위해서 CPlayer 클래스를 생성한다.
public:
    virtual void	Initialize() override;
    virtual void	Initialize(const char* _pName, int _iHp, int _iAttack) override;


    virtual void	Update()	override;
    virtual void	Release()	override;
    virtual void	Render()	override;

public: 
    virtual	void	Save(ofstream& _file) override;
    virtual void	Load(ifstream& _file) override;

//ex)public:
//    void Buy();
};

