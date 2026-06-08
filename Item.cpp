#include "Item.h"

#include "Player.h"

#include <iostream>

Item::Item() : name("Small Potion"), type("heal"), effectValue(20), quantity(1) {}

Item::Item(const std::string& name, const std::string& type, int effectValue, int quantity)
    : name(name), type(type), effectValue(effectValue), quantity(quantity) {}

bool Item::use(Player& player) {
    if (!isAvailable()) {
        std::cout << name << " is not available." << std::endl;
        return false;
    }

    if (type == "heal") {
        player.heal(effectValue);
        std::cout << "Used " << name << ". Restored " << effectValue << " HP." << std::endl;
    } else if (type == "mp") {
        player.restoreMp(effectValue);
        std::cout << "Used " << name << ". Restored " << effectValue << " MP." << std::endl;
    } else {
        std::cout << "Used " << name << ", but nothing happened." << std::endl;
    }

    quantity--;
    return true;
}

void Item::showInfo() const {
    std::cout << name << " | Type: " << type
              << " | Effect: " << effectValue
              << " | Quantity: " << quantity << std::endl;
}

bool Item::isAvailable() const {
    return quantity > 0;
}

std::string Item::getName() const {
    return name;
}

std::string Item::getType() const {
    return type;
}

int Item::getEffectValue() const {
    return effectValue;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setName(const std::string& name) {
    this->name = name;
}

void Item::setType(const std::string& type) {
    this->type = type;
}

void Item::setEffectValue(int effectValue) {
    this->effectValue = effectValue;
}

void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}
