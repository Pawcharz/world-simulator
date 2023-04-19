#include "SosnowskysHogweed.h"
#include "World.h"

SosnowskysHogweed::SosnowskysHogweed() {

	strength = 10;

	species = SOSNOWSKYS_HOGWEED;
	visual = 'H';
}

void SosnowskysHogweed::Action() {
	World* world = World::GetInstance();

	vector<Point2D>* neighbourhood = world->GetNeighbouringFields(*position);

	for (int i = 0; i < neighbourhood->size(); i++)
	{
		Point2D pos = (*neighbourhood)[i];

		Organism* organism = world->GetOrganismAtPosition(pos);

		if (organism != nullptr) {

			if (organism->GetSpecies() != CYBER_SHEEP) {
				world->KillOrganism(organism);
			}
		}
	}
}

DEFENCE_RESULT SosnowskysHogweed::Defend(Organism* attacker) {
	if (attacker->GetSpecies() != CYBER_SHEEP) {
		World* world = World::GetInstance();

		world->KillOrganism(attacker);
		return ATTACKER_KILLED;
	}
}