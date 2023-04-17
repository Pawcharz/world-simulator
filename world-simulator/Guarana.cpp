#include "Guarana.h"
#include "World.h"

Guarana::Guarana() {
	Plant::Plant();

	strength = 0;

	visual = 'R';
}


DEFENCE_RESULT Guarana::Defend(Organism* attacker) {
	if (attacker->GetStrength() >= strength) {
		int attackerStrength = attacker->GetStrength();
		attacker->SetStrength(attackerStrength + 3);
		return TARGET_KILLED;
	}
	return ATTACKER_KILLED;
}

void Guarana::Spread() {
	Point2D* spreadPosition = GetSpreadPosition();
	if (spreadPosition != nullptr) {
		World* world = World::GetInstance();

		Guarana* newPlant = new Guarana();
		newPlant->SetPosition(*spreadPosition);
		world->GetOrganisms()->push_back(newPlant);
	}
}