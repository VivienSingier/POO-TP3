#include "Mage.h"
#include <iostream>

Mage::Mage() : Character::Character("Mage", 130, 10, 10)
{
	mMaxMana = 100;
	mMana = 100;
	mFireBallBoost = 30;
	mIsfireball = false;
}

int Mage::DealDamage(Character* c)
{
	if (mIsfireball)
	{
		mAttack += mFireBallBoost;
	}
	int damage = Character::DealDamage(c);
	if (mIsfireball)
	{
		mAttack -= mFireBallBoost;
	}

	return damage;
}

void Mage::LevelUp()
{
	Character::LevelUp();
	mMaxMana += mMaxMana / 20;
	mMana = mMaxMana;
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
			mIsfireball = true;
			std::cout << "Your mage just threw a fireball spell" << std::endl;
		}
		mMana -= 30;
	}
	else
	{
		std::cout << "Your mage doesn't have enough mana" << std::endl;
	}
}
