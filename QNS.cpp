#include "QNS.h"
#include <iostream>
#include <algorithm>

using namespace std;

QNS::QNS(int p, int d, int e, int h) {
    powerLevel = min(5000, p);
    durability = d;
    energyStorage = e;
    heatLevel = max(0, h);
}

QNS::QNS(const QNS& qns) :
    powerLevel(qns.getPowerLevel()), durability(qns.getDurability()),
    energyStorage(qns.getEnergyStorage()), heatLevel(qns.getHeatLevel()) {}

QNS::QNS() {
    powerLevel = 1000;
    durability = 500;
    energyStorage = 300;
    heatLevel = 0;
}

int QNS::getPowerLevel() const { return powerLevel; }
int QNS::getDurability() const { return durability; }
int QNS::getEnergyStorage() const { return energyStorage; }
int QNS::getHeatLevel() const { return heatLevel; }

void QNS::operator+(const QNS& otherSuit) {
    setPowerLevel(min(5000, powerLevel + otherSuit.energyStorage));
    setDurability(durability + otherSuit.durability);
    setEnergyStorage(energyStorage + otherSuit.powerLevel);
    setHeatLevel(max(0, heatLevel));
}

void QNS::operator-(int x) {
    setDurability(durability - x);
    setEnergyStorage(energyStorage + x);
    setHeatLevel(max(0, heatLevel + x));
}

void QNS::operator*(int x) {
    setPowerLevel(min(5000, powerLevel + (powerLevel * x) / 100));
    setEnergyStorage(energyStorage + 5 * x);
    setHeatLevel(max(0, heatLevel + x));
}

void QNS::operator/(int x) {
    setDurability(durability + x);
    setHeatLevel(max(0, heatLevel - x));
}

void QNS::boostPower(int x) {
    setPowerLevel(min(5000, powerLevel + (powerLevel * x) / 100));
    setEnergyStorage(energyStorage + 5 * x);
    setHeatLevel(max(0, heatLevel + x));
}

void QNS::boostPower(const QNS& otherSuit) {
    setPowerLevel(min(5000, powerLevel + otherSuit.energyStorage));
    setDurability(durability + otherSuit.durability);
    setEnergyStorage(energyStorage + otherSuit.powerLevel);
    setHeatLevel(max(0, heatLevel + otherSuit.heatLevel));
}

bool QNS::operator==(const QNS& otherSuit) const {
    return (powerLevel == otherSuit.getPowerLevel() && durability == otherSuit.getDurability());
}

bool QNS::operator<(const QNS& otherSuit) const {
    return (powerLevel + durability) < (otherSuit.getPowerLevel() + otherSuit.getDurability());
}

void QNS::setPowerLevel(int p) { powerLevel = p; }
void QNS::setDurability(int d) { durability = d; }
void QNS::setEnergyStorage(int e) { energyStorage = e; }
void QNS::setHeatLevel(int h) { heatLevel = h; }

void QNS::printStatus() {
    cout << powerLevel << " " << durability << " " << energyStorage << " " << heatLevel << endl;
}
