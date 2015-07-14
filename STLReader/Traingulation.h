#pragma once
#include <array>
#include "Point.h"
#include <map>
#include "Triangle.h"
typedef std::vector<Triangle*> Triangles;
typedef std::map<int,Point> IndexPtTable;
typedef std::map<Point,int> PointIdxTable;


class Traingulation
{

private:
	Triangles mTraingleList;
	IndexPtTable mIndexPtTable;
	PointIdxTable mPointIdxTable;
};

