// Player.h
#pragma once

#include <iostream>
#include <limits>
#include <memory>
#include "Character.h"

class Player {
public:
    Player();
    ~Player();

    void chooseRace();
    void createCharacter();

    Character* getPlayerCharacter() const;

private:
    std::string playerName;
    std::unique_ptr<Character> playerCharacter;
    std::string readPlayerName() const;
    void clearConsole() const;
    void confirmChoice(std::string choiceType);
    void confirmName();
};
