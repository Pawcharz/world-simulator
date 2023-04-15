#pragma once

#include <iostream>
#include <vector>

#include "Organism.h"
#include "utlis.h"
#include "Point2D.h"

#include "Wolf.h"
#include "Sheep.h"


using namespace std;

class World
{
private:

	int height;
	int width;

	vector<Organism*>* organisms;

	static World* worldInstance;


	World();

	void SetSize(int width, int height);

	bool IsWithinBorders(Point2D& position);

	template<typename T>
	void CreateOrganism() {
		T* organism = new T();
		Point2D position = Point2D::Random(GetStartBorders(), GetFinishBorders());

		// FIX - will crash for more entities on the map
		Organism* existing = GetOrganismAtPosition(position);
		while (existing != nullptr)
		{
			position = Point2D::Random(GetStartBorders(), GetFinishBorders());
			existing = GetOrganismAtPosition(position);
		}

		organism->SetPosition(position);
		organisms->push_back(organism);
	}

	template<typename T>
	void CreateSpecies(int entities) {
		for (int i = 0; i < entities; i++)
		{
			CreateOrganism<T>();
		}
	}

	void MakeTurn();

	void CleanDeadOrganisms();

	void SortOrganisms();

public:
	Point2D& GetStartBorders();
	Point2D& GetFinishBorders();

	World(const World& other) = delete;

	~World();

	static World* GetInstance();

	void Initialize(int widthArg, int heightArg);

	void Simulate();



	vector<Point2D>* GetNeighbouringFields(Point2D& position);


	Point2D& GetSize();

	vector<Organism*>* GetOrganisms();

	Organism* GetOrganismAtPosition(Point2D& position);

	void KillOrganism(Organism* target);

};

