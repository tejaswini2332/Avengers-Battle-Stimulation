#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include <string>
#include "Avenger.h"
using namespace std;

class Battle {
private:
    vector<Avenger> heroes;
    vector<Avenger> enemies;
    vector<string> battleLog;

public:
    Battle();

    void startBattle();
    void printBattleLog();
    int Result();
    vector<string>& getBattleLog();
    vector<Avenger>& getHeroes();
    vector<Avenger>& getEnemies();

    void addHero(Avenger& avenger);
    void addEnemy(Avenger& avenger);
    Avenger* findAvenger(string avName);
};

#endif
