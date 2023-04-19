#pragma once
#include "utlis.h"
#include "Organism.h"

using namespace std;

class Animal: public Organism
{
protected:

	virtual vector<Point2D>* GetPositionsToMove();

	virtual void Collision(Organism* target);

	virtual void Attack(Organism* target);

	virtual DEFENCE_RESULT Defend(Organism* attacker);


public:
	Animal();

	//~Animal();

	virtual void Movement();

	virtual void Action();
};

