#pragma once
#include "Character.h"

class Archer : public Character
{
	int mCritChance;
	int mAbilityCooldown;
	bool mIsDoubleHit;
	bool mIsAbilityReady;

public :

	Archer();
	void LevelUp() override;
	int DealDamage(Character* c) override;
	void SpecialAbility() override;
	void CoolDownAbility();
};

