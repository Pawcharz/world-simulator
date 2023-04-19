#include "Grass.h"
#include "World.h"

Grass::Grass() {

	strength = 0;

	species = GRASS;
	visual = 'G';
}

void Grass::Spread() {
	Point2D* spreadPosition = GetSpreadPosition();
	if (spreadPosition != nullptr) {
		World* world = World::GetInstance();

		Grass* newPlant = new Grass();
		newPlant->SetPosition(*spreadPosition);
		world->GetOrganisms()->push_back(newPlant);

		Displayer* diplayer = world->GetDisplayer();
		diplayer->AddLog(GetDescribtion() + " spread creating new " + newPlant->GetDescribtion());
	}
}