#include "Player.h"

int main() {
    Player player;
    player.createCharacter();

    // Display the created character's stats
    if (player.getPlayerCharacter()) {
        player.getPlayerCharacter()->displayStats();
    }

    return 0;
}
