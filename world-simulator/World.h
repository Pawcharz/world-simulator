#pragma once
#include "Organism.h"

#include <vector>

class World
{
private:

	int height;
	int width;

	vector<Organism*>* organisms;

	static World* worldInstance;


	World();

	Point2D& GetStartBorders();
	Point2D& GetFinishBorders();

	void SetSize(int width, int height);

public:

	World(const World& other) = delete;

	~World();

	static World* GetInstance();

	void Initialize(int widthArg, int heightArg);



	void AddOrganism(Organism* organism);


	//vector<Point2D>* GetFreeNeighbouringFields(Point2D& position);

	vector<Point2D*>* GetNeighbouringFields(Point2D& position);


	void MakeTurn();

	bool IsWithinBorders(Point2D& position);



	Point2D& GetSize();

	vector<Organism*>* GetOrganisms();
};

