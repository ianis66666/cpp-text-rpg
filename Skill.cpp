#include "Skill.h"

#include <iostream>

Skill::Skill() : name("Basic Strike"), damage(10), mpCost(0) {}

Skill::Skill(const std::string& name, int damage, int mpCost)
    : name(name), damage(damage), mpCost(mpCost) {}

int Skill::use() const {
    std::cout << "Used skill: " << name << "!" << std::endl;
    return damage;
}

void Skill::showInfo() const {
    std::cout << name << " | Damage: " << damage << " | MP Cost: " << mpCost << std::endl;
}

int Skill::getDamage() const {
    return damage;
}

int Skill::getMpCost() const {
    return mpCost;
}

std::string Skill::getName() const {
    return name;
}

void Skill::setName(const std::string& name) {
    this->name = name;
}

void Skill::setDamage(int damage) {
    this->damage = damage;
}

void Skill::setMpCost(int mpCost) {
    this->mpCost = mpCost;
}
