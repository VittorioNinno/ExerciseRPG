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

    //Getters for individual variables
    std::string getName() const { return name; }
    int getLevel() const { return level; }
    int getHealth() const { return health; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getSpeed() const { return speed; }

protected:
    std::string name;
    int level;
    int health;
    int attack;
    int defense;
    int speed;
};

