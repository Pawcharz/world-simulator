#pragma once
#include "utlis.h"
#include "Organism.h"

using namespace std;

class Animal: public Organism
{
protected:

	vector<Point2D>* GetPositionsToMove();

	void Collision(Organism* target);

	void Attack(Organism* target);

	bool virtual Defend(Organism* attacker);


public:
	Animal();

	//~Animal();

	void Movement();

	void Action();
};

