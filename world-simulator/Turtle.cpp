#include "Turtle.h"
#include "World.h"

const float TURTLE_MOVE_CHANCE = 0.25;
const int TURTLE_REFLECT_MAX_STRENGTH = 4;

Turtle::Turtle() {

	strength = 3;
	initiative = 7;

	species = TURTLE;
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

void Turtle::Breed(Animal* partner) {
	World* world = World::GetInstance();
	Point2D* breedPosition = partner->GetBreedPosition(partner->GetPosition());

	if (breedPosition == nullptr) {
		return;
	}

	Turtle* child = new Turtle();
	child->SetPosition(*breedPosition);
	world->GetOrganisms()->push_back(child);
}