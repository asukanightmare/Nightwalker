//---------------------------------------------------------------------------

#ifndef TRoadH
#define TRoadH
#include "TCrossroad.h"
//---------------------------------------------------------------------------
class TRoad {
public:
	int ID_A;
	int ID_B;
	double length;
	TCrossroad* CR_A;
	TCrossroad* CR_B;
	TRoad(int a, int b, TCrossroad* _CR_A, TCrossroad* _CR_B);
	TRoad(int a, int b);
	TRoad();
	double angle;
	bool operator==(TRoad* left, TRoad* right);
private:
	void set_angle();
};
#endif
