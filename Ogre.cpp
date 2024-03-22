//  Ogre.cpp
#include "Ogre.h"
#include <iostream>

Ogre::Ogre(std::string name, int health, int attack, int speed)
    : Character(name, health, attack, speed) {}

void Ogre::characterAdvantage() const {
    std::cout << "\nOgre advantage: +20 on Attack" << std::endl;
}

void Ogre::addBonus() {
    attack += ogreBonus;
}
