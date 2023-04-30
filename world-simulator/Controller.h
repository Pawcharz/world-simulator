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

	string fileName;
public:
	Controller();

	void ReadInputChar();

	char GetPressedCharacter();

	SIMULATION_MODE GetMode();

	string GetFileName();
};

