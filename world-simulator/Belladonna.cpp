#include "Belladonna.h"
#include "World.h"

Belladonna::Belladonna() {

	strength = 99;

	species = BELLADONNA;
	visual = 'B';
}

void Belladonna::Spread() {
	Point2D* spreadPosition = GetSpreadPosition();
	if (spreadPosition != nullptr) {
		World* world = World::GetInstance();

		Belladonna* newPlant = new Belladonna();
		newPlant->SetPosition(*spreadPosition);
		world->GetOrganisms()->push_back(newPlant);

		Displayer* diplayer = world->GetDisplayer();
		diplayer->AddLog(GetDescribtion() + " spread creating new " + newPlant->GetDescribtion());
	}
}