#pragma once

#include "Animal.h"

class Turtle : public Animal
{
protected:

	void Breed(Animal* partner);

	DEFENCE_RESULT Defend(Organism* attacker);

public:
	Turtle();

	~Turtle();

	void Movement();
};


