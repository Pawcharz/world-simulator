#pragma once
#include <iostream>

#include "Point2D.h"

using namespace std;

enum ORGANISM_STATE {
	DEAD,
	ALIVE
};
class Organism
{
protected:
	int strength;
	int initiative;

	int age;

	Point2D* position;

	char visual;

	ORGANISM_STATE state;

public:

	Organism();

	Organism(Point2D& initialPosition);

	virtual void Action();

	// Always running for the organism entering field
	virtual void Collision(Organism* foundOrganism);

	virtual bool Defend(Organism* attacker);

	// Always running for the organism in which field other organism entered
	//virtual void ReactToCollision(Organism* enteringOrganism);

	virtual char GetVisual();

	void SetStrength(int newStrength);

	int GetStrength();

	int GetInitiative();


	void SetPosition(Point2D& vector);

	Point2D& GetPosition();


	void SetState(ORGANISM_STATE newState);

	ORGANISM_STATE GetState();


	void SetAge(int newAge);

	int GetAge();
};

