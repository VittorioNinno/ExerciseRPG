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
    Player(std::string playerName, PlayerClass playerClass, int playerLevel, int playerHealth, int playerAttack, int playerDefense, int playerSpeed);
    virtual ~Player() override;

    void addBonus() override;

    static void playerClassToString(PlayerClass playerClass, std::string& classString);

    //  Getters
    PlayerClass getPlayerClass() const { return playerClass; }

    bool operator==(const Player& other) const {
        return (name == other.name &&
            playerClass == other.playerClass &&
            level == other.level &&
            health == other.health &&
            attack == other.attack &&
            defense == other.defense &&
            speed == other.speed);
    }

private:
    PlayerClass playerClass;
};