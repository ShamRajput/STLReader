#pragma once
class Point
{
public:
	Point(double inX,double inY,double inZ);
	Point(double inXYZ[3]);
private:
	double mX;
	double mY;
	double mZ;
};

