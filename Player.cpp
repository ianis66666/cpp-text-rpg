#include "Player.h"

#include "Monster.h"

#include <algorithm>
#include <iostream>

Player::Player() : name("Hero"), hp(120), maxHp(120), mp(40), maxMp(40), attackPower(18), gold(0) {}

Player::Player(const std::string& name, int hp, int mp, int attackPower)
    : name(name), hp(hp), maxHp(hp), mp(mp), maxMp(mp), attackPower(attackPower), gold(0) {}

void Player::attack(Monster& monster) const {
    std::cout << name << " uses a normal attack!" << std::endl;
    monster.takeDamage(attackPower);
}

void Player::takeDamage(int damage) {
    hp = std::max(0, hp - damage);
    std::cout << name << " took " << damage << " damage. "
              << "HP: " << hp << "/" << maxHp << std::endl;
}

bool Player::useItem(int index) {
    if (index < 0 || index >= static_cast<int>(items.size())) {
        std::cout << "Invalid item choice." << std::endl;
        return false;
    }

    return items[index].use(*this);
}

bool Player::useSkill(int index, Monster& monster) {
    if (index < 0 || index >= static_cast<int>(skills.size())) {
        std::cout << "Invalid skill choice." << std::endl;
        return false;
    }

    const Skill& skill = skills[index];
    if (mp < skill.getMpCost()) {
        std::cout << "Not enough MP to use " << skill.getName() << "." << std::endl;
        return false;
    }

    mp -= skill.getMpCost();
    int damage = skill.use();
    monster.takeDamage(damage);
    return true;
}

bool Player::isAlive() const {
    return hp > 0;
}

void Player::heal(int amount) {
    hp = std::min(maxHp, hp + amount);
}

void Player::restoreMp(int amount) {
    mp = std::min(maxMp, mp + amount);
}

void Player::addGold(int amount) {
    gold += amount;
}

void Player::addItem(const Item& item) {
    items.push_back(item);
}

void Player::addSkill(const Skill& skill) {
    skills.push_back(skill);
}

void Player::showStatus() const {
    std::cout << "\n== Player Status ==" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << hp << "/" << maxHp << std::endl;
    std::cout << "MP: " << mp << "/" << maxMp << std::endl;
    std::cout << "Attack: " << attackPower << std::endl;
    std::cout << "Gold: " << gold << std::endl;
}

void Player::showItems() const {
    std::cout << "\n== Items ==" << std::endl;
    if (items.empty()) {
        std::cout << "No items." << std::endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(items.size()); i++) {
        std::cout << i + 1 << ". ";
        items[i].showInfo();
    }
}

void Player::showSkills() const {
    std::cout << "\n== Skills ==" << std::endl;
    if (skills.empty()) {
        std::cout << "No skills." << std::endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(skills.size()); i++) {
        std::cout << i + 1 << ". ";
        skills[i].showInfo();
    }
}

std::string Player::getName() const {
    return name;
}

int Player::getHp() const {
    return hp;
}

int Player::getMaxHp() const {
    return maxHp;
}

int Player::getMp() const {
    return mp;
}

int Player::getMaxMp() const {
    return maxMp;
}

int Player::getAttackPower() const {
    return attackPower;
}

int Player::getGold() const {
    return gold;
}

std::vector<Item>& Player::getItems() {
    return items;
}

const std::vector<Item>& Player::getItems() const {
    return items;
}

const std::vector<Skill>& Player::getSkills() const {
    return skills;
}

void Player::setName(const std::string& name) {
    this->name = name;
}

void Player::setHp(int hp) {
    this->hp = hp;
    this->maxHp = hp;
}

void Player::setMp(int mp) {
    this->mp = mp;
    this->maxMp = mp;
}

void Player::setAttackPower(int attackPower) {
    this->attackPower = attackPower;
}

void Player::setGold(int gold) {
    this->gold = gold;
}
