//---------------------------------------------------------------------------


#pragma hdrstop

#include "TRoadmap.h"
#include "TCrossroad.h"
#include "TRoad.h"
#include <math.h>
#include <Math.hpp>
#include <deque>
#define PI 3.141592653
#define _log(x) log->Lines->Add(x)
#define US(x) UnicodeString(x)
//---------------------------------------------------------------------------
inline void Line(int x1, int y1, int x2, int y2, TCanvas* dest) {
	dest->MoveTo(x1, y1);
	dest->LineTo(x2, y2);
}
TRoadmap::TRoadmap(TMemo* logDest) {
	this->log = logDest;
}
TRoadmap::~TRoadmap() {
	for(int i = 0; i < this->listRoad.size(); i++) delete this->listRoad[i]
	for(int i = 0; i < this->listCrossroad.size(); i++) delete this->listCrossroad[i];
}
void TRoadmap::drawRoads(TCanvas* dest) {
	for(int i = 0; listRoad.size() > i; i++) {
		int x1 = listRoad[i]->CR_A->x;
		int x2 = listRoad[i]->CR_B->x;
		int y1 = listRoad[i]->CR_A->y;
		int y2 = listRoad[i]->CR_B->y;

		double dx = (double)(x2 - x1);
		double dy = (double)(y2 - y1);
		double radius = 7;
		Line(x1, y1, x2, y2, dest);
/*
    		//dest->Pen->Color = clRed;
			 angle;
    		if((dx > 0.0 && dy > 0.0) || (dx > 0.0 && dy < 0.0)) angle = atan(dy/dx);
    		else if(dx < 0.0 && dy > 0.0) angle = atan(dy/dx) + PI;
    		else if(dx < 0.0 && dy < 0.0) angle = atan(dy/dx) - PI;
			else if(dx == 0.0) angle = PI/2.0;
			else if(dy == 0.0) angle = 0;
*/
		_log("Road " + US(listRoad[i]->ID_A) + "->" + US(listRoad[i]->ID_B) + ": " + US((double)SimpleRoundTo(listRoad[i]->angle*180/PI, -3)) + " dx: " + US(dx) + " dy: " + US(dy));

		Line(x1+radius*cos(listRoad[i]->angle - (PI/2.0)),
			y1+radius*sin(listRoad[i]->angle - (PI/2.0)),
				x2+radius*cos(listRoad[i]->angle - (PI/2.0)),
					y2+radius*sin(listRoad[i]->angle - (PI/2.0)), dest);
		Line(x1+radius*cos(listRoad[i]->angle + (PI/2.0)),
			y1+radius*sin(listRoad[i]->angle + (PI/2.0)),
				x2+radius*cos(listRoad[i]->angle + (PI/2.0)),
					y2+radius*sin(listRoad[i]->angle + (PI/2.0)), dest);
		//dest->Pen->Color = clBlack;
	}
}
void TRoadmap::addConnection(TRoad* road) {
	listRoad.push_back(road);
}
void TRoadmap::addConnection(int ID_A, int ID_B) {
	addConnection(new TRoad(ID_A, ID_B, listCrossroad[ID_A], listCrossroad[ID_B]));
}
void TRoadmap::addCrossroad(int x, int y) {
	listCrossroad.push_back(new TCrossroad(listCrossroad.size(), x, y));
}
bool TRoadmap::existRoad(TRoad road) {
	for(int h = 0; listRoad.size() > h; h++) {
		if((listRoad[h]->ID_A == road.ID_A && listRoad[h]->ID_B == road.ID_B) ||
		 (listRoad[h]->ID_A == road.ID_A && listRoad[h]->ID_B == road.ID_B)) return true;
	}
	return false;
}
bool TRoadmap::existRoad(int ID_A, int ID_B) {
	existRoad(TRoad(ID_A, ID_B));
}
void TRoadmap::drawCrossroads(TCanvas* dest) {
	for(int i = 0; listCrossroad.size() > i; i++) {
		dest->TextOutA(listCrossroad[i].x+10,listCrossroad[i].y+10, UnicodeString(listCrossroad[i].ID));
		//dest->Pen->Color = clWhite;
		dest->Ellipse(listCrossroad[i].x-10,listCrossroad[i].y-10, listCrossroad[i].x+11,listCrossroad[i].y+11);
		dest->Pen->Color = clBlack;
	}
}
void TRoadmap::traceRoads() {
	for(int i = 0; listCrossroad.size() > i; i++) {
		for(int k = 0; listCrossroad[i].connetions.size() > k; k++) {
			if(!existRoad(listCrossroad[i].ID, listCrossroad[i].connetions[k]->ID))
				addConnection(listCrossroad[i].ID, listCrossroad[i].connetions[k]->ID);
		}
	}
}
void TRoadmap::fillRand() {
	for(int i = 0; i < 8; i++) {
		int _x = (1+rand()%5)*60, _y = (1+rand()%5)*60;
		addCrossroad(_x,_y);
	}
	listCrossroad[0].connetions.push_back(listCrossroad[1]);
	listCrossroad[1].connetions.push_back(listCrossroad[2]);
	listCrossroad[2].connetions.push_back(listCrossroad[3]);
	listCrossroad[3].connetions.push_back(listCrossroad[4]);
	listCrossroad[4].connetions.push_back(listCrossroad[1]);
	listCrossroad[4].connetions.push_back(listCrossroad[5]);
	listCrossroad[5].connetions.push_back(listCrossroad[0]);
	listCrossroad[5].connetions.push_back(listCrossroad[6]);
	listCrossroad[6].connetions.push_back(listCrossroad[7]);
	listCrossroad[7].connetions.push_back(listCrossroad[3]);
}


#pragma package(smart_init)
