#include "Guarana.h"
#include "World.h"

Guarana::Guarana() {
	Plant::Plant();

	strength = 0;

	visual = 'R';
}


bool Guarana::Defend(Organism* attacker) {
	if (attacker->GetStrength() >= strength) {
		int attackerStrength = attacker->GetStrength();
		attacker->SetStrength(attackerStrength + 3);
		return false;
	}
	return true;
}
