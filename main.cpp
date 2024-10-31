#include <iostream>
#include <Windows.h>
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"

#define BLACK 0
#define RED 4
#define GREEN 2
#define YELLOW 6
#define BLUE 1
#define MAGENTA 5
#define CYAN 3
#define WHITE 15
#define LIGHTBLUE 9
#define LIGHTGREEN 10

void SetColor(int color, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | color);
}

void ResetColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (0 << 4) | 7);
}

void DisplayHealthBar(Character* player)
{
    int healthCubes = (int)(((float)player->mHealth / (float)player->mMaxHealth) * 20);

    std::cout << "+";
    for (int i = 0; i < 20; i++)
    {
        std::cout << "---";
    }
    std::cout << "+" << std::endl;

    std::cout << "|";
    SetColor(RED, BLACK);
    for (int i = 0; i < healthCubes; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << (char)178;
        };
    }
    SetColor(YELLOW, BLACK);
    if (healthCubes < 20)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << (char)177;
        }
    }
    ResetColor();
    for (int i = 0; i < 19 - healthCubes; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << (char)176;
        }
    }
    std::cout << "|" << std::endl;

    std::cout << "+";
    for (int i = 0; i < 20; i++)
    {
        std::cout << "---";
    }
    std::cout << "+" << std::endl;
}

void DisplayExpBar(Character* player)
{
    int expCubes = (int)(((float)player->mExpPoints / (float)player->mExpToNextLevel) * 10);

    std::cout << "|";
    SetColor(GREEN, BLACK);
    for (int i = 0; i < expCubes; i++)
    {
        std::cout << (char)219;
    }
    for (int i = 0; i < 10 - expCubes; i++)
    {
        std::cout << " ";
    }
    ResetColor();
    std::cout << "|";
    SetColor(GREEN, BLACK);
    std::cout << " " << player->mExpLevel; 
    ResetColor();
    std::cout << " |" << std::endl;

    std::cout << "+";
    for (int i = 0; i < 10; i++)
    {
        std::cout << "-";
    }
    std::cout << "+---+" << std::endl;
}

void DisplayPotionCount(Character* player)
{
    std::cout << "| ";
    SetColor(MAGENTA, BLACK);
    std::cout << player->mPotionCount;
    ResetColor();
    std::cout << " |" << std::endl;
    std::cout << "+---+" << std::endl;
}

bool Fight(Character* c1, Character* c2)
{
    Character* attackChar = c1;
    Character* defenseChar = c2;
    
    while (!c1->IsDead() && !c2->IsDead())
    {
        system("cls");
        DisplayHealthBar(c1);
        DisplayExpBar(c1);
        DisplayPotionCount(c1);

        attackChar->SpecialAbility();

        int damage = attackChar->DealDamage(defenseChar);

        std::cout << attackChar->mName << " just attacked " << defenseChar->mName << " for " << damage << " damage." << std::endl;
        std::cout << defenseChar->mName << " now has " << defenseChar->mHealth << " HP remaining." << std::endl << std::endl;

        Character* temp = attackChar;
        attackChar = defenseChar;
        defenseChar = temp;
        Sleep(500);
    }
    if (c1->IsDead())
    {
        std::cout << c2->mName << " won !" << std::endl;
        return false;
    }
    else
    {
        std::cout << c1->mName << " won !" << std::endl;
        return true;
    }
}

void NextEnnemie(int* pEnnemieStats)
{
    pEnnemieStats[0] = pEnnemieStats[0] + 5;
    pEnnemieStats[1] = pEnnemieStats[1] + 2;
    pEnnemieStats[2] = pEnnemieStats[2] + 1;
}

int GetExpGain(int* pEnnemieStats)
{
    return pEnnemieStats[0]  + pEnnemieStats[1] * 3 + pEnnemieStats[2] * 5;
}

void Game()
{
    Character* Player = new Archer();
    int EnnemieStats[3] = { 20, 2, 1 };

    while (!Player->IsDead())
    {
        Character Ennemie = Character("Ennemie", EnnemieStats[0], EnnemieStats[1], EnnemieStats[2]);
        if (Fight(Player, &Ennemie))
        {
            NextEnnemie(EnnemieStats);
            Player->GetPotion();

            SetColor(GREEN, BLACK);
            int expGain = GetExpGain(EnnemieStats);
            std::cout << "You gained " << expGain << " XP" << std::endl;
            Player->AddExp(expGain);
            ResetColor();

            if (Player->mPotionCount > 0)
            {
                Player->AskPotionUse();
            }
        }
    }
    std::cout << "YOU LOST" << std::endl;
}

int main()
{
    srand(time(NULL));
    Game();
}
