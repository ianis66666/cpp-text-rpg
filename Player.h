#ifndef PLAYER_H
#define PLAYER_H

#include "Item.h"
#include "Skill.h"

#include <string>
#include <vector>

class Monster;

class Player {
private:
    std::string name;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int attackPower;
    int gold;
    std::vector<Item> items;
    std::vector<Skill> skills;

public:
    Player();
    Player(const std::string& name, int hp, int mp, int attackPower);

    void attack(Monster& monster) const;
    void takeDamage(int damage);
    bool useItem(int index);
    bool useSkill(int index, Monster& monster);
    bool isAlive() const;

    void heal(int amount);
    void restoreMp(int amount);
    void addGold(int amount);
    void addItem(const Item& item);
    void addSkill(const Skill& skill);
    void showStatus() const;
    void showItems() const;
    void showSkills() const;

    std::string getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getMp() const;
    int getMaxMp() const;
    int getAttackPower() const;
    int getGold() const;
    std::vector<Item>& getItems();
    const std::vector<Item>& getItems() const;
    const std::vector<Skill>& getSkills() const;

    void setName(const std::string& name);
    void setHp(int hp);
    void setMp(int mp);
    void setAttackPower(int attackPower);
    void setGold(int gold);
};

#endif
