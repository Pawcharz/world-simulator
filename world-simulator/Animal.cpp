#include "Animal.h"
#include "World.h"

using namespace std;

Animal::Animal() {

	visual = 'A';
}



void Animal::Movement() {
	World* world = World::GetInstance();

	vector<Point2D>* positions = world->GetNeighbouringFields(*position);

	int index = randomInteger(0, positions->size());

	//*position = positions[index];
	Point2D newPosition = (*positions)[index];

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

	bool defended = target->Defend(this);
	
	if (!defended) {
		position = new Point2D(target->GetPosition());
		world->KillOrganism(target);
	}
	else {
		world->KillOrganism(this);
	}
}

bool Animal::Defend(Organism* attacker) {
	return Organism::Defend(attacker);
}

void Animal::Action() {
	Movement();
}