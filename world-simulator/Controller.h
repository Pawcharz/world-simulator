#pragma once
#include <string>

using namespace std;


enum SIMULATION_MODE {
	FILE_SAVING,
	FILE_LOADING,

	SIMULATION_PLAYING
};

class Controller
{
private:
	char pressedCharacter;

	SIMULATION_MODE mode;

	//string fileName; // ADD more from file saving. Maybe create another class
public:
	Controller();

	void ReadInputChar();

	char GetPressedCharacter();
};

