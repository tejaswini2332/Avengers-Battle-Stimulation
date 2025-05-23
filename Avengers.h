#ifndef AVENGER_H
#define AVENGER_H

#include <string>
#include "QNS.h"
using namespace std;

class Avenger {
private:
    string name;
    QNS suit;
    int attackStrength;

public:
    Avenger();
    Avenger(string avName, QNS avSuit, int strength);

    bool attack(Avenger* enemy);
    bool upgradeSuit();
    void repair(int x);
    void boostPower(int x);
    void boostPower(const QNS& other);
    void printStatus();

    string getName();
    QNS getSuit();
    int getAttackStrength();

    void setName(string avName);
    void setSuit(QNS avSuit);
    void setAttackStrength(int strength);
};

extern queue<QNS> Q;

#endif
