// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(std::string playerName, PlayerClass playerClass, int playerLevel, int playerHealth, int playerAttack, int playerDefense, int playerSpeed)
    : Character(playerName, playerLevel, playerHealth, playerAttack, playerDefense, playerSpeed), playerClass(playerClass) {}

Player::~Player() {}

void Player::addBonus() {
    switch (playerClass) {
        case PlayerClass::Warrior:
            std::cout << "\nWarrior bonus: Increased health and defense!\n";
            health += 15;
            defense += 5;
            break;
        case PlayerClass::Mage:
            std::cout << "\nMage bonus: Increased attack and speed!\n";
            attack += 15;
            speed += 5;
            break;
        case PlayerClass::Archer:
            std::cout << "\nArcher bonus: Increased attack and speed!\n";
            attack += 15;
            speed += 5;
            break;
        case PlayerClass::Paladin:
            std::cout << "\nPaladin bonus: Balanced boost to all stats!\n";
            health += 10;
            attack += 10;
            defense += 10;
            speed += 10;
            break;
        case PlayerClass::Thief:
            std::cout << "\nThief bonus: Increased speed and critical chance!\n";
            speed += 15;
            attack += 5;
            break;
        case PlayerClass::Priest:
            std::cout << "\nPriest bonus: Enhanced health and healing!\n";
            health += 20;
            defense += 5;
            break;
        case PlayerClass::Barbarian:
            std::cout << "\nBarbarian bonus: Increased health and attack!\n";
            health += 20;
            attack += 10;
            break;
        case PlayerClass::Necromancer:
            std::cout << "\nNecromancer bonus: Dark powers boost attack and defense!\n";
            attack += 15;
            defense += 10;
            break;
        case PlayerClass::Ranger:
            std::cout << "\nRanger bonus: Enhanced attack and speed!\n";
            attack += 15;
            speed += 5;
            break;
        case PlayerClass::Sorcerer:
            std::cout << "\nSorcerer bonus: Increased health and spellcasting prowess!\n";
            health += 20;
            attack += 5;
            break;
    default:
            break;
    }
}

void Player::playerClassToString(PlayerClass playerClass, std::string& classString) {
    switch (playerClass) {
        case PlayerClass::Warrior:
            classString = "Warrior";
            break;
        case PlayerClass::Mage:
            classString = "Mage";
            break;
        case PlayerClass::Archer:
            classString = "Archer";
            break;
        case PlayerClass::Paladin:
            classString = "Paladin";
            break;
        case PlayerClass::Thief:
            classString = "Thief";
            break;
        case PlayerClass::Priest:
            classString = "Priest";
            break;
        case PlayerClass::Barbarian:
            classString = "Barbarian";
            break;
        case PlayerClass::Necromancer:
            classString = "Necromancer";
            break;
        case PlayerClass::Ranger:
            classString = "Ranger";
            break;
        case PlayerClass::Sorcerer:
            classString = "Sorcerer";
            break;
    }
}