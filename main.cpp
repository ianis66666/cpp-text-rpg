#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"

#include <ctime>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <vector>

using namespace std;

int readInt(int minValue, int maxValue) {
    int choice;
    while (true) {
        cout << "Enter choice (" << minValue << "-" << maxValue << "): ";
        if (cin >> choice && choice >= minValue && choice <= maxValue) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "Invalid input. Please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void showTitle() {
    cout << "======================================" << endl;
    cout << "       Dungeon Quest Text RPG" << endl;
    cout << "======================================" << endl;
    cout << "A simple C++ CLI RPG using OOP classes." << endl;
}

void randomEvent(Player& player, mt19937& rng) {
    uniform_int_distribution<int> eventChance(1, 100);
    int roll = eventChance(rng);

    if (roll <= 20) {
        cout << "\nRandom Event: You found a small fountain and recovered 10 HP." << endl;
        player.heal(10);
    } else if (roll <= 35) {
        cout << "\nRandom Event: You found a mana crystal and recovered 8 MP." << endl;
        player.restoreMp(8);
    } else if (roll <= 45) {
        cout << "\nRandom Event: A trap arrow hits you!" << endl;
        player.takeDamage(6);
    }
}

bool playerTurn(Player& player, Monster& monster) {
    cout << "\n== Your Turn ==" << endl;
    cout << "1. Normal Attack" << endl;
    cout << "2. Use Skill" << endl;
    cout << "3. Use Item" << endl;
    cout << "4. Show Status" << endl;

    int choice = readInt(1, 4);
    if (choice == 1) {
        player.attack(monster);
        return true;
    }

    if (choice == 2) {
        player.showSkills();
        cout << "0. Back" << endl;
        int skillChoice = readInt(0, static_cast<int>(player.getSkills().size()));
        if (skillChoice == 0) {
            return false;
        }
        return player.useSkill(skillChoice - 1, monster);
    }

    if (choice == 3) {
        player.showItems();
        cout << "0. Back" << endl;
        int itemChoice = readInt(0, static_cast<int>(player.getItems().size()));
        if (itemChoice == 0) {
            return false;
        }
        return player.useItem(itemChoice - 1);
    }

    player.showStatus();
    monster.showInfo();
    return false;
}

bool battle(Player& player, Monster& monster) {
    cout << "\nA wild " << monster.getName() << " appears!" << endl;
    monster.showInfo();

    while (player.isAlive() && monster.isAlive()) {
        bool actionUsed = false;
        while (!actionUsed) {
            actionUsed = playerTurn(player, monster);
        }

        if (!monster.isAlive()) {
            cout << "\nYou defeated " << monster.getName() << "!" << endl;
            cout << "Reward: " << monster.getRewardGold() << " gold" << endl;
            player.addGold(monster.getRewardGold());
            return true;
        }

        cout << "\n== Monster Turn ==" << endl;
        monster.attack(player);

        if (!player.isAlive()) {
            cout << "\nYou were defeated by " << monster.getName() << "." << endl;
            return false;
        }
    }

    return player.isAlive();
}

int main() {
    mt19937 rng(static_cast<unsigned int>(time(nullptr)));

    showTitle();

    cout << "\nEnter your hero name: ";
    string playerName;
    getline(cin, playerName);
    if (playerName.empty()) {
        playerName = "Hero";
    }

    Player player(playerName, 130, 50, 18);
    player.addSkill(Skill("Fire Slash", 32, 12));
    player.addSkill(Skill("Thunder Strike", 45, 20));
    player.addItem(Item("Small Potion", "heal", 30, 3));
    player.addItem(Item("Mana Potion", "mp", 20, 2));

    vector<Monster> monsters = {
        Monster("Slime", 55, 8, 15),
        Monster("Goblin", 80, 12, 25),
        Monster("Dark Knight", 120, 18, 50)
    };

    cout << "\nStory: You enter a dungeon to recover the lost crystal." << endl;
    cout << "Defeat all monsters to win the game." << endl;

    for (int stage = 0; stage < static_cast<int>(monsters.size()); stage++) {
        cout << "\n========== Stage " << stage + 1 << " ==========" << endl;
        randomEvent(player, rng);

        if (!player.isAlive()) {
            cout << "\nGame Over. The dungeon trap defeated you." << endl;
            return 0;
        }

        bool won = battle(player, monsters[stage]);
        if (!won) {
            cout << "\nGame Over." << endl;
            return 0;
        }

        if (stage < static_cast<int>(monsters.size()) - 1) {
            cout << "\nYou take a short rest before moving deeper into the dungeon." << endl;
            player.heal(15);
            player.restoreMp(10);
        }
    }

    cout << "\n======================================" << endl;
    cout << "Victory! " << player.getName() << " recovered the lost crystal." << endl;
    cout << "Final gold: " << player.getGold() << endl;
    cout << "Thank you for playing Dungeon Quest Text RPG." << endl;
    cout << "======================================" << endl;

    return 0;
}
