#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Player.h"
#include "Enemy.h"

using namespace std;

// Function to clear the console screen
void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to display title screen and wait for user input to continue
void showTitleScreen() {
    cout << "8888888 888b    888 8888888888 8888888 888b    888 8888888 88888888888 Y88b   d88P\n";
    cout << "  888   8888b   888 888          888   8888b   888   888       888      Y88b d88P\n";
    cout << "  888   88888b  888 888          888   88888b  888   888       888       Y88o88P\n";
    cout << "  888   888Y88b 888 8888888      888   888Y88b 888   888       888        Y888P\n";
    cout << "  888   888 Y88b888 888          888   888 Y88b888   888       888         888\n";
    cout << "  888   888  Y88888 888          888   888  Y88888   888       888         888\n";
    cout << "  888   888   Y8888 888          888   888   Y8888   888       888         888\n";
    cout << "8888888 888    Y888 888        8888888 888    Y888 8888888     888         888\n";
    cout << "\n\n";
    cout << "           888888b.         d8888 88888888888 88888888888 888      8888888888\n";
    cout << "           888  \"88b       d88888     888         888     888      888\n";
    cout << "           888  .88P      d88P888     888         888     888      888\n";
    cout << "           8888888K.     d88P 888     888         888     888      8888888\n";
    cout << "           888  \"Y88b   d88P  888     888         888     888      888\n";
    cout << "           888    888  d88P   888     888         888     888      888\n";
    cout << "           888   d88P d8888888888     888         888     888      888\n";
    cout << "           8888888P\" d88P     888     888         888     88888888 8888888888\n";
    
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Wait for user input
    clearConsole(); // Clear console after user presses Enter
}

// Function to create a player with user input
Player createPlayerWithInput() {
    string playerName;
    PlayerClass playerClass;

    // Loop until player's name is confirmed
    while (true) {
        clearConsole();
        // Prompt user to enter player's name
        cout << "Enter player's name: ";
        getline(cin, playerName);

        // Capitalize the first letter of the name
        if (!playerName.empty()) {
            playerName[0] = toupper(playerName[0]);
        }

        // Confirm player's name
        cout << "Confirm player's name: " << playerName << '\n';

        // Prompt user to confirm the name
        char confirmNameChoice;
        cout << "Is this name correct? (Y/N): ";
        cin >> confirmNameChoice;
        cin.ignore(); // Clear input buffer
        if (confirmNameChoice == 'Y' || confirmNameChoice == 'y') {
            break; // Exit loop if name is confirmed
        }
    }

    // Clear console
    clearConsole();

    // Loop until player's class is confirmed
    while (true) {
        clearConsole();
        // Display available player classes
        cout << "Choose player's class:\n";
        for (int i = 0; i < static_cast<int>(PlayerClass::Count); ++i) {
            string classString;
            Player::playerClassToString(static_cast<PlayerClass>(i), classString);
            cout << i + 1 << ". " << classString << '\n';
        }

        // Prompt user to choose player's class
        int classChoice;
        cout << "\nEnter the number corresponding to the class: ";
        cin >> classChoice;

        // Validate user input
        if (classChoice >= 1 && classChoice <= static_cast<int>(PlayerClass::Count)) {
            // Convert user's choice to PlayerClass enum
            playerClass = static_cast<PlayerClass>(classChoice - 1);

            // Display player's class and advantage
            Player player("", playerClass, 1, 0, 0, 0, 0);
            player.addBonus();

            // Prompt user to confirm the class
            char confirmClassChoice;
            cout << "Is this class correct? (Y/N): ";
            cin >> confirmClassChoice;
            cin.ignore(); // Clear input buffer
            if (confirmClassChoice == 'Y' || confirmClassChoice == 'y') {
                break; // Exit loop if class is confirmed
            }
        } else {
            cout << "Invalid choice. Please choose a number between 1 and " << static_cast<int>(PlayerClass::Count) << ".\n";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // Clear console
    clearConsole();

    // Create and return the player
    return Player(playerName, playerClass, 1, 100, 10, 10, 10); // Basic stats for level 1 player
}

// Function to generate a random enemy
Enemy generateRandomEnemy() {
    // Array of enemy types
    EnemyType enemyTypes[] = {
        EnemyType::Goblin, EnemyType::Skeleton, EnemyType::Ogre,
        EnemyType::Dragon, EnemyType::Troll, EnemyType::Vampire,
        EnemyType::Werewolf, EnemyType::Ghost, EnemyType::Wraith,
        EnemyType::Demon
    };

    // Array of random enemy names
    string enemyNames[] = {
        "Grog", "Bones", "Gronk", "Flameheart", "Grunt", "Dracula",
        "Fenrir", "Specter", "Shadow", "Inferno"
    };

    // Generate a random index for the enemy type
    int randomIndex = rand() % (sizeof(enemyTypes) / sizeof(enemyTypes[0]));
    // Generate a random index for the enemy name
    int randomNameIndex = rand() % (sizeof(enemyNames) / sizeof(enemyNames[0]));

    // Generate random attributes for the enemy
    int enemyLevel = 1; // Random level for example
    int enemyHealth = 50 + rand() % 101; // Random health between 50 and 150
    int enemyAttack = 5 + rand() % 16;    // Random attack between 5 and 20
    int enemyDefense = 5 + rand() % 16;   // Random defense between 5 and 20
    int enemySpeed = 5 + rand() % 16;     // Random speed between 5 and 20

    // Create and return the enemy with a random name
    return Enemy(enemyNames[randomNameIndex], enemyTypes[randomIndex], enemyLevel, enemyHealth, enemyAttack, enemyDefense, enemySpeed);
}

int main() {
    // Display the title screen and wait for user input
    showTitleScreen();

    // Generate player with user input
    Player player = createPlayerWithInput();

    // Add bonus to the player
    player.addBonus();
    
    // Display player's stats after adding bonus
    player.displayStats();

    // Genera un nemico casuale
    Enemy enemy = generateRandomEnemy();

    // Aggiungi bonus al nemico
    enemy.addBonus();

    // Visualizza le statistiche del nemico
    cout << "\nA wild enemy appears!\n";
    enemy.displayStats();

    return 0;
}
