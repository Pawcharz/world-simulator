#include "Fox.h"
#include "World.h"

Fox::Fox() {

	strength = 3;
	initiative = 7;

	visual = 'F';
}

vector<Point2D>* Fox::GetPositionsToMove() {
	World* world = World::GetInstance();

	vector<Point2D>* positions = world->GetNeighbouringFields(*position);
	int positionsCount = positions->size();

	vector<Point2D>* available = new vector<Point2D>();

	for (int i = 0; i < positionsCount; i++)
	{
		Point2D neighbouringPosition = (*positions)[i];
		Organism* organism = world->GetOrganismAtPosition(neighbouringPosition);

		if (organism == nullptr) {
			available->push_back(neighbouringPosition);
		}
		else if (organism->GetStrength() <= strength) {
			available->push_back(neighbouringPosition);
		}
	}

	return available;
}
