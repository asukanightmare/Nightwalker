//---------------------------------------------------------------------------

#ifndef TEnitymapH
#define TEnitymapH
#include <vector>
#include <math.h>
#include "TEnity.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TEnitymap {

public:
	std::vector<TEnity*> listEnity;
	std::vector<TCrossroad*>* listCrossroad;
	TCanvas* dest;
	int tickDelay;

	void drawEnities();
	void drawEnity(TEnity* enity);
	void calcEnity(TEnity* enity);
	void createEnity(TRoad* road, double position, bool direction);

	TEnitymap(TCanvas* dest);
	~TEnitymap();
};
#endif
