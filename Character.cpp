// Character.cpp
#include "Character.h"
#include <iostream>

Character::Character(std::string name, int health, int attack, int speed)
    : name(name), health(health), attack(attack), speed(speed) {}

Character::~Character() {}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << name << " has been defeated!" << std::endl;
    }
}

void Character::displayStats() const {
    std::cout << "Name: " << name << "\nHealth: " << health << "\nAttack: " << attack << "\nSpeed: " << speed << std::endl;
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::addBonus() {
    std::cout << "Base Character have no bonus" << std::endl;
}

void Character::characterAdvantage() const {
    std::cout << "Base Character have no advantage." << std::endl;
}
