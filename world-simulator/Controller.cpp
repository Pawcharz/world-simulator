#include "Controller.h"
#include <conio.h>
#include "World.h"

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
		displayer->DrawWorld();
		pressedCharacter = _getch();

		if (mode == SIMULATION_PLAYING) {

			if (isValidPlayerKey(pressedCharacter)) {
				world->GetPlayer()->HandleControlledAction(&errorOccured);
			}
			else {
				displayer->ResetLogs();
				displayer->AddLog("Wrong key, try again");
				displayer->DrawWorld();
			}
		}
		else {
			// ...
		}
	}












	

	

}


char Controller::GetPressedCharacter() {
	return pressedCharacter;
}
