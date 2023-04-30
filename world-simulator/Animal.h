#pragma once
#include "utlis.h"
#include "Organism.h"

using namespace std;

class Animal: public Organism
{
protected:

	virtual vector<Point2D>* GetPositionsToMove();


	virtual void Collision(Organism* target);



	virtual void Breed(Animal* partner);


	virtual void Attack(Organism* target);

	virtual DEFENCE_RESULT Defend(Organism* attacker);


public:
	Animal();

	//~Animal();

	Point2D* GetBreedPosition(Point2D& partnerPosition);

	virtual void Movement();

	virtual void Action();
};

