//---------------------------------------------------------------------------


#pragma hdrstop
#define PI 3.141592653
#include "TRoad.h"
#include <math.h>
//---------------------------------------------------------------------------
TRoad::TRoad(int a, int b, TCrossroad* _CR_A, TCrossroad* _CR_B) {
   this->ID_A = a;
   this->ID_B = b;
   this->CR_A = _CR_A;
   this->CR_B = _CR_B;
   this->length = sqrt(pow(_CR_A->x - _CR_B->x,2)+ pow(_CR_A->y - _CR_B->y,2));
   set_angle();
}
TRoad::TRoad(int a, int b) { //pseudo
   this->ID_A = a;
   this->ID_B = b;
}
TRoad::TRoad() {
   this->ID_A = -1;
   this->ID_B = -1;
   CR_A = NULL;
   CR_B = NULL;
}
void TRoad::set_angle() {
	int x1 = CR_A->x;
	int x2 = CR_B->x;
	int y1 = CR_A->y;
	int y2 = CR_B->y;

	double dx = (double)(x2 - x1);
	double dy = (double)(y2 - y1);

	if((dx > 0.0 && dy > 0.0) || (dx > 0.0 && dy < 0.0)) angle = atan(dy/dx);
	else if(dx < 0.0 && dy > 0.0) angle = atan(dy/dx) + PI;
	else if(dx < 0.0 && dy < 0.0) angle = atan(dy/dx) - PI;
	else if(dx == 0.0) angle = PI/2.0;
	else if(dy == 0.0) angle = 0;
}
#pragma package(smart_init)
