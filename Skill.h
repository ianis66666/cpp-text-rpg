#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill {
private:
    std::string name;
    int damage;
    int mpCost;

public:
    Skill();
    Skill(const std::string& name, int damage, int mpCost);

    int use() const;
    void showInfo() const;
    int getDamage() const;
    int getMpCost() const;
    std::string getName() const;

    void setName(const std::string& name);
    void setDamage(int damage);
    void setMpCost(int mpCost);
};

#endif
