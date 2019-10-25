//---------------------------------------------------------------------------


#pragma hdrstop

#include "TCrossroad.h"

//---------------------------------------------------------------------------
TCrossroad::TCrossroad(int ID, int x, int y) {
	this->ID = ID;
	this->x = x;
	this->y = y;
}
TCrossroad::TCrossroad() {
	this->ID = -1;
	this->x = -1;
	this->y = -1;
}
#pragma package(smart_init)
