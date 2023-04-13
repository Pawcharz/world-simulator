#include "Displayer.h"

#include <iostream>
#include "Wolf.h"
#include "Sheep.h"

#include <vector>

using namespace std;


Displayer::Displayer() {
	World* world = World::GetInstance();

	Point2D size = world->GetSize();
	Point2D displayedSize = size;
	displayedSize.x += 2;
	displayedSize.y += 2;
	//displayedSize.x *= 2;
	screenBuffer = new vector<vector<char*>*>(size.y);

	for (int y = 0; y < size.x; y++)
	{
		vector<char*>* row = screenBuffer->at(y);
		row = new vector<char*>(size.x);
	}

}

void Displayer::UpdateBuffer() {
	World* world = World::GetInstance();

	int height = screenBuffer->size();
	for (int y = 0; y < height; y++)
	{
		vector<char*>* row = screenBuffer->at(y);
		int width = row->size();

		for (int x = 0; x < width; x++)
		{
			*row->at(x) = '*';
		}
	}

	vector<Organism*>* organisms = world->GetOrganisms();
	int organismsCount = organisms->size();
	for (int i = 0; i < organismsCount; i++)
	{
		Organism* organism = organisms->at(i);
		Point2D position = organism->GetPosition();
		char visual = organisms->at(i)->GetVisual();
		vector<char*>* row = screenBuffer->at(position.y);
		char* cell = row->at(position.x);

		*cell = visual;
	}
}

void Displayer::DrawWorld() {
	UpdateBuffer();

	int height = screenBuffer->size();
	for (int y = 0; y < height; y++)
	{
		vector<char*>* row = screenBuffer->at(y);
		int width = row->size();

		for (int x = 0; x < width; x++)
		{
			cout << *row->at(x);
		}
		cout << endl;
	}

	
}