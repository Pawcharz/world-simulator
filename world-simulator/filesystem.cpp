#include "World.h"
//#include "utlis.h"
#include <fstream>
//#pragma warning(disable : 4996)

using namespace std;

// Copies only properties that can vary between instances of the same subclass of Organism
void copyBaseProperties(Organism& base, Organism* target) {

	target->SetStrength(base.GetStrength());
	target->SetInitiative(base.GetInitiative());

	target->SetAge(base.GetAge());
	target->SetPosition(base.GetPosition());

	target->SetState(base.GetState());
}

Organism* spawnOrganismBySpecies(Organism* base) {

	ORGANISM_SPECIES species = base->GetSpecies();

	if (species == HUMAN) {
		// FIX - probably could be removed
		Human* asHuman = dynamic_cast<Human*>(base);

		Human* player = new Human();

		copyBaseProperties(*base, player);
		player->SetStrengthBuff(asHuman->GetStrengthBuff());
		player->SetAbilityCooldown(asHuman->GetAbilityCooldown());

		World* world = World::GetInstance();
		world->SetPlayer(player);

		return player;
	}
	else if (species == WOLF) {
		Wolf* organism = new Wolf();
		copyBaseProperties(*base, organism);

		return organism;
	}
	else if (species == SHEEP) {
		Sheep* organism = new Sheep();
		copyBaseProperties(*base, organism);

		return organism;
	}
	else if (species == FOX) {
		Fox* organism = new Fox();
		copyBaseProperties(*base, organism);

		return organism;
	}
	else if (species == TURTLE) {
		Turtle* organism = new Turtle();
		copyBaseProperties(*base, organism);

		return organism;
	}
	else if (species == ANTILOPE) {
		Antilope* organism = new Antilope();
		copyBaseProperties(*base, organism);

		return organism;
	}
	else if (species == CYBER_SHEEP) {
		// Not Implemented yet
	}
	else if (species == GRASS) {
		Grass* organism = new Grass();
		copyBaseProperties(*base, organism);

		return organism;
	}
	else if (species == SOW_THISTLE) {
		SowThistle* organism = new SowThistle();
		copyBaseProperties(*base, organism);

		return organism;
	}
	else if (species == GUARANA) {
		Guarana* organism = new Guarana();
		copyBaseProperties(*base, organism);

		return organism;
	}
	else if (species == BELLADONNA) {
		Belladonna* organism = new Belladonna();
		copyBaseProperties(*base, organism);

		return organism;
	}
	else if (species == SOSNOWSKYS_HOGWEED) {
		SosnowskysHogweed* organism = new SosnowskysHogweed();
		copyBaseProperties(*base, organism);

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


istream& operator>>(istream& inputStream, Organism& organism) {

	int strength;
	inputStream >> strength;
	organism.SetStrength(strength);

	int initiative;
	inputStream >> initiative;
	organism.SetInitiative(initiative);

	int age;
	inputStream >> age;
	organism.SetAge(age);

	int x, y;
	inputStream >> x;
	inputStream >> y;
	Point2D newPos(x, y);
	organism.SetPosition(newPos);

	string species;
	inputStream >> species;
	ORGANISM_SPECIES parsedSpecies = parseStringToSpecies(species);
	organism.SetSpecies(parsedSpecies);

	char visual;
	inputStream >> visual;
	organism.SetVisual(visual);

	string state;
	inputStream >> state;
	organism.SetState(parseStringToOrganismState(state));

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
		Organism* base = new Organism();

		inputStream >> *base;

		Organism* properType = nullptr;
		if (base->GetSpecies() == HUMAN) {
			Human* asHuman = new Human();

			int strengthBuff;
			inputStream >> strengthBuff;
			asHuman->SetStrengthBuff(strengthBuff);

			int cooldown;
			inputStream >> cooldown;
			asHuman->SetAbilityCooldown(cooldown);

			properType = spawnOrganismBySpecies(asHuman);
		}
		else {
			properType = spawnOrganismBySpecies(base);
		}

		organisms->push_back(properType);
	}

	inputStream.close();
}
