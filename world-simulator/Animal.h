#pragma once
#include "utlis.h"
#include "Organism.h"

using namespace std;

class Animal: public Organism
{
protected:

	virtual vector<Point2D>* GetPositionsToMove();

	void Collision(Organism* target);

	void Attack(Organism* target);

	virtual DEFENCE_RESULT Defend(Organism* attacker);


public:
	Animal();

	//~Animal();

	virtual void Movement();

	void Action();
};

