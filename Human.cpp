// Human.cpp
#include "Human.h"
#include <iostream>

Human::Human(std::string name, int health, int attack, int speed)
    : Character(name, health, attack, speed) {}

void Human::characterAdvantage() const {
    std::cout << "\nHuman bonus: +15 on Health." << std::endl;
}

void Human::addBonus() {
    health += humanBonus;
}
