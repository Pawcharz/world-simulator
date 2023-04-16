#include "SowThistle.h"
#include "World.h"

SowThistle::SowThistle() {
	Plant::Plant();

	strength = 0;

	visual = 'T';
}

void SowThistle::Spread() {

	for (int i = 0; i < 3; i++)
	{
		Plant::Spread();
	}
}
