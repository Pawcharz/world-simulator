#include "Human.h"
#include "World.h"
#include <conio.h>

Human::Human() {

	strength = 5;
	initiative = 4;

	species = HUMAN;
	visual = '+';
}
bool isValidKey(char key) {
	if (key == 'a' || key == 'd' || key == 'w' || key == 's' || key == ' ') {
		return true;
	}
	return false;
}

void Human::Action() {
	World* world = World::GetInstance();
	Displayer* displayer = world->GetDisplayer();

	Point2D moveTo;

	char pressedKey = NULL;
	while (!isValidKey(pressedKey))
	{
		pressedKey = _getch();

		switch (pressedKey)
		{
		case 'a':
			moveTo = position->GetLeftPosition();
			break;
		case 'd':
			moveTo = position->GetRightPosition();
			break;
		case 'w':
			moveTo = position->GetTopPosition();
			break;
		case 's':
			moveTo = position->GetBottomPosition();
			break;
		case ' ':
			displayer->AddLog("Special ability used!");
			// Use Special Ability
			return;
		default:
			displayer->AddLog("Wrong key, try again");
			displayer->DrawWorld();
		}

		if (!world->IsWithinBorders(moveTo)) {
			displayer->AddLog("Tried to move outside of the map, try again");
			displayer->DrawWorld();
			pressedKey = NULL;
		}
	}


	

	Organism* target = world->GetOrganismAtPosition(moveTo);

	if (target != nullptr) {

		Attack(target);
		return;
	}
	
	*position = moveTo;
}
