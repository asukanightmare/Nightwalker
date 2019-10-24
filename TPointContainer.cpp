//---------------------------------------------------------------------------


#pragma hdrstop

#include "TPointContainer.h"
#include "TCrossroad.h"
#include "TRoad.h"
#include <deque>
//---------------------------------------------------------------------------
TPointContainer::TPointContainer(TMemo* logDest) {
	this->log = logDest;
}
void TPointContainer::drawRoads(TCanvas* dest) {
	for(int i = 0; listRoad.size() > i; i++) {
		dest->MoveTo(listCrossroad[listRoad[i].ID_A].x, listCrossroad[listRoad[i].ID_A].y);
		dest->LineTo(listCrossroad[listRoad[i].ID_B].x, listCrossroad[listRoad[i].ID_B].y) ;
	}
}
void TPointContainer::addConnection(TRoad road) {
	listRoad.push_back(road);
}
void TPointContainer::addConnection(int ID_A, int ID_B) {
	addConnection(TRoad(ID_A, ID_B));
}
void TPointContainer::addCrossroad(int x, int y) {
	listCrossroad.push_back(TCrossroad(listCrossroad.size(), x, y));
}
bool TPointContainer::existRoad(TRoad road) {
	for(int h = 0; listRoad.size() > h; h++) {
		if((listRoad[h].ID_A == road.ID_A && listRoad[h].ID_B == road.ID_B) ||
		 (listRoad[h].ID_A == road.ID_A && listRoad[h].ID_B == road.ID_B)) return true;
	}
	return false;
}
bool TPointContainer::existRoad(int ID_A, int ID_B) {
	existRoad(TRoad(ID_A, ID_B));
}
void TPointContainer::drawCrossroads(TCanvas* dest) {
	for(int i = 0; listCrossroad.size() > i; i++) {
		dest->TextOutA(listCrossroad[i].x,listCrossroad[i].y, UnicodeString(listCrossroad[i].ID));
	}
}
void TPointContainer::traceRoads() {
	for(int i = 0; listCrossroad.size() > i; i++) {
		for(int k = 0; listCrossroad[i].connetions.size() > k; k++) {
			if(!existRoad(listCrossroad[i].ID, listCrossroad[i].connetions[k]->ID))
				addConnection(listCrossroad[i].ID, listCrossroad[i].connetions[k]->ID);
		}
	}
}
void TPointContainer::fillRand() {
	for(int i = 0; i < 8; i++) {
		int _x = (1+rand()%5)*60, _y = (1+rand()%5)*60;
		addCrossroad(_x,_y);
	}
	listCrossroad[0].connetions.push_back(&listCrossroad[1]);
	listCrossroad[1].connetions.push_back(&listCrossroad[2]);
	listCrossroad[2].connetions.push_back(&listCrossroad[3]);
	listCrossroad[3].connetions.push_back(&listCrossroad[4]);
	listCrossroad[4].connetions.push_back(&listCrossroad[1]);
	listCrossroad[4].connetions.push_back(&listCrossroad[5]);
	listCrossroad[5].connetions.push_back(&listCrossroad[0]);
	listCrossroad[5].connetions.push_back(&listCrossroad[6]);
	listCrossroad[6].connetions.push_back(&listCrossroad[7]);
	listCrossroad[7].connetions.push_back(&listCrossroad[3]);
}


#pragma package(smart_init)
