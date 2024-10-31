#include "Mage.h"
#include <iostream>

Mage::Mage() : Character::Character("Mage", 130, 20, 10)
{
	mMaxMana = 100;
	mMana = 100;
	mIsfireball = false;
}

int Mage::TakeDamage(int damage)
{
	return 0;
}

void Mage::LevelUp()
{
	Character::LevelUp();
	mMaxMana += mMaxMana / 20;
	mMana = mMana;
}

void Mage::SpecialAbility()
{
	if (mMana > 30)
	{
		if (mMaxHealth - mHealth > 40)
		{
			mHealth += 40;
			std::cout << "Your mage just healed himself for 40 hp" << std::endl;
		}
		else
		{
			mAttack += 40;
			mIsfireball = true;
			std::cout << "Your mage just threw a fireball spell" << std::endl;
		}
	}
}
