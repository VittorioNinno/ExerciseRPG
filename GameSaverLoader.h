// GameSaverLoader.h
#pragma once
#include "Player.h"

class GameSaverLoader {
public:
    static void saveGame(const Player& player);
    static Player loadGame();
};