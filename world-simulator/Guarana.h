#pragma once
#include "Plant.h"

class Guarana : public Plant
{
	bool Defend(Organism* attacker);

public:
	Guarana();

	~Guarana();
};


