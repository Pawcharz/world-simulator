#pragma once

#include "utlis.h"
#include "Organism.h"

using namespace std;

class Plant : public Organism
{
protected:

	void Sow();

	virtual DEFENCE_RESULT Defend(Organism* attacker);

	Point2D* GetSpreadPosition();
public:
	Plant();
	Plant(Point2D& initialPosition);

	//~Plant();

	virtual void Spread();

	void Action();
};

