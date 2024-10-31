#pragma once
#include "Character.h"

class Mage : public Character
{
	int mMana;
	int mMaxMana;
	bool mIsfireball;

public:
	Mage();
	int TakeDamage(int damage) override;
	void LevelUp() override; 
	void SpecialAbility() override;
};

