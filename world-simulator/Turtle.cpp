#include "Turtle.h"
#include "World.h"

const float TURTLE_MOVE_CHANCE = 0.25;
const int TURTLE_REFLECT_MAX_STRENGTH = 4;

Turtle::Turtle() {

	strength = 3;
	initiative = 7;

	visual = '@';
}

void Turtle::Movement() {
	float random = randomNumber();

	if (random <= TURTLE_MOVE_CHANCE) {
		Animal::Movement();
	}
}

DEFENCE_RESULT Turtle::Defend(Organism* attacker) {
	int attackerStength = attacker->GetStrength();

	if (attackerStength < strength) {
		return ATTACKER_KILLED;
	}
	else if (attackerStength <= TURTLE_REFLECT_MAX_STRENGTH) {
		return REFLECTED;
	}

	return TARGET_KILLED;
}