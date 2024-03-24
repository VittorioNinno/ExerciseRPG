// Character.cpp
#include "Character.h"
#include <iostream>

Character::Character(std::string name, int level, int health, int attack, int speed)
    : name(name), level(level), health(health), attack(attack), speed(speed) {}

Character::~Character() {}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << name << " has been defeated!\n";
    }
}

void Character::displayStats() const {
    std::cout << "Name: " << name << "\nLevel: " << level << "\nHealth: " << health << "\nAttack: " << attack << "\nSpeed: " << speed << '\n';
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::addBonus() {
    std::cout << "Base Character have no bonus\n";
}

void Character::characterAdvantage() const {
    std::cout << "Base Character have no advantage.\n";
}
