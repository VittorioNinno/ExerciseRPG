// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(std::string playerName, PlayerClass playerClass, int playerLevel, int playerHealth, int playerAttack, int playerSpeed)
    : Character(playerName, playerLevel, playerHealth, playerAttack, playerSpeed), playerClass(playerClass) {}

Player::~Player() {}

void Player::addBonus() {
    switch (playerClass) {
        case PlayerClass::Warrior:
            std::cout << "Warrior bonus: Increased health!\n";
            health += 10;
            break;
        case PlayerClass::Mage:
            std::cout << "Mage bonus: Increased attack!\n";
            attack += 10;
            break;
        case PlayerClass::Archer:
            std::cout << "Archer bonus: Increased speed!\n";
            speed += 10;
            break;
        case PlayerClass::Paladin:
            std::cout << "Paladin bonus: Increased health and defense!\n";
            health += 5;
            attack += 5;
            break;
        case PlayerClass::Thief:
            std::cout << "Thief bonus: Increased speed and attack!\n";
            speed += 10;
            attack += 5;
            break;
        case PlayerClass::Priest:
            std::cout << "Priest bonus: Increased health and special healing ability!\n";
            health += 5;
            break;
        case PlayerClass::Barbarian:
            std::cout << "Barbarian bonus: Increased attack and health regeneration!\n";
            attack += 10;
            break;
        case PlayerClass::Necromancer:
            std::cout << "Necromancer bonus: Dark magic powers and health leeching!\n";
            attack += 5;
            break;
        case PlayerClass::Ranger:
            std::cout << "Ranger bonus: Enhanced ranged attack and tracking skills!\n";
            attack += 5;
            break;
        case PlayerClass::Sorcerer:
            std::cout << "Sorcerer bonus: Mastery over elements and elemental resistance!\n";
            health += 5;
            break;
    }
}

void Player::characterAdvantage() const {
    switch (playerClass) {
        case PlayerClass::Warrior:
            std::cout << "Warrior advantage: High defense!\n";
            break;
        case PlayerClass::Mage:
            std::cout << "Mage advantage: Powerful spells!\n";
            break;
        case PlayerClass::Archer:
            std::cout << "Archer advantage: Precise attacks!\n";
            break;
        case PlayerClass::Paladin:
            std::cout << "Paladin advantage: Holy abilities and resilience!\n";
            break;
        case PlayerClass::Thief:
            std::cout << "Thief advantage: Stealth and critical strikes!\n";
            break;
        case PlayerClass::Priest:
            std::cout << "Priest advantage: Healing powers and divine protection!\n";
            break;
        case PlayerClass::Barbarian:
            std::cout << "Barbarian advantage: Berserker rage and resilience!\n";
            break;
        case PlayerClass::Necromancer:
            std::cout << "Necromancer advantage: Control over undead and dark magic!\n";
            break;
        case PlayerClass::Ranger:
            std::cout << "Ranger advantage: Nature affinity and survival skills!\n";
            break;
        case PlayerClass::Sorcerer:
            std::cout << "Sorcerer advantage: Elemental mastery and arcane knowledge!\n";
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