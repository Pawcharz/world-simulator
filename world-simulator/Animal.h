#pragma once
#include "utlis.h"
#include "Organism.h"

using namespace std;

class Animal: public Organism
{
//protected:
public:
	Animal();

	void Movement();

	void Multiplication();

	void Action();
};

