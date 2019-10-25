//---------------------------------------------------------------------------


#pragma hdrstop

#include "TEnity.h"

#include <math.h>

//---------------------------------------------------------------------------
double TEnity::getX() {
	return position*cos(this->road->angle)+this->road->CR_A->x;
}
double TEnity::getY() {
	return position*sin(this->road->angle)+this->road->CR_A->y;
}
void TEnity::move(double distance){
	if(position + distance*(direction ? 1.0 : -1.0) >= this->road->length) {
		position = this->road->length;
	}
	else if(position + distance*(direction ? 1.0 : -1.0) <= 0) {
		position = 0;
	}
	else position += distance*(direction ? 1 : -1);
}


#pragma package(smart_init)
