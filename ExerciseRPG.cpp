#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Player.h"

using namespace std;

// Function to clear the console screen
void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to create a player with user input
Player createPlayerWithInput() {
    string playerName;
    PlayerClass playerClass;

    // Loop until player's name is confirmed
    while (true) {
        // Prompt user to enter player's name
        printf("Enter player's name: ");
        getline(cin, playerName);

        // Capitalize the first letter of the name
        if (!playerName.empty()) {
            playerName[0] = toupper(playerName[0]);
        }

        // Confirm player's name
        printf("Confirm player's name: %s\n", playerName.c_str());

        // Prompt user to confirm the name
        char confirmNameChoice;
        printf("Is this name correct? (Y/N): ");
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
        // Display available player classes
        printf("Choose player's class:\n");
        for (int i = 0; i < static_cast<int>(PlayerClass::Count); ++i) {
            string classString;
            Player::playerClassToString(static_cast<PlayerClass>(i), classString);
            printf("%d. %s\n", i + 1, classString.c_str());
        }

        // Prompt user to choose player's class
        int classChoice;
        printf("Enter the number corresponding to the class: ");
        cin >> classChoice;

        // Validate user input
        if (classChoice >= 1 && classChoice <= static_cast<int>(PlayerClass::Count)) {
            // Convert user's choice to PlayerClass enum
            playerClass = static_cast<PlayerClass>(classChoice - 1);

            // Display player's class and advantage
            Player player("", playerClass, 1, 0, 0, 0);
            printf("Class Advantage: ");
            player.characterAdvantage();

            // Prompt user to confirm the class
            char confirmClassChoice;
            printf("Is this class correct? (Y/N): ");
            cin >> confirmClassChoice;
            cin.ignore(); // Clear input buffer
            if (confirmClassChoice == 'Y' || confirmClassChoice == 'y') {
                break; // Exit loop if class is confirmed
            }
        } else {
            printf("Invalid choice. Please choose a number between 1 and %d.\n", static_cast<int>(PlayerClass::Count));
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // Clear console
    clearConsole();

    // Create and return the player
    return Player(playerName, playerClass, 1, 100, 10, 10); // Basic stats for level 1 player
}

int main() {
    // Generate player with user input
    Player player = createPlayerWithInput();

    // Display player's stats before adding bonus
    printf("\nPlayer's stats before adding bonus:\n");
    player.displayStats();

    // Add bonus to the player
    player.addBonus();

    // Display player's stats after adding bonus
    printf("\nPlayer's stats after adding bonus:\n");
    player.displayStats();

    return 0;
}
