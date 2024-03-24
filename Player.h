// Player.h
#pragma once

#include "Character.h"

enum class PlayerClass {
    Warrior,
    Mage,
    Archer,
    Paladin,
    Thief,
    Priest,
    Barbarian,
    Necromancer,
    Ranger,
    Sorcerer,
    Count
};

class Player : public Character {
public:
    Player(std::string playerName, PlayerClass playerClass, int playerLevel, int playerHealth, int playerAttack, int playerSpeed);
    virtual ~Player() override;

    void addBonus() override;
    void characterAdvantage() const override;

    static void playerClassToString(PlayerClass playerClass, std::string& classString);

private:
    PlayerClass playerClass;
};