#pragma once
#include "Point.h"
#include <array>
typedef std::array<int,3> Indices;

class Triangle
{
public:
	Triangle(int inIndexV1, int inIndexV2, int inIndexV3);
private:
	enum { size=3};
	Indices mIndices[size];
};

