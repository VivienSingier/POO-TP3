#pragma once
#include "Character.h"

class Warrior : public Character
{
	bool mIsWarCry;
	bool mIsAbilityReady;
	int mDamageBoost;
	int mAbilityCooldown;
	int mAbilityDuration;

public :
	Warrior();
	int DealDamage(Character* c) override;
	void SpecialAbility() override;
	void CooldownAbility();
};

