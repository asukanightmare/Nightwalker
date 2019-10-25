//---------------------------------------------------------------------------

#ifndef TRoadmapH
#define TRoadmapH
#include <vector>
#include <deque>
#include "TCrossroad.h"
#include "TRoad.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TRoadmap {

public:
	TMemo* log;
	std::vector<TCrossroad*> listCrossroad;
	std::vector<TRoad*> listRoad;

	void traceRoads();
	void drawRoads(TCanvas* dest);
	void drawCrossroads(TCanvas* dest);
	void addConnection(TRoad* road);
	void addConnection(int ID_A, int ID_B);
	bool existRoad(TRoad road);
	bool existRoad(int ID_A, int ID_B);
	void addCrossroad(int x, int y);
	void fillRand();
	TRoadmap(TMemo* logDest);
	~TRoadmap();
};
#endif
