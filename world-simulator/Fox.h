#pragma once
#include "Animal.h"

class Fox : public Animal
{
protected:

	vector<Point2D>* GetPositionsToMove();

public:
	Fox();

	~Fox();
};


