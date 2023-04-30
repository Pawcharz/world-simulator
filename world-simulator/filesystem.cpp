#include "World.h"
#include <fstream>

using namespace std;

struct OrganismBase {
	int strength;
	int initiative;

	int age;

	Point2D* position;

	ORGANISM_SPECIES species;
	char visual;

	ORGANISM_STATE state;
};



// Copies only properties that can vary between instances of the same subclass of Organism
void copyBaseProperties(OrganismBase& base, Organism* target) {

	target->SetStrength(base.strength);
	target->SetInitiative(base.initiative);

	target->SetAge(base.age);

	target->SetPosition(*base.position);

	target->SetState(base.state);
}

Organism* spawnOrganismBySpecies(OrganismBase& base) {

	ORGANISM_SPECIES species = base.species;

	if (species == HUMAN) {
		// Already done to upper scope
	}
	else if (species == WOLF) {
		Wolf* organism = new Wolf();
		copyBaseProperties(base, organism);

		return organism;
	}
	else if (species == SHEEP) {
		Sheep* organism = new Sheep();
		copyBaseProperties(base, organism);

		return organism;
	}
	else if (species == FOX) {
		Fox* organism = new Fox();
		copyBaseProperties(base, organism);

		return organism;
	}
	else if (species == TURTLE) {
		Turtle* organism = new Turtle();
		copyBaseProperties(base, organism);

		return organism;
	}
	else if (species == ANTILOPE) {
		Antilope* organism = new Antilope();
		copyBaseProperties(base, organism);

		return organism;
	}
	else if (species == CYBER_SHEEP) {
		// Not Implemented yet
	}
	else if (species == GRASS) {
		Grass* organism = new Grass();
		copyBaseProperties(base, organism);

		return organism;
	}
	else if (species == SOW_THISTLE) {
		SowThistle* organism = new SowThistle();
		copyBaseProperties(base, organism);

		return organism;
	}
	else if (species == GUARANA) {
		Guarana* organism = new Guarana();
		copyBaseProperties(base, organism);

		return organism;
	}
	else if (species == BELLADONNA) {
		Belladonna* organism = new Belladonna();
		copyBaseProperties(base, organism);

		return organism;
	}
	else if (species == SOSNOWSKYS_HOGWEED) {
		SosnowskysHogweed* organism = new SosnowskysHogweed();
		copyBaseProperties(base, organism);

		return organism;
	}

	// Should never happen
	return nullptr;
}

ORGANISM_SPECIES parseStringToSpecies(string speciesString) {
	if (speciesString == "HUMAN") {
		return HUMAN;
	}
	else if (speciesString == "WOLF") {
		return WOLF;
	}
	else if (speciesString == "SHEEP") {
		return SHEEP;
	}
	else if (speciesString == "FOX") {
		return FOX;
	}
	else if (speciesString == "TURTLE") {
		return TURTLE;
	}
	else if (speciesString == "ANTILOPE") {
		return ANTILOPE;
	}
	else if (speciesString == "CYBER_SHEEP") {
		return CYBER_SHEEP;
	}
	else if (speciesString == "GRASS") {
		return GRASS;
	}
	else if (speciesString == "SOW_THISTLE") {
		return SOW_THISTLE;
	}
	else if (speciesString == "GUARANA") {
		return GUARANA;
	}
	else if (speciesString == "BELLADONNA") {
		return BELLADONNA;
	}
	else if (speciesString == "SOSNOWSKYS_HOGWEED") {
		return SOSNOWSKYS_HOGWEED;
	}
	else {
		return UNKNOWN;
	}

}

string parseSpeciesToString(ORGANISM_SPECIES species) {
	if (species == HUMAN) {
		return "HUMAN";
	}
	else if (species == WOLF) {
		return "WOLF";
	}
	else if (species == SHEEP) {
		return "SHEEP";
	}
	else if (species == FOX) {
		return "FOX";
	}
	else if (species == TURTLE) {
		return "TURTLE";
	}
	else if (species == ANTILOPE) {
		return "ANTILOPE";
	}
	else if (species == CYBER_SHEEP) {
		return "CYBER_SHEEP";
	}
	else if (species == GRASS) {
		return "GRASS";
	}
	else if (species == SOW_THISTLE) {
		return "SOW_THISTLE";
	}
	else if (species == GUARANA) {
		return "GUARANA";
	}
	else if (species == BELLADONNA) {
		return "BELLADONNA";
	}
	else if (species == SOSNOWSKYS_HOGWEED) {
		return "SOSNOWSKYS_HOGWEED";
	}
	else {
		return "UNKNOWN";
	}

}

ORGANISM_STATE parseStringToOrganismState(string speciesString) {
	if (speciesString == "ALIVE") {
		return ALIVE;
	}
	else {
		return DEAD;
	}
}

string parseOrganismStateToString(ORGANISM_STATE species) {
	if (species == ALIVE) {
		return "ALIVE";
	}
	else {
		return "DEAD";
	}
}


istream& operator>>(istream& inputStream, OrganismBase& base) {

	int strength;
	inputStream >> base.strength;
	//organism.SetStrength(strength);

	int initiative;
	inputStream >> base.initiative;
	//organism.SetInitiative(initiative);

	int age;
	inputStream >> base.age;
	//organism.SetAge(age);

	int x, y;
	inputStream >> x;
	inputStream >> y;
	Point2D* newPos = new Point2D(x, y);
	base.position = newPos;
	//organism.SetPosition(newPos);

	string species;
	inputStream >> species;
	ORGANISM_SPECIES parsedSpecies = parseStringToSpecies(species);
	base.species = parsedSpecies;
	//organism.SetSpecies(parsedSpecies);

	char visual;
	inputStream >> base.visual;
	//organism.SetVisual(visual);

	string state;
	inputStream >> state;

	ORGANISM_STATE properState = parseStringToOrganismState(state);
	base.state = properState;
	//organism.SetState();

	return inputStream;
}


ostream& operator<<(ostream& outputStream, Organism& organism)
{
	outputStream << parseIntToChar(organism.GetStrength()) << " ";
	outputStream << parseIntToChar(organism.GetInitiative()) << " ";
	outputStream << parseIntToChar(organism.GetAge()) << " ";

	outputStream << organism.GetPosition().x << " ";
	outputStream << organism.GetPosition().y << " ";

	ORGANISM_SPECIES species = organism.GetSpecies();
	outputStream << parseSpeciesToString(species) << " ";

	outputStream << organism.GetVisual() << " ";

	outputStream << parseOrganismStateToString(organism.GetState()) << " ";

	if (species == HUMAN) {
		Human* asHuman = dynamic_cast<Human*>(&organism);
		outputStream << asHuman->GetStrengthBuff() << " ";
		outputStream << asHuman->GetAbilityCooldown() << " ";
	}

	return outputStream;
}

void World::SaveToFile() {
	string fileName = controller->GetFileName();

	ofstream outputStream( fileName.c_str() );

	outputStream << organisms->size() << " ";

	outputStream << height << " ";
	outputStream << width << " ";


	int organismsSize = organisms->size();

	for (int i = 0; i < organismsSize; i++)
	{
		Organism* elem = (*organisms)[i];

		outputStream << *elem << " ";
	}

	outputStream.close();

}

void World::LoadFromFile() {

	int organismsSize = organisms->size();
	for (int i = organismsSize-1; i >= 0; i--)
	{
		Organism* elem = (*organisms)[i];
		delete elem;

		organisms->pop_back();
	}
	player = nullptr;


	string fileName = controller->GetFileName();

	ifstream inputStream(fileName.c_str());

	int organismsInputSize;
	inputStream >> organismsInputSize;

	inputStream >> height;
	inputStream >> width;



	for (int i = 0; i < organismsInputSize; i++)
	{

		OrganismBase base;
		inputStream >> base;

		Organism* properType = nullptr;
		if (base.species == HUMAN) {
			
			Human* human = new Human();

			copyBaseProperties(base, human);

			int strengthBuff;
			inputStream >> strengthBuff;
			human->SetStrengthBuff(strengthBuff);

			int cooldown;
			inputStream >> cooldown;
			human->SetAbilityCooldown(cooldown);

			World* world = World::GetInstance();
			world->SetPlayer(human);

			properType = human;

		}
		else {
			properType = spawnOrganismBySpecies(base);
		}

		organisms->push_back(properType);
	}

	justLoaded = true;
	inputStream.close();
}
