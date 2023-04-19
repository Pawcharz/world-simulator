#include "Human.h"
#include "World.h"
#include <conio.h>

Human::Human() {

	strength = 5;
	initiative = 4;

	species = HUMAN;
	visual = '+';
}

void Human::Action() {
	char pressedKey = _getch();
	Point2D moveTo;

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
		cout << "Special ability used!";
		return;
	default:
		return;
	}

	World* world = World::GetInstance();

	if (!world->IsWithinBorders(moveTo)) {
		return;
	}

	Organism* target = world->GetOrganismAtPosition(moveTo);

	if (target != nullptr) {

		Attack(target);
		return;
	}
	
	*position = moveTo;
}
