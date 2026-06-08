#include "Monster.h"

#include "Player.h"

#include <algorithm>
#include <iostream>

Monster::Monster() : name("Slime"), hp(50), maxHp(50), attackPower(8), rewardGold(10) {}

Monster::Monster(const std::string& name, int hp, int attackPower, int rewardGold)
    : name(name), hp(hp), maxHp(hp), attackPower(attackPower), rewardGold(rewardGold) {}

void Monster::attack(Player& player) const {
    std::cout << name << " attacks!" << std::endl;
    player.takeDamage(attackPower);
}

void Monster::takeDamage(int damage) {
    hp = std::max(0, hp - damage);
    std::cout << name << " took " << damage << " damage. "
              << "HP: " << hp << "/" << maxHp << std::endl;
}

bool Monster::isAlive() const {
    return hp > 0;
}

void Monster::showInfo() const {
    std::cout << "Monster: " << name
              << " | HP: " << hp << "/" << maxHp
              << " | Attack: " << attackPower
              << " | Reward: " << rewardGold << " gold" << std::endl;
}

std::string Monster::getName() const {
    return name;
}

int Monster::getHp() const {
    return hp;
}

int Monster::getMaxHp() const {
    return maxHp;
}

int Monster::getAttackPower() const {
    return attackPower;
}

int Monster::getRewardGold() const {
    return rewardGold;
}

void Monster::setName(const std::string& name) {
    this->name = name;
}

void Monster::setHp(int hp) {
    this->hp = hp;
    this->maxHp = hp;
}

void Monster::setAttackPower(int attackPower) {
    this->attackPower = attackPower;
}

void Monster::setRewardGold(int rewardGold) {
    this->rewardGold = rewardGold;
}
