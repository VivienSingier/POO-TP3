#pragma once
#include "Character.h"

class Warrior : public Character
{
	int mAbilityDurationCounter;

public :
	Warrior();
	void SpecialAbility() override;
};

