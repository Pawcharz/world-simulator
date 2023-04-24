#pragma once
#include "Animal.h"

class Wolf : public Animal
{
protected:

	void Breed(Animal* partner);
	
public:
	Wolf();

	//~Wolf();
};

