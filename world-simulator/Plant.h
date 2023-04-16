#pragma once

#include "utlis.h"
#include "Organism.h"

using namespace std;

class Plant : public Organism
{
protected:

	void Sow();

	bool virtual Defend(Organism* attacker);

	Point2D* GetSpreadPosition();
public:
	Plant();
	Plant(Point2D& initialPosition);

	//~Plant();

	void virtual Spread();

	void Action();
};

