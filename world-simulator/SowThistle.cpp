#include "SowThistle.h"
#include "World.h"

SowThistle::SowThistle() {

	strength = 0;

	species = SOW_THISTLE;
	visual = 'T';
}

void SowThistle::Spread() {

	for (int i = 0; i < 3; i++)
	{
		Plant::Spread();
	}
}
