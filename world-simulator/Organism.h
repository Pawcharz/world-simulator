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

	virtual void Action();

	virtual void Collision(Organism* foundOrganism);



	virtual char GetVisual();

	int GetStrength();

	int GetInitiative();


	void SetPosition(Point2D& vector);

	Point2D& GetPosition();


	void SetState(ORGANISM_STATE newState);

	ORGANISM_STATE GetState();


	void SetAge(int newAge);

	int GetAge();
};

