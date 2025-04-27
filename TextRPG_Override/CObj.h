#pragma once
#include "Define.h"

/*모든 자료형의 최상위 클래스 
// 라이프사이클 [Intialize(),Update(),Release(),Render()]의 기능을 제공*/
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

