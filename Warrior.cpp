#include "Warrior.h"
#include <iostream>

Warrior::Warrior() : Character("Warrior", 120, 30, 25)
{
	mIsWarCry = false;
	mIsAbilityReady = false;
	mDamageBoost = 25;
	mAbilityCooldown = 10;
	mAbilityDuration = 3;
}

int Warrior::DealDamage(Character* c)
{
	if (mIsWarCry)
	{
		mAttack += mDamageBoost;
	}
	int damage = Character::DealDamage(c);
	if (mIsWarCry)
	{
		mAttack -= mDamageBoost;
	}
	CooldownAbility();
	return damage;
}

void Warrior::SpecialAbility() 
{
	if (!mIsWarCry && mIsAbilityReady)
	{
		mIsWarCry = true;
		mAbilityCooldown = 10;
		mAbilityDuration = 3;
	}
}

void Warrior::CooldownAbility()
{
	if (mIsWarCry && mAbilityDuration > 0)
	{
		mAbilityDuration -= 1;
	}
	else if (mAbilityCooldown > 0)
	{
		mAbilityCooldown -= 1;
	}
	if (mAbilityDuration == 0)
	{
		mIsWarCry = false;
		mIsAbilityReady = false;
	}
	if (mAbilityCooldown == 0)
	{
		mIsAbilityReady = true;
	}
}

