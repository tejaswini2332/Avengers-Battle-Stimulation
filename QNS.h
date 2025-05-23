#ifndef QNS_H
#define QNS_H

class QNS {
private:
    int powerLevel;
    int durability;
    int energyStorage;
    int heatLevel;

public:
    QNS(int p, int d, int e, int h);
    QNS(const QNS& qns);
    QNS();

    int getPowerLevel() const;
    int getDurability() const;
    int getEnergyStorage() const;
    int getHeatLevel() const;

    void operator+(const QNS& otherSuit);
    void operator-(int x);
    void operator*(int x);
    void operator/(int x);

    void boostPower(int x);
    void boostPower(const QNS& otherSuit);

    bool operator==(const QNS& otherSuit) const;
    bool operator<(const QNS& otherSuit) const;

    void setPowerLevel(int p);
    void setDurability(int d);
    void setEnergyStorage(int e);
    void setHeatLevel(int h);

    void printStatus();
};

#endif
