#include <iostream>
#include <cstdlib>
#include "Character.h"
#pragma once

Character::Character(const char* name, int maxHealth, int attack, int defense)
{
	mName = name;
	mMaxHealth = maxHealth;
	mHealth = maxHealth;
	mAttack = attack;
	mDefense = defense;
	mPotionCount = 0;
	mExpLevel = 1;
	mExpPoints = 0;
	mExpToNextLevel = 100;
}

void Character::ShowStats()
{
	std::cout << "STATS OF " << mName << std::endl;
	std::cout << "   - HP : " << mHealth << std::endl;
	std::cout << "   - MAX HP : " << mMaxHealth << std::endl;
	std::cout << "   - ATTACK : " << mAttack << std::endl;
	std::cout << "   - DEFENSE : " << mDefense << std::endl;
}

int Character::TakeDamage(int damage)
{
	damage -= mDefense;
	if (damage < 1)
	{
		damage = 1;
	}
	if (damage < mHealth)
	{
		mHealth -= damage;
	}
	else
	{
		mHealth = 0;
	}
	return damage;
}

int Character::DealDamage(Character* c)
{
	return c->TakeDamage(mAttack);
}

bool Character::IsDead()
{
	return mHealth == 0;
}

void Character::LevelUp()
{
	if (mMaxHealth > 9)
	{
		mMaxHealth = mMaxHealth + (mMaxHealth / 10);
	}
	else
	{
		mMaxHealth += 1;
	}

	if (mAttack > 19)
	{
		mAttack = mAttack + (mAttack / 20);
	}
	else
	{
		mAttack += 1;
	}

	if (mDefense > 19)
	{
		mDefense = mDefense + ( mDefense / 20 );
	}
	else
	{
		mDefense += 1;
	}
	
	mHealth = mMaxHealth;
}

void Character::Heal(int hp)
{
	if (mHealth + hp < mMaxHealth)
	{
		mHealth += hp;
	}
	else
	{
		mHealth = mMaxHealth;
	}
}

void Character::AddExp(int exp)
{
	if (mExpPoints + exp > mExpToNextLevel)
	{
		mExpPoints = mExpPoints + exp - mExpToNextLevel;
		mExpLevel += 1;
		mExpToNextLevel += 100;
		std::cout << "You leveled up to level " << mExpLevel << std::endl << std::endl;
		LevelUp();
	}
	else
	{
		mExpPoints += exp;
	}
}

void Character::GetPotion()
{
	int i = rand() % 100;
	if (i < 40)
	{
		std::cout << "The ennemie has dropped a healing potion before running away." << std::endl;
		mPotionCount += 1;
		std::cout << "You now have " << mPotionCount << " potions." << std::endl << std::endl;
	}
}

void Character::AskPotionUse()
{
	char input = ' ';
	bool isCorrectChar = ((int)input != (int)'Y' && (int)input != (int)'y' + 32 && (int)input != (int)'N' && (int)input != (int)'n' + 32);
	std::cout << "You have " << mHealth << " HP" << std::endl;
	std::cout << "Do you want to use a potion ? : (Y : yes, N : no) ";
	std::cin >> input;

	while (!isCorrectChar || std::cin.peek() != '\n')
		// Si l'entrée contient plus d'un char ou il n'est parmis les choix indiqués
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		std::cout << "INVALID INPUT, please try again" << std::endl;
		std::cout << "Do you want to use a potion ? : (Y : yes, N : no) ";
		std::cin >> input;
	}
	if (input == 'Y' || input == 'y')
	{
		Heal(50);
		mPotionCount -= 1;
		std::cout << "You now have " << mHealth << " HP" << std::endl << std::endl;
	}
}
