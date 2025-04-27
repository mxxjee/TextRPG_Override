#pragma once
#include "Define.h"

/*��� �ڷ����� �ֻ��� Ŭ���� 
// ����������Ŭ [Intialize(),Update(),Release(),Render()]�� ����� ����*/
class CObj
{

public:
	CObj();
	virtual ~CObj();

public:
	virtual void	Initialize() PURE;
	virtual void	Update()	PURE;
	virtual void	Release()	PURE;
	virtual void	Render()	PURE;

};

