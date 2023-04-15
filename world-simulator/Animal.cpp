#include "Animal.h"
#include "World.h"

using namespace std;

Animal::Animal() {
	//Organism::Organism();
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

	if (strength >= target->GetStrength()) {
		world->KillOrganism(target);
	}
	else {
		position = new Point2D(target->GetPosition());
		world->KillOrganism(this);
	}
}

void Animal::Action() {
	Movement();
}