#pragma once
class Character
{
public:
	const char* mName;
	int mMaxHealth;
	int mHealth;
	int mAttack;
	int mDefense;
	int mPotionCount;
	int mExpPoints;
	int mExpLevel;
	int mExpToNextLevel;

public:
	Character(const char* name, int maxHealth, int attack, int defense);

	void ShowStats();
	int TakeDamage(int damage);
	bool IsDead();
	void LevelUp();
	void Heal(int hp);
	void AddExp(int exp);
	void GetPotion();
	void AskPotionUse();

};

