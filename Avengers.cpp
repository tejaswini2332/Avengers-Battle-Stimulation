#include "Avenger.h"
#include <iostream>
#include <queue>

using namespace std;

queue<QNS> Q;

Avenger::Avenger() {
    name = "Default Avenger";
    suit = QNS();
    attackStrength = 0;
}

Avenger::Avenger(string avName, QNS avSuit, int strength) {
    name = avName;
    suit = avSuit;
    attackStrength = strength;
}

bool Avenger::attack(Avenger* enemy) {
    if (suit.getDurability() > 0 && suit.getHeatLevel() <= 500 && enemy->getSuit().getDurability() > 0) {
        enemy->suit - attackStrength;
        return true;
    }
    return false;
}

bool Avenger::upgradeSuit() {
    if (!Q.empty()) {
        suit + Q.front();
        Q.pop();
        return true;
    }
    return false;
}

void Avenger::repair(int x) {
    suit / x;
}

void Avenger::boostPower(int x) {
    suit.boostPower(x);
}

void Avenger::boostPower(const QNS& other) {
    suit.boostPower(other);
}

void Avenger::printStatus() {
    cout << name << " ";
    suit.printStatus();
}

string Avenger::getName() { return name; }
QNS Avenger::getSuit() { return suit; }
int Avenger::getAttackStrength() { return attackStrength; }

void Avenger::setName(string avName) { name = avName; }
void Avenger::setSuit(QNS avSuit) { suit = avSuit; }
void Avenger::setAttackStrength(int strength) { attackStrength = strength; }
