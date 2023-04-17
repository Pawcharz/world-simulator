#pragma once
#include "Plant.h"

class Guarana : public Plant
{
	DEFENCE_RESULT Defend(Organism* attacker);

public:
	Guarana();

	~Guarana();

	void Spread();
};


