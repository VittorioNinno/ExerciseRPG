// Enemy.h
#pragma once

#include "Character.h"

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
    Enemy(std::string enemyName, EnemyType enemyType, int enemyLevel, int enemyHealth, int enemyAttack, int enemySpeed);
    virtual ~Enemy();

    void addBonus() override;
    void characterAdvantage() const override;

private:
    EnemyType enemyType;
};
