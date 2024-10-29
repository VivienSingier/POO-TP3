#include "Warrior.h"
#include <iostream>

Warrior::Warrior() : Character("Warrior", 100, 30, 25)
{
	mAbilityDurationCounter = 0;
}

void Warrior::SpecialAbility() 
{
	if (mAbilityDurationCounter == 10)
	{
		mAttack -= 20;
		mDefense += 5;
	}
	if (mAbilityDurationCounter == 0)
	{
		mAttack += 20;
		mDefense -= 5;
		mAbilityDurationCounter = 13;
		std::cout << "Your Warrior juste used his WAR CRY ability" << std::endl;
	}

	mAbilityDurationCounter -= 1;
	std::cout << mAbilityDurationCounter << std::endl;
}

