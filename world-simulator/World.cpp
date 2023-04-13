#include "World.h"

#include <stdexcept>
#include <iostream>

#include "utlis.h"
#include "Wolf.h"

#include <vector>

using namespace std;

const Point2D WORLD_CENTER(0, 0);

World* World::worldInstance = nullptr;



World::~World() {
	delete organisms;
	organisms = nullptr;
}

World::World() : height(1), width(1), organisms(new vector<Organism*>()) {};

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

	Wolf* animal1 = new Wolf();
	Point2D pos(-1, 4);
	animal1->SetPosition(pos);
	AddOrganism(animal1);

}


void World::AddOrganism(Organism* organism) {
	organisms->push_back(organism);
}

//vector<Point2D>* World::GetFreeNeighbouringFields(Point2D& position) {
//
//	vector<Point2D>* neighbours = GetNeighbouringFields(position);
//
//	int length = organisms->size();
//	for (int i = 0; i < length; i++)
//	{
//		int neighboursLength = neighbours->GetLength();
//		for (int j = 0; j < neighboursLength; j++)
//		{
//			// should be fixed to standard [i] <-
//			if (organisms->GetElement(i).GetPosition().IsEqual(neighbours->GetElement(i))) {
//				neighbours->RemoveSpecific(j);
//			}
//		}
//	}
//
//
//	return neighbours;
//}


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

vector<Point2D*>* World::GetNeighbouringFields(Point2D& position) {

	vector<Point2D*>* neighbours = new vector<Point2D*>();

	Point2D top = position.GetTopPosition();
	if (IsWithinBorders(top)) {
		neighbours->push_back(&top);
	}

	Point2D bottom = position.GetBottomPosition();
	if (IsWithinBorders(bottom)) {
		neighbours->push_back(&bottom);
	}

	Point2D left = position.GetLeftPosition();
	if (IsWithinBorders(left)) {
		neighbours->push_back(&left);
	}

	Point2D right = position.GetRightPosition();
	if (IsWithinBorders(right)) {
		neighbours->push_back(&right);
	}

	return neighbours;
}


Point2D& World::GetStartBorders() {
	int x = WORLD_CENTER.x - int(width / 2);

	int y = WORLD_CENTER.y - int(height / 2);

	Point2D position(x, y);

	return position;
}
Point2D& World::GetFinishBorders() {
	int x = WORLD_CENTER.x + int(width / 2);
	if (width % 2 == 0) {
		x -= 1;
	}

	int y = WORLD_CENTER.y + int(height / 2);
	if (height % 2 == 0) {
		y -= 1;
	}

	Point2D position(x, y);

	return position;
}


Point2D& World::GetSize() {
	Point2D size(width, height);
	return size;
}


vector<Organism*> World::GetOrganisms() {
	return organisms;
}