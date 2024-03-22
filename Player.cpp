// Player.cpp
#include "Player.h"
#include "Human.h"
#include "Elf.h"
#include "Ogre.h"

Player::Player() : playerCharacter(nullptr) {}

Player::~Player() {
}

void Player::clearConsole() const {
    // Platform-specific console clearing code
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Player::confirmChoice(std::string choiceType) {
    char confirmation;
    bool confirmed = false;

    std::cout << "Confirm your " << choiceType << " choice (Y/N): ";
    std::cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {
        confirmed = true;
    }
    else if (confirmation == 'N' || confirmation == 'n') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choiceType == "name") {
            playerName = readPlayerName();
            confirmChoice("name");
        }
        else if (choiceType == "race") {
            chooseRace();
            confirmChoice("race");
        }
        else {
            // Invalid choiceType
            std::cerr << "Invalid choiceType in confirmChoice function.\n";
            return;
        }
    }
    else {
        std::cout << "Invalid input. Please enter 'Y' or 'N'.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Player::chooseRace() {
    clearConsole();

    std::cout << "Choose your race:\n";
    std::cout << "1. Human\n";
    std::cout << "2. Elf\n";
    std::cout << "3. Ogre\n";

    int choice;
    while (!(std::cin >> choice) || choice < 1 || choice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid choice: ";
    }

    switch (choice) {
    case 1:
        playerCharacter = std::make_unique<Human>(playerName, 100, 20, 30);
        break;
    case 2:
        playerCharacter = std::make_unique<Elf>(playerName, 80, 25, 40);
        break;
    case 3:
        playerCharacter = std::make_unique<Ogre>(playerName, 120, 15, 25);
        break;
    default:
        std::cout << "Invalid choice. Defaulting to Human.\n";
        playerCharacter = std::make_unique<Human>("", 100, 20, 30);
        break;
    }
    playerCharacter->addBonus();
    playerCharacter->characterAdvantage();
}

void Player::createCharacter() {
    playerName = readPlayerName();
    confirmChoice("name");

    chooseRace();
    confirmChoice("race");
}

std::string Player::readPlayerName() const {
    std::cout << "Enter your character's name: ";
    std::string playerName;
    std::getline(std::cin, playerName);

    // Capitalize the first letter
    if (!playerName.empty()) {
        playerName[0] = std::toupper(playerName[0]);
    }

    return playerName;
}

Character* Player::getPlayerCharacter() const {
    clearConsole();
    return playerCharacter.get();
}