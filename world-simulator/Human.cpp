#include "Human.h"
#include "World.h"
#include <conio.h>

Human::Human() {

	strength = 105;
	baseStrength = strength;

	initiative = 4;

	species = HUMAN;
	visual = 'H';

	specialAbilityCooldown = 0;
	strengthBuff = 0;
}

Human::Human(Organism& base) {

	strength = base.GetStrength();
	baseStrength = strength;

	initiative = base.GetInitiative();

	Point2D* pos = new Point2D();
	pos->x = base.GetPosition().x;
	pos->y = base.GetPosition().y;

	position = pos;

	species = HUMAN;
	visual = 'H';

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
	specialAbilityCooldown = 5;

	Displayer* displayer = World::GetInstance()->GetDisplayer();
	displayer->AddLog("You drink magic potion, strength + 5");
}

bool Human::HandleMovement() {
	World* world = World::GetInstance();
	Controller* controller = world->GetController();
	Displayer* displayer = world->GetDisplayer();

	char pressedKey = controller->GetPressedCharacter();

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
		return false;
	}
}

void Human::HandleControlledAction(bool* errorOccured) {
	World* world = World::GetInstance();
	Controller* controller = world->GetController();
	Displayer* displayer = world->GetDisplayer();

	char pressedKey = controller->GetPressedCharacter();

	if (pressedKey == ' ') {
		if (specialAbilityCooldown == 0) {

			UseSpecialAbility();
			*errorOccured = false;
		}
		else {
			string message = "You cant use this ability for the next ";
			message += (specialAbilityCooldown + '0');
			message += " turns.";
			displayer->AddLog(message);
		}
	}
	else {
		bool success = HandleMovement();
		*errorOccured = !success;
	}
}

void Human::Action() {
	World* world = World::GetInstance();
	Controller* controller = world->GetController();

	controller->ReadInputChar();

	UpdateState();
}


void Human::SetStrengthBuff(int buff) {
	strengthBuff = buff;
}

int Human::GetStrengthBuff() {
	return strengthBuff;
}

void Human::SetAbilityCooldown(int cooldown) {
	specialAbilityCooldown = cooldown;
}

int Human::GetAbilityCooldown() {
	return specialAbilityCooldown;
}