#include <string>
#include <iostream>

#include "koffer.h"
#include "packstueck.h"

Packstueck::Packstueck(int player, std::string stueck) {
    this->player = player;
    this->stueck = stueck;
}

Packstueck::~Packstueck() {
    delete naechstes;
}

bool Packstueck::einpacken(int player) {
    if (naechstes == nullptr) {
        std::string stueck;
        std::cout << "Welches Packstück möchtest du einpacken? ";
        std::cin >> stueck;

        naechstes = new Packstueck(player, stueck);
        return true;
    }
    else {
        return naechstes->einpacken(player);
    }
}

bool Packstueck::hat_gewonnen(int player, int anzahl) {
    if (naechstes == nullptr) {
        return false;
    }
    else {
        return naechstes->hat_gewonnen(player, anzahl);
    }
}

void Packstueck::print() {
    if (naechstes != nullptr) {
        naechstes->print();
    }
}