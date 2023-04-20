#include "Human.h"
#include "World.h"
#include <conio.h>

Human::Human() {

	strength = 5;
	baseStrength = strength;

	initiative = 4;

	species = HUMAN;
	visual = '+';

	specialAbilityCooldown = 0;
	strengthBuff = 0;
}

void Human::UpdateState() {

	strength = baseStrength + strengthBuff;

	strengthBuff -= 1;

	if (strengthBuff < 0) {
		strengthBuff = 0;
	}

	specialAbilityCooldown -= 1;

	if (specialAbilityCooldown < 0) {
		specialAbilityCooldown = 0;
	}
}

void Human::UseSpecialAbility() {
	strengthBuff = 5;

	Displayer* displayer = World::GetInstance()->GetDisplayer();
	displayer->AddLog("You drink magic potion, strength + 5");
}

bool Human::HandleMovement(char pressedKey) {
	World* world = World::GetInstance();
	Displayer* displayer = world->GetDisplayer();

	Point2D moveTo;

	if (pressedKey == 'a') {
		moveTo = position->GetLeftPosition();
	}
	else if (pressedKey == 'd') {
		moveTo = position->GetRightPosition();
	}
	else if (pressedKey == 'w') {
		moveTo = position->GetTopPosition();
	}
	else if (pressedKey == 's') {
		moveTo = position->GetBottomPosition();
	}

	if (world->IsWithinBorders(moveTo)) {
		Organism* target = world->GetOrganismAtPosition(moveTo);

		displayer->ResetLogs();
		if (target != nullptr) {

			Attack(target);
			return true;
		}

		*position = moveTo;
		return true;
	}
	else {
		displayer->ResetLogs();
		displayer->AddLog("Tried to move outside of the map, try again");
		displayer->DrawWorld();
		return false;
	}
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
	displayer->DrawWorld();

	char pressedKey = NULL;
	bool errorOccured = true;

	while (errorOccured)
	{
		pressedKey = _getch();

		if (isValidKey(pressedKey)) {

			if (pressedKey == ' ') {
				if (specialAbilityCooldown == 0) {

					UseSpecialAbility();
					errorOccured = false;
				}
				else {
					string message = "You cant use this ability for the next " + (specialAbilityCooldown + '0');
					message += " turns.";
					displayer->AddLog(message);
				}
			}
			else {
				bool success = HandleMovement(pressedKey);
				errorOccured = !success;
			}
		}
		else {
			displayer->ResetLogs();
			displayer->AddLog("Wrong key, try again");
			displayer->DrawWorld();
		}
	}

	UpdateState();
	//displayer->DrawWorld();
}

