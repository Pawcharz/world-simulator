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

	virtual bool Defend(Organism* attacker);


public:
	Animal();

	//~Animal();

	void Movement();

	void Action();
};

