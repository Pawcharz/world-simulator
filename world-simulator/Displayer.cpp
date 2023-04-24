#include "Displayer.h"
#include "World.h"


Displayer::Displayer() {
	World* world = World::GetInstance();

	Point2D size = world->GetSize();
	Point2D displayedSize = size;
	displayedSize.x += 2;
	displayedSize.y += 2;

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


	logs = new vector<string>;
}



void Displayer::AddLog(string logText) {
	logs->push_back(logText);
}

void Displayer::ResetLogs() {
	logs->clear();
}

void Displayer::RegenerateBuffer() {

	World* world = World::GetInstance();
	Point2D size = world->GetSize();

	//int oldHeight = screenBuffer->size();
	//for (int y = 0; y < oldHeight; y++)
	//{
	//	delete (*screenBuffer)[y];
	//}

	delete screenBuffer;
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

void Displayer::UpdateBuffer() {

	RegenerateBuffer();

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

	cout << "Pawel Blicharz - s193193 | World Simulator";
	cout << endl;
	cout << endl;

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
	cout << endl;

	int logsSize = logs->size();
	for (int i = 0; i < logsSize; i++)
	{
		cout << (*logs)[i] << endl;
	}
}

void Displayer::DrawFileMenu() {

	Controller* controller = World::GetInstance()->GetController();

	system("cls");

	if (controller->GetMode() == FILE_SAVING) {
		cout << "File saving menu:" << endl;
	}
	else {
		cout << "File loading menu:" << endl;
	}

	cout << "Write name of the file: " << controller->GetFileName() << endl;
}

void Displayer::DrawInterface() {
	Controller* controller = World::GetInstance()->GetController();

	if (controller->GetMode() == SIMULATION_PLAYING) {
		DrawWorld();
	}
	else {
		DrawFileMenu();
	}
}
