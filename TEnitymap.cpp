//---------------------------------------------------------------------------


#pragma hdrstop

#include "TEnitymap.h"
#define SPEED_LIMIT 5.0
#define RANGE_STOP 50.0

//---------------------------------------------------------------------------
void TEnitymap::drawEnity(TEnity* enity) {
	double x = floor(enity->getX() + 0.5);
	double y = floor(enity->getY() + 0.5);
	dest->Pen->Color = clRed;
	dest->Ellipse(x-4,y-4,x+4,y+4);
	dest->Pen->Color = clBlack;
}
void TEnitymap::drawEnities() {
	for(int i = 0; i < this->listEnity.size(); i++) drawEnity(this->listEnity[i]);
}
TEnitymap::TEnitymap(TCanvas* dest) {
	this->dest = dest;
}
TEnitymap::~TEnitymap() {
	for(int i = 0; i < this->listEnity.size(); i++) delete this->listEnity[i];
}
void TEnitymap::createEnity(TRoad* road, double position, bool direction) {
	TEnity* enity = new TEnity();
	enity->road = road;
	enity->position = position;
	enity->direction = direction;
	this->listEnity.push_back(enity);
}
void TEnitymap::calcEnity(TEnity* enity) {
	for(int i = 0; i < this->listEnity.size(); i++) {
		double range = fabs(listEnity[i]->position - enity->position);
		if(*(listEnity[i]->road) == *(enity->road)
		&& listEnity[i]->direction == enity->direction) {
			//double koeff = (range - 10.0)/(STOP_RANGE) - 1;
			enity->acceleration += range
		}
	}
}
#pragma package(smart_init)
