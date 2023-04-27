#include <string>
#include <iostream>

#include "koffer.h"

Koffer::Koffer() {
    erstes = nullptr;
}

Koffer::~Koffer() {
    delete erstes;
}

bool Koffer::einpacken(int player) {
    if (erstes == nullptr) {
        std::string stueck;
        std::cout << "Welches Packstück möchtest du einpacken? ";
        std::cin >> stueck;

        erstes = new Packstueck(player, stueck);
        return true;
    }
    else {
        return erstes->einpacken(player);
    }
}

bool Koffer::hat_gewonnen(int player, int anzahl) {
    if (erstes == nullptr) {
        return false;
    }
    else {
        return erstes->hat_gewonnen(player, anzahl);
    }
}

void Koffer::print() {
    if (erstes != nullptr) {
        erstes->print();
    }
}