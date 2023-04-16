#include "Grass.h"
#include "World.h"

Grass::Grass() {
	Plant::Plant();

	strength = 0;

	visual = 'G';
}

void Grass::Spread() {
	Point2D* spreadPosition = GetSpreadPosition();
	if (spreadPosition != nullptr) {
		World* world = World::GetInstance();

		Grass* newPlant = new Grass();
		newPlant->SetPosition(*spreadPosition);
		world->GetOrganisms()->push_back(newPlant);
	}
}