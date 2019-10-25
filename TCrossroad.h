//---------------------------------------------------------------------------
#include <vector>
#include "TRoad.h"
#ifndef TCrossroadH
#define TCrossroadH
//---------------------------------------------------------------------------
class TCrossroad {
public:
	int ID;
	int x, y;
	std::vector<TCrossroad*> connetions;
	TCrossroad(int ID, int x, int y);
	TCrossroad();
};
#endif
