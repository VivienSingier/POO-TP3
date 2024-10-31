#pragma once
#include "Character.h"

class Mage : public Character
{
	int mMana;
	int mMaxMana;
	int mFireBallBoost;
	bool mIsfireball;

public:
	Mage();
	int DealDamage(Character* c) override;
	void LevelUp() override; 
	void SpecialAbility() override;
};

