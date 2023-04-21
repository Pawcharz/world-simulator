#include "Organism.h"
#include <fstream>

using namespace std;

Organism::Organism(): age(0) {
	position = new Point2D(0, 0);

	species = UNKNOWN;
	visual = 'O';

	state = ALIVE;
}

Organism::Organism(Point2D& initialPosition) : age(0) {
	position = new Point2D(initialPosition);

	species = UNKNOWN;
	visual = 'O';

	state = ALIVE;
}


void Organism::Action() {
	cout << "BASE CLASS ACTION" << endl;
}

void Organism::Collision(Organism* foundOrganism) {
	cout << "BASE CLASS COLLISION" << endl;
}

DEFENCE_RESULT Organism::Defend(Organism* attacker) {
	if (attacker->GetStrength() >= strength) {
		return TARGET_KILLED;
	}
	return ATTACKER_KILLED;
}


void Organism::SetStrength(int newStrength) {
	strength = newStrength;
}

int Organism::GetStrength() {
	return strength;
}


void Organism::SetInitiative(int newInitiative) {
	initiative = newInitiative;
}

int Organism::GetInitiative() {
	return initiative;
}


void Organism::SetSpecies(ORGANISM_SPECIES newSpecies) {
	species = newSpecies;
}

ORGANISM_SPECIES Organism::GetSpecies() {
	return species;
}


void Organism::SetVisual(char newVisual) {
	visual = newVisual;
}

char Organism::GetVisual() {
	return visual;
}


void Organism::SetPosition(Point2D& newPosition) {
	//delete position;
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

string& parseIntToString(int inputValue) {
	char* buffer = parseIntToChar(inputValue);
	string* res = new string(buffer);
	return *res;
}

string Organism::GetDescribtion() {
	string description = "";

	switch (species)
	{
	case(HUMAN):
		description += "Human";
		break;
	case(WOLF):
		description += "Wolf";
		break;
	case(SHEEP):
		description += "Sheep";
		break;
	case(FOX):
		description += "Fox";
		break;
	case(TURTLE):
		description += "Turtle";
		break;
	case(ANTILOPE):
		description += "Antilope";
		break;
	case(CYBER_SHEEP):
		description += "Cyber Sheep";
		break;
	case(GRASS):
		description += "Grass";
		break;
	case(SOW_THISTLE):
		description += "Sow Thistle";
		break;
	case(GUARANA):
		description += "Guarana";
		break;
	case(BELLADONNA):
		description += "Belladonna";
		break;
	case(SOSNOWSKYS_HOGWEED):
		description += "Sosnowsky's Hogweed";
		break;
	case(UNKNOWN):
		description += "Unknown Organism";
		break;
	default:
		break;
	}

	description += " at position (";
	description += parseIntToString(position->x);
	description += ", ";
	description += parseIntToString(position->y);
	description += ")";

	return description;
}