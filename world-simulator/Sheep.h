#pragma once
#include "Animal.h"

class Sheep : public Animal
{
protected:

	void Breed(Animal* partner);

public:
	Sheep();

	//~Sheep();

	//void Movement();
};

