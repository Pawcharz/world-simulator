#pragma once
#include "utlis.h"
#include "Organism.h"

using namespace std;

class Animal: public Organism
{
protected:
	void Attack(Organism* target);

	void Multiplication();

	void Collision(Organism* target);

public:
	Animal();

	void Movement();

	void Action();
};

