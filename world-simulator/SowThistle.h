#pragma once
#include "Plant.h"

class SowThistle: public Plant
{

public:
	SowThistle();

	~SowThistle();

	void Spread() override;
};

