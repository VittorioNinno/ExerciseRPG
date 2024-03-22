// Elf.h
#pragma once

#include "Character.h"

class Elf : public Character {
public:
    Elf(std::string name, int health, int attack, int speed);
    void characterAdvantage() const override;
    void addBonus() override;

protected:
    int const elfBonus = 10;
};
