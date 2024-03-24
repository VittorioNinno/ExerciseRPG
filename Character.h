// Character.h
#pragma once
#include <string>

class Character {
public:
    Character(std::string name, int level, int health, int attack, int defense, int speed);
    virtual ~Character();

    void takeDamage(int damage);
    void displayStats() const;
    bool isAlive() const;

    virtual void addBonus();
    virtual void characterAdvantage() const;

protected:
    std::string name;
    int level;
    int health;
    int attack;
    int defense;
    int speed;
};

