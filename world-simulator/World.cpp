#include "World.h"
#include "Displayer.h"

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
};

World* World::GetInstance()
{
	if (worldInstance == nullptr) {
		worldInstance = new World();
		return worldInstance;
	}

	return worldInstance;
}

void World::SetSize(int widthArg, int heightArg) {
	width = widthArg;
	height = heightArg;
}

void World::Initialize(int widthArg, int heightArg) {
	SetSize(widthArg, heightArg);

	const int WOLFS_COUNT = 4;
	const int SHEEPS_COUNT = 6;
	const int FOXES_COUNT = 2;
	const int TURTLES_COUNT = 2;
	const int ANTELOPES_COUNT = 2;

	CreateSpecies<Wolf>(WOLFS_COUNT);
	CreateSpecies<Sheep>(SHEEPS_COUNT);
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

	Organism* best = (*all)[0];

	for (int i = 1; i < length; i++)
	{
		Organism* newOrganism = (*all)[i];
		int currentInitiative = best->GetInitiative();
		int newInitiative = newOrganism->GetInitiative();

		bool includes = vectorIncludes<Organism*>(excluded, newOrganism);

		if (!includes) {
			if (newInitiative > currentInitiative) {
				best = newOrganism;
			}
			else if (newInitiative == currentInitiative && newOrganism->GetAge() > best->GetAge()) {

				best = newOrganism;
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

vector<Point2D>* World::GetNeighbouringFields(Point2D& position) {

	vector<Point2D>* neighbours = new vector<Point2D>();

	Point2D top = position.GetTopPosition();
	if (IsWithinBorders(top)) {
		neighbours->push_back(top);
	}

	Point2D bottom = position.GetBottomPosition();
	if (IsWithinBorders(bottom)) {
		neighbours->push_back(bottom);
	}

	Point2D left = position.GetLeftPosition();
	if (IsWithinBorders(left)) {
		neighbours->push_back(left);
	}

	Point2D right = position.GetRightPosition();
	if (IsWithinBorders(right)) {
		neighbours->push_back(right);
	}

	return neighbours;
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
		if (organism->GetState()) {
			newOrganisms->push_back(organism);
		}
	}

	delete organisms;
	organisms = nullptr;
	swap(organisms, newOrganisms);
}


void World::MakeTurn() {
	// Sort organisms by initiative
	int initialOrganismsCount = organisms->size();
	//qsort(organisms, );

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
	Displayer* displayer = Displayer::GetInstance();

	char pressed = NULL;

	while (pressed != 'q') {
		pressed = getchar();

		if (pressed == ' ') {
			MakeTurn();
			displayer->DrawWorld();
		}
	}
	
}


