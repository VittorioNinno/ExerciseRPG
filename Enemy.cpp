// Enemy.cpp
#include "Enemy.h"
#include <iostream>

Enemy::Enemy(std::string enemyName, EnemyType enemyType, int enemyLevel, int enemyHealth, int enemyAttack, int enemySpeed)
    : Character(enemyName, enemyLevel, enemyHealth, enemyAttack, enemySpeed), enemyType(enemyType) {}

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

void Enemy::characterAdvantage() const {
    switch (enemyType) {
        case EnemyType::Goblin:
            std::cout << "Goblin advantage: Quick and nimble!\n";
            break;
        case EnemyType::Skeleton:
            std::cout << "Skeleton advantage: Resilient to physical attacks!\n";
            break;
        case EnemyType::Ogre:
            std::cout << "Ogre advantage: Massive and powerful!\n";
            break;
        case EnemyType::Dragon:
            std::cout << "Dragon advantage: Ruler of the skies, fearsome and deadly!\n";
            break;
        case EnemyType::Troll:
            std::cout << "Troll advantage: Regenerates wounds, hard to kill!\n";
            break;
        case EnemyType::Vampire:
            std::cout << "Vampire advantage: Undead creature with unholy strength!\n";
            break;
        case EnemyType::Werewolf:
            std::cout << "Werewolf advantage: Lycanthrope, swift and deadly under the moon!\n";
            break;
        case EnemyType::Ghost:
            std::cout << "Ghost advantage: Incorporeal, difficult to harm with physical attacks!\n";
            break;
        case EnemyType::Wraith:
            std::cout << "Wraith advantage: Spectral being, drains life with its touch!\n";
            break;
        case EnemyType::Demon:
            std::cout << "Demon advantage: Fiendish entity, commands infernal powers!\n";
            break;
    }
}