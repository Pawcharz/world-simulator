#include "Organism.h"

Organism::Organism(): age(0) {
	position = new Point2D(0, 0);

	visual = 'O';

	state = ALIVE;
}

void Organism::Action() {
	cout << "BASE CLASS ACTION" << endl;;
}

void Organism::Collision(Organism* foundOrganism) {
	cout << "BASE CLASS COLLISION" << endl;
}


int Organism::GetStrength() {
	return strength;
}

int Organism::GetInitiative() {
	return initiative;
}

char Organism::GetVisual() {
	return visual;
}


void Organism::SetPosition(Point2D& newPosition) {
	*position = newPosition;
}

Point2D& Organism::GetPosition() {
	return *position;
}


void Organism::SetState(ORGANISM_STATE newState) {
	state = newState;
}

ORGANISM_STATE Organism::GetState() {
	return state;
}


void Organism::SetAge(int newAge) {
	age = newAge;
}

int Organism::GetAge() {
	return age;
}