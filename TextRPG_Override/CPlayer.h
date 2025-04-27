#pragma once
#include "CCharacter.h"
class CPlayer :
    public CCharacter
{
public:
    CPlayer();
    ~CPlayer() override;

    //�ϴ� ����ν� �÷��̾�Ŭ���� ���������� ������ ����̾�����,
    //�ڷ����� Ȯ�强�� ���ؼ� CPlayer Ŭ������ �����Ѵ�.
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

