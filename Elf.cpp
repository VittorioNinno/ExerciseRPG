//Elf.cpp
#include "Elf.h"
#include <iostream>

Elf::Elf(std::string name, int health, int attack, int speed)
    : Character(name, health, attack, speed) {}

void Elf::characterAdvantage() const {
    std::cout << "\nElf advantage: +10 on Speed" << std::endl;
}

void Elf::addBonus() {
    speed += elfBonus;
}
