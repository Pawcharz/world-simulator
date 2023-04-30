#include "Controller.h"
#include <conio.h>
#include "World.h"

const char KEY_ENTER = 13;
const char KEY_ESCAPE = 27;
const char KEY_BACKSPACE = 8;

Controller::Controller() {

	pressedCharacter = NULL;

	mode = SIMULATION_PLAYING;

}

bool isValidPlayerKey(char key) {
	if (key == 'a' || key == 'd' || key == 'w' || key == 's' || key == ' ') {
		return true;
	}
	return false;
}

void Controller::ReadInputChar()
{
	World* world = World::GetInstance();

	Displayer* displayer = world->GetDisplayer();

	bool errorOccured = true;

	while (errorOccured)
	{
		displayer->DrawInterface();
		pressedCharacter = _getch();

		if (mode == SIMULATION_PLAYING) {
			if (pressedCharacter == ',') {
				mode = FILE_SAVING;
			}
			else if (pressedCharacter == '.') {
				mode = FILE_LOADING;
			}
			else if (isValidPlayerKey(pressedCharacter)) {
				world->GetPlayer()->HandleControlledAction(&errorOccured);
			}
			else {
				displayer->ResetLogs();
				displayer->AddLog("Wrong key, try again");
			}
		}
		else {
			if (pressedCharacter == KEY_ENTER) {
				if (mode == FILE_SAVING) {
					world->SaveToFile();
					displayer->AddLog("Saved file to " + fileName);
					fileName.clear();
				}
				else if (mode == FILE_LOADING) {

					world->LoadFromFile();
					displayer->AddLog("Loaded game from " + fileName);
					fileName.clear();
				}
				mode = SIMULATION_PLAYING;
				//return;
			}
			else if (pressedCharacter == KEY_ESCAPE) {
				mode = SIMULATION_PLAYING;
				//return;
			}
			else if (pressedCharacter == KEY_BACKSPACE) {
				if (fileName.size() > 0) {
					fileName.pop_back();
				}
			}
			else {
				fileName += pressedCharacter;
			}			
		}


		
	}
}


char Controller::GetPressedCharacter() {
	return pressedCharacter;
}

SIMULATION_MODE Controller::GetMode() {
	return mode;
}

string Controller::GetFileName() {
	return fileName;
}