#include "Battle.h"
#include <iostream>

Battle::Battle() {}

void Battle::startBattle() {
    // Simulation not implemented in this version
}

void Battle::printBattleLog() {
    for (auto& it : battleLog) {
        cout << it << endl;
    }
}

int Battle::Result() {
    int hSum = 0, eSum = 0;
    for (auto& it : heroes) {
        if (it.getSuit().getDurability() > 0)
            hSum += it.getSuit().getPowerLevel() + it.getSuit().getDurability();
    }
    for (auto& it : enemies) {
        eSum += it.getSuit().getPowerLevel() + it.getSuit().getDurability();
    }
    return (hSum > eSum) ? 1 : (hSum < eSum) ? -1 : 0;
}

vector<string>& Battle::getBattleLog() { return battleLog; }
vector<Avenger>& Battle::getHeroes() { return heroes; }
vector<Avenger>& Battle::getEnemies() { return enemies; }

void Battle::addHero(Avenger& avenger) { heroes.push_back(avenger); }
void Battle::addEnemy(Avenger& avenger) { enemies.push_back(avenger); }

Avenger* Battle::findAvenger(string avName) {
    for (auto& hero : heroes) {
        if (hero.getName() == avName) return &hero;
    }
    for (auto& enemy : enemies) {
        if (enemy.getName() == avName) return &enemy;
    }
    return nullptr;
}
