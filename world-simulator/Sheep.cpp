#include "Sheep.h"
#include "World.h"

Sheep::Sheep() {

	strength = 4;
	initiative = 4;

	species = SHEEP;
	visual = 'S';
}

void Sheep::Breed(Animal* partner) {
	World* world = World::GetInstance();
	Point2D* breedPosition = partner->GetBreedPosition(partner->GetPosition());

	if (breedPosition == nullptr) {
		return;
	}

	Sheep* child = new Sheep();
	child->SetPosition(*breedPosition);
	world->GetOrganisms()->push_back(child);
}