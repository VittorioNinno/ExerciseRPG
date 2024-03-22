// Human.h
#pragma once

#include "Character.h"

class Human : public Character {
public:
    Human(std::string name, int health, int attack, int speed);
    void characterAdvantage() const override;
    void addBonus() override;

private:
    int const humanBonus = 15;
};
