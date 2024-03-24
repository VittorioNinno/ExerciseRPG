// Enemy.h
#pragma once

#include "Character.h"
#include <string>
#include <random>

enum class EnemyType {
    Goblin,
    Skeleton,
    Ogre,
    Dragon,
    Troll,
    Vampire,
    Werewolf,
    Ghost,
    Wraith,
    Demon
};

class Enemy : public Character {
public:
    Enemy(std::string enemyName, EnemyType enemyType, int enemyLevel, int enemyHealth, int enemyAttack, int enemyDefense, int enemySpeed);
    virtual ~Enemy();

    void addBonus() override;

    int getGoldValue() const;

private:
    EnemyType enemyType;
    int minGoldValue;
    int maxGoldValue;
};
