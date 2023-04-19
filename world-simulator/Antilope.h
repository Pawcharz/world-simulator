#pragma once
#include "Animal.h"

class Antilope : public Animal
{
private:

	void Breed(Animal* partner);

	bool EscapeFromFight(Point2D& targetPosition);

protected:

	void Attack(Organism* target);

	DEFENCE_RESULT Defend(Organism* attacker);

	vector<Point2D>* GetPositionsToMove();

public:
	Antilope();

	~Antilope();
};