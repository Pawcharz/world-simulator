#include "Antilope.h"
#include "World.h"

const int ANTILOPE_ESCAPE_CHANCE = 0.5;

Antilope::Antilope() {

	strength = 4;
	initiative = 4;

	species = ANTILOPE;
	visual = '&';
}

void Antilope::Attack(Organism* target) {
	World* world = World::GetInstance();

	DEFENCE_RESULT result = target->Defend(this);

	if (result == TARGET_KILLED) {
		position = new Point2D(target->GetPosition());
		world->KillOrganism(target);
	}
	else if (result == ATTACKER_KILLED) {
		DEFENCE_RESULT result = target->Defend(this);
		float random = randomNumber();

		if (random > ANTILOPE_ESCAPE_CHANCE) {
			world->KillOrganism(this);
		}
	}
	else if (result == TARGET_ESCAPED) {

		vector<Point2D>* availablePositions = world->GetNeighbouringFields(target->GetPosition());
		int positionsCount = availablePositions->size();

		if (positionsCount == 0) {
			position = new Point2D(target->GetPosition());
			world->KillOrganism(target);

			return;
		}

		int index = randomInteger(0, positionsCount);

		target->SetPosition(target->GetPosition());
	}
}

DEFENCE_RESULT Antilope::Defend(Organism* attacker) {
	float random = randomNumber();

	if (random > ANTILOPE_ESCAPE_CHANCE) {
		return Animal::Defend(attacker);
	}

	return TARGET_ESCAPED;
}

vector<Point2D>* Antilope::GetPositionsToMove() {
	World* world = World::GetInstance();

	vector<Point2D>* positions = world->GetFieldsAtRadius(*position, 2);

	return positions;
}