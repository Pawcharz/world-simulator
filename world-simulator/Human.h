#pragma once
#include "Animal.h"

class Human : public Animal
{
private:

	int specialAbilityCooldown;

	int baseStrength;
	int strengthBuff;

	void UseSpecialAbility();

	bool HandleMovement();

public:
	Human();

	void SetStrengthBuff(int buff);

	int GetStrengthBuff();


	void SetAbilityCooldown(int cooldown);

	int GetAbilityCooldown();



	void UpdateState();

	void HandleControlledAction(bool* errorOccured);

	void Action();
};
