#include "Wolf.h"
#include "World.h"

Wolf::Wolf() {

	strength = 9;
	initiative = 5;

	species = WOLF;
	visual = 'W';
}

void Wolf::Breed(Animal* partner) {
	World* world = World::GetInstance();
	Point2D* breedPosition = partner->GetBreedPosition(partner->GetPosition());

	if (breedPosition == nullptr) {
		return;
	}

	Wolf* child = new Wolf();
	child->SetPosition(*breedPosition);
	world->GetOrganisms()->push_back(child);
}