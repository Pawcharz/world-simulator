#pragma 
#include "World.h"
#include "utlis.h"
#include "Wolf.h"
#include "Sheep.h"

#include <vector>
#include <iostream>

using namespace std;


class Displayer
{
private:
	vector<vector<char*>*>* screenBuffer;

	void UpdateBuffer();

	Displayer();

	static Displayer* displayerInstance;

public:

	static Displayer* GetInstance();

	~Displayer();

	void DrawWorld();
};

