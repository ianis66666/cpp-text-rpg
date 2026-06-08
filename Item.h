#ifndef ITEM_H
#define ITEM_H

#include <string>

class Player;

class Item {
private:
    std::string name;
    std::string type;
    int effectValue;
    int quantity;

public:
    Item();
    Item(const std::string& name, const std::string& type, int effectValue, int quantity);

    bool use(Player& player);
    void showInfo() const;
    bool isAvailable() const;

    std::string getName() const;
    std::string getType() const;
    int getEffectValue() const;
    int getQuantity() const;

    void setName(const std::string& name);
    void setType(const std::string& type);
    void setEffectValue(int effectValue);
    void setQuantity(int quantity);
};

#endif
