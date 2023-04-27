#ifndef KOFFER_H
#define KOFFER_H

#include <string>
#include "packstueck.h"

class Koffer {
private:
    Packstueck *erstes;

public:
    Koffer();
    ~Koffer();
    bool einpacken(int player);
    bool hat_gewonnen(int player, int anzahl);
    void print();
};

#endif