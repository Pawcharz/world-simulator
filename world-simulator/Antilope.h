#pragma once
#include "Animal.h"

class Antilope : public Animal
{
private:

	bool EscapeFromFight(Point2D& targetPosition);

protected:

	void Attack(Organism* target);

	DEFENCE_RESULT Defend(Organism* attacker);

	vector<Point2D>* GetPositionsToMove();

public:
	Antilope();

	~Antilope();
};