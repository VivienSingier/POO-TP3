#include "Archer.h"
#include <iostream>
#include <cstdlib>

Archer::Archer() : Character::Character("Archer", 150, 20, 15)
{
	mCritChance = 10;
	mAbilityCooldown = 8;
	mIsDoubleHit = false;
	mIsAbilityReady = false;
}

int Archer::DealDamage(Character* c)
{
	int r = rand() % 100;
	if (mIsDoubleHit)
	{
		mAttack *= 2;
	}
	if (r < mCritChance)
	{
		std::cout << "Your Archer managed to inflict a CRITICAL HIT" << std::endl;
		mAttack *= 2;
	}
	int damage = Character::DealDamage(c);
	if (mIsDoubleHit)
	{
		mAttack /= 2;
	}
	if (r < mCritChance)
	{
		mAttack /= 2;
	}
	mIsDoubleHit = false;
	CoolDownAbility();
	return damage;
}

void Archer::LevelUp()
{
	Character::LevelUp();
	mCritChance += 1;
}

void Archer::SpecialAbility()
{
	if (mIsAbilityReady)
	{
		std::cout << "Your Archer shot two arrows at once" << std::endl;
		mIsDoubleHit = true;
		mIsAbilityReady = false;
		mAbilityCooldown = 8;
	}
}

void Archer::CoolDownAbility()
{
	if (!mIsDoubleHit && !mIsAbilityReady)
	{
		mAbilityCooldown -= 1;
	}
	if (mAbilityCooldown == 0)
	{
		mIsAbilityReady = true;
	}
}
