#pragma once
#include <iostream>

#include "Point2D.h"

using namespace std;

enum DEFENCE_RESULT {
	TARGET_KILLED,
	ATTACKER_KILLED,
	REFLECTED,
	TARGET_ESCAPED
};

enum ORGANISM_STATE {
	DEAD,
	ALIVE
};

enum ORGANISM_SPECIES {
	HUMAN,

	WOLF,
	SHEEP,
	FOX,
	TURTLE,
	ANTILOPE,
	CYBER_SHEEP,

	GRASS,
	SOW_THISTLE,
	GUARANA,
	BELLADONNA,
	SOSNOWSKYS_HOGWEED,

	UNKNOWN
};


class Organism
{
protected:
	int strength;
	int initiative;

	int age;

	Point2D* position;

	ORGANISM_SPECIES species;
	char visual;

	ORGANISM_STATE state;

public:

	Organism();

	~Organism();

	Organism(Point2D& initialPosition);

	virtual void Action() = 0;

	virtual DEFENCE_RESULT Defend(Organism* attacker);

	void SetSpecies(ORGANISM_SPECIES newSpecies);

	ORGANISM_SPECIES GetSpecies();


	void SetVisual(char newVisual);

	virtual char GetVisual();


	void SetStrength(int newStrength);

	int GetStrength();


	void SetInitiative(int newInitiative);

	int GetInitiative();


	void SetPosition(Point2D& vector);

	Point2D& GetPosition();


	void SetState(ORGANISM_STATE newState);

	ORGANISM_STATE GetState();


	void SetAge(int newAge);

	int GetAge();


	string GetDescribtion();

};

