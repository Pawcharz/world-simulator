#pragma once
#include "Animal.h"

class Fox : public Animal
{
protected:

	void Breed(Animal* partner);

	vector<Point2D>* GetPositionsToMove();

public:
	Fox();

	~Fox();
};


