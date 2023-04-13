#pragma once
#include "Point2D.h"

class Organism
{
protected:
	int strength;
	int initiative;

	Point2D* position;

	char visual;

public:

	Organism();

	void Action();

	void Collision();

	virtual char GetVisual();


	Point2D& GetPosition();

	void SetPosition(Point2D& vector);
};

