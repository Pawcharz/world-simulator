#include "Animal.h"
#include "World.h"

using namespace std;

Animal::Animal() {
	//Organism::Organism();
}

void Animal::Movement() {
	World* world = World::GetInstance();

	vector<Point2D*>* positions = world->GetNeighbouringFields(*position);

	int index = randomInteger(0, positions->size());

	//*position = positions[index];
	position = positions->at(index);
}