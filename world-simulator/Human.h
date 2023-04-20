#pragma once
#include "Animal.h"

class Human : public Animal
{
private:

	int specialAbilityCooldown;

	int baseStrength;
	int strengthBuff;

	void UseSpecialAbility();

	bool HandleMovement(char pressedKey);

public:
	Human();

	void UpdateState();

	void Action();
};
