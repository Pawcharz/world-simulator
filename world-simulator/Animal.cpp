#include "Animal.h"
#include "World.h"

using namespace std;

Animal::Animal() {

	visual = 'A';
}



vector<Point2D>* Animal::GetPositionsToMove() {
	World* world = World::GetInstance();

	vector<Point2D>* positions = world->GetNeighbouringFields(*position);

	return positions;
}

void Animal::Movement() {

	World* world = World::GetInstance();

	vector<Point2D>* availablePositions = GetPositionsToMove();
	int positionsCount = availablePositions->size();
	if (positionsCount == 0) {
		return;
	}

	int index = randomInteger(0, positionsCount);

	Point2D newPosition = (*availablePositions)[index];

	Organism* foundOrganism = world->GetOrganismAtPosition(newPosition);

	if (foundOrganism != nullptr) {
		Collision(foundOrganism);
	}
	else {
		delete position;
		position = new Point2D(newPosition);
	}
}


void Animal::Collision(Organism* target) {
	// Check if the same type

	Attack(target);
}

void Animal::Attack(Organism* target) {
	World* world = World::GetInstance();

	Point2D targetInitialPosition = target->GetPosition();

	DEFENCE_RESULT result = target->Defend(this);
	
	Displayer* displayer = world->GetDisplayer();


	if (result == TARGET_KILLED) {
		displayer->AddLog(GetDescribtion() + " killed " + target->GetDescribtion());

		position = new Point2D(targetInitialPosition);
		world->KillOrganism(target);
	}
	else if (result == ATTACKER_KILLED) {
		displayer->AddLog(target->GetDescribtion() + " killed " + GetDescribtion());

		world->KillOrganism(this);
	}
	else if (result == TARGET_ESCAPED) {

		// Should probably be impemented in the antilope class
		vector<Point2D>* availablePositions = world->GetNeighbouringFields(targetInitialPosition);
		int positionsCount = availablePositions->size();
		
		if (positionsCount == 0) {
			displayer->AddLog(GetDescribtion() + " killed " + target->GetDescribtion());

			position = new Point2D(target->GetPosition());
			world->KillOrganism(target);

			return;
		}

		position = new Point2D(targetInitialPosition);

		int index = randomInteger(0, positionsCount);

		displayer->AddLog(target->GetDescribtion() + " escaped from attack of " + GetDescribtion());

		target->SetPosition((*availablePositions)[index]);

	}
}

DEFENCE_RESULT Animal::Defend(Organism* attacker) {
	return Organism::Defend(attacker);
}

void Animal::Action() {
	Movement();
}