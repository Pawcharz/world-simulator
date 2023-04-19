#pragma once

#include <iostream>
#include <vector>

#include "Displayer.h"

#include "Organism.h"
#include "utlis.h"
#include "Point2D.h"

#include "Human.h"


#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antilope.h"

#include "Grass.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "Belladonna.h"

using namespace std;



class World
{
private:

	static World* worldInstance;

	Displayer* displayer;

	int height;
	int width;

	vector<Organism*>* organisms;

	Human* player;


	World();

	void SetSize(int width, int height);

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

	void CreateHuman();


	void MakeTurn();

	void CleanDeadOrganisms();

	void SortOrganisms();

public:
	bool IsWithinBorders(Point2D& position);

	Point2D& GetStartBorders();
	Point2D& GetFinishBorders();



	World(const World& other) = delete;

	~World();

	static World* GetInstance();

	void Initialize(int widthArg, int heightArg);

	void Simulate();


	
	vector<Point2D>* GetFieldsAtRadius(Point2D& position, int radius = 1);

	vector<Point2D>* GetNeighbouringFields(Point2D& position);

	vector<Point2D>* GetNeighbouringFreeFields(Point2D& position);


	Point2D& GetSize();

	vector<Organism*>* GetOrganisms();

	Organism* GetOrganismAtPosition(Point2D& position);

	void KillOrganism(Organism* target);

};

