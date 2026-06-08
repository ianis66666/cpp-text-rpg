#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Player;

class Monster {
private:
    std::string name;
    int hp;
    int maxHp;
    int attackPower;
    int rewardGold;

public:
    Monster();
    Monster(const std::string& name, int hp, int attackPower, int rewardGold);

    void attack(Player& player) const;
    void takeDamage(int damage);
    bool isAlive() const;
    void showInfo() const;

    std::string getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getAttackPower() const;
    int getRewardGold() const;

    void setName(const std::string& name);
    void setHp(int hp);
    void setAttackPower(int attackPower);
    void setRewardGold(int rewardGold);
};

#endif
