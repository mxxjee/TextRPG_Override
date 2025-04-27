#pragma once

#define		PURE =0
#define		SAFEDELETE(p) {if(p) delete p;p=nullptr;}
#define		SAFEDELETE_ARR(p) {if(p) delete[] p;p=nullptr;}

#define		MAXSTR 32
#define		SHOP_ITEM_COUNT 3
