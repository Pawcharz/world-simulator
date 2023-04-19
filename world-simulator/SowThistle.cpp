#include "SowThistle.h"
#include "World.h"

SowThistle::SowThistle() {

	strength = 0;

	species = SOW_THISTLE;
	visual = 'T';
}

void SowThistle::Spread() {

	World* world = World::GetInstance();
	for (int i = 0; i < 3; i++)
	{
		Point2D* spreadPosition = GetSpreadPosition();

		if (spreadPosition == nullptr) {
			return;
		}

		SowThistle* newPlant = new SowThistle();
		newPlant->SetPosition(*spreadPosition);
		world->GetOrganisms()->push_back(newPlant);

		Displayer* diplayer = world->GetDisplayer();
		diplayer->AddLog(GetDescribtion() + " spread creating new " + newPlant->GetDescribtion());
	}
}
