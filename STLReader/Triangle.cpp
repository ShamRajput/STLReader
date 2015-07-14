#include "Triangle.h"





Triangle::Triangle(int inIndexV1, int inIndexV2, int inIndexV3)
{
	mIndices->assign(inIndexV1);
	mIndices->assign(inIndexV2);
	mIndices->assign(inIndexV3);
}


