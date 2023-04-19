#include "Fox.h"
#include "World.h"

Fox::Fox() {

	strength = 3;
	initiative = 7;

	species = FOX;
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

void Fox::Breed(Animal* partner) {
	World* world = World::GetInstance();
	Point2D* breedPosition = partner->GetBreedPosition(partner->GetPosition());

	if (breedPosition == nullptr) {
		return;
	}

	Fox* child = new Fox();
	child->SetPosition(*breedPosition);
	world->GetOrganisms()->push_back(child);

	Displayer* displayer = world->GetDisplayer();
	displayer->AddLog(GetDescribtion() + " and " + partner->GetDescribtion() + " born the new " + child->GetDescribtion());
}