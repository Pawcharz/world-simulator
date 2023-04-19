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
	Displayer* displayer = world->GetDisplayer();

	Point2D targetPosition = target->GetPosition();

	DEFENCE_RESULT result = target->Defend(this);

	if (result == TARGET_KILLED) {
		displayer->AddLog(GetDescribtion() + " killed " + target->GetDescribtion());

		position = new Point2D(targetPosition);
		world->KillOrganism(target);
	}
	else if (result == ATTACKER_KILLED) {

		float random = randomNumber();
		if (random <= ANTILOPE_ESCAPE_CHANCE) {

			bool escapeSuccess = EscapeFromFight(*position);

			if (escapeSuccess) {
				displayer->AddLog(GetDescribtion() + " attacked and escaped from " + target->GetDescribtion());
			}
			else {
				displayer->AddLog(target->GetDescribtion() + " killed " + GetDescribtion());
				world->KillOrganism(this);
			}
		}
		else {
			displayer->AddLog(target->GetDescribtion() + " killed " + GetDescribtion());
			world->KillOrganism(this);
		}
	}
	else if (result == TARGET_ESCAPED) {
		displayer->AddLog(target->GetDescribtion() + " escaped from " + GetDescribtion());
		position = new Point2D(targetPosition);
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

void Antilope::Breed(Animal* partner) {
	World* world = World::GetInstance();
	Point2D* breedPosition = partner->GetBreedPosition(partner->GetPosition());

	if (breedPosition == nullptr) {
		return;
	}

	Antilope* child = new Antilope();
	child->SetPosition(*breedPosition);
	world->GetOrganisms()->push_back(child);

	Displayer* displayer = world->GetDisplayer();
	displayer->AddLog(GetDescribtion() + " and " + partner->GetDescribtion() + " born the new " + child->GetDescribtion());
}