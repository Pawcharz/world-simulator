#include "Antilope.h"
#include "World.h"

const int ANTILOPE_ESCAPE_CHANCE = 1;

Antilope::Antilope() {

	strength = 4;
	initiative = 4;

	species = ANTILOPE;
	visual = '&';
}


// Returns bool representing success of escape (will fail if all neighbouring fields are taken)
bool Antilope::EscapeFromFight(Point2D& escapeFrom) {
	World* world = World::GetInstance();
	vector<Point2D>* availablePositions = world->GetNeighbouringFreeFields(escapeFrom);
	int positionsCount = availablePositions->size();

	if (positionsCount == 0) {
		return false;
	}

	int index = randomInteger(0, positionsCount);

	Point2D newPosition = (*availablePositions)[index];

	delete position;
	position = new Point2D(newPosition);
	return true;
}

void Antilope::Attack(Organism* target) {
	World* world = World::GetInstance();

	Point2D targetPosition = target->GetPosition();

	DEFENCE_RESULT result = target->Defend(this);

	if (result == TARGET_KILLED) {
		position = new Point2D(targetPosition);
		world->KillOrganism(target);
	}
	else if (result == ATTACKER_KILLED) {
		world->KillOrganism(this);
	}
	else if (result == TARGET_ESCAPED) {

	}
}

DEFENCE_RESULT Antilope::Defend(Organism* attacker) {
	World* world = World::GetInstance();

	float random = randomNumber();

	if (random > ANTILOPE_ESCAPE_CHANCE) {
		return Animal::Defend(attacker);
	}
	
	// Tries to escape
	bool escapeSuccess = EscapeFromFight(*position);

	if (escapeSuccess) {
		return TARGET_ESCAPED;
	}

	return TARGET_KILLED;
}

vector<Point2D>* Antilope::GetPositionsToMove() {
	World* world = World::GetInstance();

	vector<Point2D>* positions = world->GetFieldsAtRadius(*position, 2);

	return positions;
}