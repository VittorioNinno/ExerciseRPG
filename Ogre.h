//Ogre.h
#pragma once

#include "Character.h"

class Ogre : public Character {
public:
    Ogre(std::string name, int health, int attack, int speed);
    void characterAdvantage() const override;
    void addBonus() override;

private:
    int const ogreBonus = 10;
};
