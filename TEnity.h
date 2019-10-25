//---------------------------------------------------------------------------
#include "TRoad.h"
#ifndef TEnityH
#define TEnityH
//---------------------------------------------------------------------------
class TEnity {
	public:
		TRoad* road;
		double position;
		double acceleration;
		double speed;
		bool direction;
		double getX();
		double getY();
		void move(double distance);
};
#endif
