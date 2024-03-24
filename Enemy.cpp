// Enemy.cpp
#include "Enemy.h"
#include <iostream>

Enemy::Enemy(std::string enemyName, EnemyType enemyType, int enemyLevel, int enemyHealth, int enemyAttack, int enemyDefense, int enemySpeed)
    : Character(enemyName, enemyLevel, enemyHealth, enemyAttack, enemyDefense, enemySpeed), enemyType(enemyType), minGoldValue(0), maxGoldValue(0) {
    // Setting gold values based on enemy type
    switch (enemyType) {
    case EnemyType::Goblin:
        minGoldValue = 10;
        maxGoldValue = 20;
        break;
    case EnemyType::Skeleton:
        minGoldValue = 15;
        maxGoldValue = 25;
        break;
    case EnemyType::Ogre:
        minGoldValue = 30;
        maxGoldValue = 40;
        break;
    case EnemyType::Dragon:
        minGoldValue = 100;
        maxGoldValue = 150;
        break;
    case EnemyType::Troll:
        minGoldValue = 25;
        maxGoldValue = 35;
        break;
    case EnemyType::Vampire:
        minGoldValue = 50;
        maxGoldValue = 70;
        break;
    case EnemyType::Werewolf:
        minGoldValue = 40;
        maxGoldValue = 60;
        break;
    case EnemyType::Ghost:
        minGoldValue = 20;
        maxGoldValue = 30;
        break;
    case EnemyType::Wraith:
        minGoldValue = 35;
        maxGoldValue = 45;
        break;
    case EnemyType::Demon:
        minGoldValue = 80;
        maxGoldValue = 100;
        break;
    }
}

Enemy::~Enemy() {}

void Enemy::addBonus() {
    switch (enemyType) {
        case EnemyType::Goblin:
            std::cout << "Goblin bonus: Increased attack!\n";
            attack += 5;
            break;
        case EnemyType::Skeleton:
            std::cout << "Skeleton bonus: Increased speed!\n";
            speed += 5;
            break;
        case EnemyType::Ogre:
            std::cout << "Ogre bonus: Increased health and attack!\n";
            health += 20;
            attack += 10;
            break;
        case EnemyType::Dragon:
            std::cout << "Dragon bonus: Massive health and devastating fire breath!\n";
            health += 100;
            attack += 30;
            break;
        case EnemyType::Troll:
            std::cout << "Troll bonus: High regeneration and strength!\n";
            health += 50;
            break;
        case EnemyType::Vampire:
            std::cout << "Vampire bonus: Immortality and life-stealing abilities!\n";
            attack += 20;
            break;
        case EnemyType::Werewolf:
            std::cout << "Werewolf bonus: Enhanced senses and ferocious attacks!\n";
            attack += 15;
            speed += 10;
            break;
        case EnemyType::Ghost:
            std::cout << "Ghost bonus: Intangibility and spectral attacks!\n";
            attack += 10;
            break;
        case EnemyType::Wraith:
            std::cout << "Wraith bonus: Ethereal form and soul-draining abilities!\n";
            health += 30;
            attack += 15;
            break;
        case EnemyType::Demon:
            std::cout << "Demon bonus: Infernal powers and demonic strength!\n";
            health += 50;
            attack += 25;
            break;
    }
}

int Enemy::getGoldValue() const {
    // Generate a random value within the range [minGoldValue, maxGoldValue]
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minGoldValue, maxGoldValue);
    return dis(gen);
}