#include "bits/stdc++.h"
using namespace std;

int main(){
    int k, n, m;
    cin >> k >> n >> m;
    Battle battle;
    for(int i = 0; i < k; i++) {
        int p, e, d, h;
        cin >> p >> e >> d >> h;
        Q.push(QNS(p, e, d, h));
    }
    for(int i = 0; i < n; i++) {
        string avName;
        int strength;
        cin >> avName >> strength;
        if (!Q.empty()) {
            Avenger av(avName, Q.front(), strength);
            battle.addHero(av);
            Q.pop();
        } else {
            cout << avName << " is out of fight\n";
        }
    }
    for(int i = 0; i < m; i++) {
        string avName;
        int strength;
        cin >> avName >> strength;
        if (!Q.empty()) {
            Avenger av(avName, Q.front(), strength);
            battle.addEnemy(av);
            Q.pop();
        } else {
            cout << avName << " is out of fight\n";
        }
    }

    string command;
    while (cin >> command) {
        if (command == "BattleBegin") {
            battle.getBattleLog().push_back("Battle begins");
        } else if (command == "Attack") {
            string av1, av2;
            cin >> av1 >> av2;
            Avenger* attacker = battle.findAvenger(av1);
            Avenger* target = battle.findAvenger(av2);
            if (attacker && target && attacker->attack(target)) {
                battle.getBattleLog().push_back(av1 + " attacks " + av2);
                if (target->getSuit().getDurability() <= 0) {
                    battle.getBattleLog().push_back(av2 + " suit destroyed");
                } else if (target->getSuit().getHeatLevel() > 500) {
                    battle.getBattleLog().push_back(av2 + " suit overheated");
                }
            } else {
                if (attacker && attacker->getSuit().getDurability() <= 0) {
                    battle.getBattleLog().push_back(av1 + " is out of fight");
                }
            }
        } else if (command == "Repair") {
            string name;
            int x;
            cin >> name >> x;
            Avenger* av = battle.findAvenger(name);
            if (av) {
                av->repair(x);
                battle.getBattleLog().push_back(name + " repaired");
            }
        } else if (command == "BoostPowerByFactor") {
            string name;
            int x;
            cin >> name >> x;
            Avenger* av = battle.findAvenger(name);
            if (av) {
                av->boostPower(x);
                battle.getBattleLog().push_back(name + " boosted power by factor " + to_string(x));
            }
        } else if (command == "BoostPowerBySuit") {
            string name1, name2;
            cin >> name1 >> name2;
            Avenger* av1 = battle.findAvenger(name1);
            Avenger* av2 = battle.findAvenger(name2);
            if (av1 && av2) {
                av1->boostPower(av2->getSuit());
                battle.getBattleLog().push_back(name1 + " boosted power using " + name2 + "'s suit");
            }
        } else if (command == "UpgradeSuit") {
            string name;
            cin >> name;
            Avenger* av = battle.findAvenger(name);
            if (av && av->upgradeSuit()) {
                battle.getBattleLog().push_back(name + " upgraded suit");
            }
        } else if (command == "Status") {
            for (auto& av : battle.getHeroes()) av.printStatus();
            for (auto& av : battle.getEnemies()) av.printStatus();
        } else if (command == "BattleLog") {
            battle.printBattleLog();
        } else if (command == "Result") {
            int result = battle.Result();
            if (result == 1) cout << "Heroes won\n";
            else if (result == -1) cout << "Enemies won\n";
            else cout << "Draw\n";
        } else if (command == "End") {
            break;
        }
    }

    return 0;
}
