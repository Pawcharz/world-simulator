#pragma 
#include "World.h"
#include "utlis.h"
#include "Sheep.h"

#include <vector>

class Displayer
{
private:
	vector<vector<char*>*>* screenBuffer;

	void UpdateBuffer();
public:

	Displayer();

	~Displayer();

	void DrawWorld();
};

