#include "Displayer.h"

Displayer* Displayer::displayerInstance = nullptr;

Displayer::Displayer() {
	World* world = World::GetInstance();

	Point2D size = world->GetSize();
	Point2D displayedSize = size;
	displayedSize.x += 2;
	displayedSize.y += 2;
	//displayedSize.x *= 2;

	screenBuffer = new vector<vector<char*>*>(size.y);

	for (int y = 0; y < size.y; y++)
	{
		vector<char*>* rowTmp = new vector<char*>(size.x);
		for (int x = 0; x < size.x; x++)
		{
			(*rowTmp)[x] = new char('*');
		}
		(*screenBuffer)[y] = rowTmp;
	}

}

Displayer* Displayer::GetInstance() {
	if (displayerInstance == nullptr) {
		displayerInstance = new Displayer();
		return displayerInstance;
	}

	return displayerInstance;
}

void Displayer::UpdateBuffer() {
	World* world = World::GetInstance();

	int height = screenBuffer->size();
	for (int y = 0; y < height; y++)
	{
		vector<char*>* row = (*screenBuffer)[y];
		int width = row->size();

		for (int x = 0; x < width; x++)
		{
			*(*row)[x] = '*';
		}
	}

	vector<Organism*>* organisms = world->GetOrganisms();

	int organismsCount = organisms->size();

	for (int i = 0; i < organismsCount; i++)
	{
		Organism* organism = (*organisms)[i];
		Point2D position = organism->GetPosition();
		char visual = (*organisms)[i]->GetVisual();

		vector<char*>* row = (*screenBuffer)[position.y];

		char* cell = (*row)[position.x];

		*cell = visual;
	}
}

void Displayer::DrawWorld() {
	UpdateBuffer();
	system("cls");

	int height = screenBuffer->size();
	for (int y = height-1; y >= 0; y--)
	{
		vector<char*>* row = (*screenBuffer)[y];
		int width = row->size();

		for (int x = 0; x < width; x++)
		{
			cout << *(*row)[x] << ' ';
		}
		cout << endl;
	}
}