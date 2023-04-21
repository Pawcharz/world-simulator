#include "World.h"

World* World::worldInstance = nullptr;


World::~World() {
	delete organisms;
	organisms = nullptr;
}

World::World() : height(1), width(1) {

	// FIX - Should i move it?
	// FIX - Not working perfectly - first rand() always returns 4
	srand(time(NULL));

	organisms = new vector<Organism*>();
	player = nullptr;
};

World* World::GetInstance()
{
	if (worldInstance == nullptr) {
		worldInstance = new World();
	}

	return worldInstance;
}


void World::SetSize(int widthArg, int heightArg) {
	width = widthArg;
	height = heightArg;
}

void World::Initialize(int widthArg, int heightArg) {
	SetSize(widthArg, heightArg);

	worldInstance->displayer = new Displayer();
	worldInstance->controller = new Controller();

	const int WOLFS_COUNT = 2;
	const int SHEEPS_COUNT = 4;
	const int FOXES_COUNT = 2;
	const int TURTLES_COUNT = 2;
	const int ANTELOPES_COUNT = 2;


	const int GRASS_COUNT = 2;
	const int SOW_THISTLE_COUNT = 1;
	const int GUARANA_COUNT = 2;
	const int BELLADONNA_COUNT = 2;
	const int SOSNOWSKYS_HOGWEED_COUNT = 2;

	/*CreateSpecies<Wolf>(WOLFS_COUNT);
	CreateSpecies<Sheep>(SHEEPS_COUNT);
	CreateSpecies<Fox>(FOXES_COUNT);
	CreateSpecies<Turtle>(TURTLES_COUNT);
	CreateSpecies<Antilope>(ANTELOPES_COUNT);*/

	/*CreateSpecies<Grass>(GRASS_COUNT);
	CreateSpecies<SowThistle>(SOW_THISTLE_COUNT);
	CreateSpecies<Guarana>(GUARANA_COUNT);
	CreateSpecies<Belladonna>(BELLADONNA_COUNT);
	CreateSpecies<SosnowskysHogweed>(SOSNOWSKYS_HOGWEED_COUNT);*/


	//CreateSpecies<Wolf>(2);
	//CreateSpecies<Fox>(3);
	//CreateSpecies<Grass>(10);
	//CreateSpecies<Antilope>(1);
	//CreateSpecies<Wolf>(1);

	CreateSpecies<Sheep>(5);

	CreateHuman();
}


Controller* World::GetController() {
	return controller;
}

Displayer* World::GetDisplayer() {
	return displayer;
}


bool World::IsWithinBorders(Point2D& position) {

	Point2D start = GetStartBorders();
	Point2D end = GetFinishBorders();

	if (position.x < start.x || position.x > end.x) {
		return false;
	}

	if (position.y < start.y || position.y > end.y) {
		return false;
	}

	return true;
}

vector<Point2D>* World::GetFieldsAtRadius(Point2D& center, int radius) {

	vector<Point2D>* neighbours = new vector<Point2D>();

	Point2D top = center;
	Point2D bottom = center;
	Point2D left = center;
	Point2D right = center;

	for (int i = 0; i < radius; i++)
	{
		top = top.GetTopPosition();
		bottom = bottom.GetBottomPosition();
		left = left.GetLeftPosition();
		right = right.GetRightPosition();
	}
	
	if (IsWithinBorders(top)) {
		neighbours->push_back(top);
	}
	if (IsWithinBorders(bottom)) {
		neighbours->push_back(bottom);
	}
	if (IsWithinBorders(left)) {
		neighbours->push_back(left);
	}
	if (IsWithinBorders(right)) {
		neighbours->push_back(right);
	}
	return neighbours;
}
 

vector<Point2D>* World::GetNeighbouringFields(Point2D& position) {
	return GetFieldsAtRadius(position);
}

vector<Point2D>* World::GetNeighbouringFreeFields(Point2D& position) {

	vector<Point2D>* fields = GetNeighbouringFields(position);
	int length = fields->size();

	vector<Point2D>* free = new vector<Point2D>();

	for (int i = 0; i < length; i++)
	{
		Point2D position = (*fields)[i];
		Organism* organism = GetOrganismAtPosition(position);
		if (organism == nullptr) {
			free->push_back(position);
		}
	}

	return free;
}


Point2D& World::GetStartBorders() {

	Point2D* position = new Point2D(0, 0);

	return *position;
}

Point2D& World::GetFinishBorders() {
	int x = width - 1;
	int y = height - 1;

	Point2D* position = new Point2D(x, y);

	return *position;
}


Point2D& World::GetSize() {
	Point2D size(width, height);
	return size;
}

vector<Organism*>* World::GetOrganisms() {
	return organisms;
}

Organism* World::GetOrganismAtPosition(Point2D& position) {
	int organismsCount = organisms->size();

	for (int i = 0; i < organismsCount; i++)
	{
		Organism* elem = (*organisms)[i];

		if (elem->GetPosition().IsEqual(position)) {
			return elem;
		}
	}

	return nullptr;
}


template<typename ElementType>
bool vectorIncludes(vector<ElementType>* vector, ElementType elem) {
	int foundElements = count(vector->begin(), vector->end(), elem);

	if (foundElements > 0) {
		return true;
	}
	return false;
}

Organism* getQuickestOrganism(vector<Organism*>* all, vector<Organism*>* excluded) {
	int length = all->size();

	Organism* best = nullptr;

	for (int i = 0; i < length; i++)
	{
		Organism* newOrganism = (*all)[i];

		bool includes = vectorIncludes<Organism*>(excluded, newOrganism);

		if (!includes) {
			if (best == nullptr) {
				best = newOrganism;
			}
			else {
				int currentInitiative = best->GetInitiative();
				int newInitiative = newOrganism->GetInitiative();

				if (newInitiative > currentInitiative) {
					best = newOrganism;
				}
				else if (newInitiative == currentInitiative && newOrganism->GetAge() > best->GetAge()) {

					best = newOrganism;
				}
			}
		}
	}

	return best;
}

void World::SortOrganisms() {
	int length = organisms->size();

	vector<Organism*>* sorted = new vector<Organism*>();

	for (int i = 0; i < length; i++) {
		Organism* best = getQuickestOrganism(organisms, sorted);

		sorted->push_back(best);
	}

	delete organisms;
	organisms = sorted;
}


void World::CreateHuman() {
	player = new Human();
	Point2D position = Point2D::Random(GetStartBorders(), GetFinishBorders());

	// FIX - will crash for more entities on the map
	Organism* existing = GetOrganismAtPosition(position);
	while (existing != nullptr)
	{
		position = Point2D::Random(GetStartBorders(), GetFinishBorders());
		existing = GetOrganismAtPosition(position);
	}

	player->SetPosition(position);
	organisms->push_back(player);
}


void World::SetPlayer(Human* newPlayer) {
	if (player != nullptr) {
		delete player;
	}
	player = newPlayer;
}

Human* World::GetPlayer() {
	return player;
}


// Sets dead organisms to nullptr to avoid bugs while iterating over whole vectors in MakeTurn() function.
void World::KillOrganism(Organism* target) {
	int organismsCount = organisms->size();

	for (int i = 0; i < organismsCount; i++)
	{
		Organism* organism = (*organisms)[i];
		if (target == organism) {
			organism->SetState(DEAD);
			return;
		}
	}
}

void World::CleanDeadOrganisms() {
	int organismsCount = organisms->size();
	vector<Organism*>* newOrganisms = new vector<Organism*>();
	for (int i = 0; i < organismsCount; i++)
	{
		Organism* organism = (*organisms)[i];
		if (organism->GetState() == ALIVE) {
			newOrganisms->push_back(organism);
		}
		else {
			if (organism->GetSpecies() == HUMAN) {
				player = nullptr;
			}
			delete organism;
		}
	}


	delete organisms;
	organisms = nullptr;
	swap(organisms, newOrganisms);
}


void World::MakeTurn() {

	// Sort organisms by initiative
	int initialOrganismsCount = organisms->size();
	SortOrganisms();

	// Shouldnt break the order of organisms as we are marking deadAnimals as nullptr and new ones are created at the ond of the array (out of the initialOrganismsCount)
	for (int i = 0; i < initialOrganismsCount; i++)
	{
		Organism* elem = (*organisms)[i];

		if (elem != nullptr) {
			elem->Action();
		}
	}

	CleanDeadOrganisms();

	int organismsCount = organisms->size();

	for (int i = 0; i < organismsCount; i++)
	{
		Organism* elem = (*organisms)[i];
		int age = elem->GetAge();
		elem->SetAge(age + 1);
	}
}

void World::Simulate() {

	displayer->DrawWorld();

	while (player != nullptr) {
		MakeTurn();
	}
}
