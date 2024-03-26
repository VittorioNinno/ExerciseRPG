// GameSaverLoader.cpp
#include "GameSaverLoader.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void GameSaverLoader::saveGame(const Player& player) {
    ofstream file("savegame.txt");
    if (file.is_open()) {
        file << player.getName() << "\n";
        file << static_cast<int>(player.getPlayerClass()) << "\n";
        file << player.getLevel() << "\n";
        file << player.getHealth() << "\n";
        file << player.getAttack() << "\n";
        file << player.getDefense() << "\n";
        file << player.getSpeed() << "\n";
        cout << "Game saved.\n";
    }
    else {
        cout << "Unable to open save file.\n";
    }
    file.close();
}

Player GameSaverLoader::loadGame() {
    ifstream file("savegame.txt");
    if (file.is_open()) {
        string playerName;
        int playerClassInt, level, health, attack, defense, speed;
        getline(file, playerName);
        file >> playerClassInt >> level >> health >> attack >> defense >> speed;
        PlayerClass playerClass = static_cast<PlayerClass>(playerClassInt);
        Player loadedPlayer(playerName, playerClass, level, health, attack, defense, speed);
        cout << "Game loaded.\n";
        return loadedPlayer;
    }
    else {
        cout << "No save file found. Starting new game.\n";
        return Player("", PlayerClass::Warrior, 1, 100, 10, 10, 10); // Default values
    }
    file.close();
}
