#include "Point.h"



Point::Point(double inX, double inY, double inZ)
	:mX(inX), mY(inY), mZ(inZ)
{

}

Point::Point(double inXYZ[3])
	: mX(inXYZ[0]), mY(inXYZ[1]), mZ(inXYZ[2])
{

}


