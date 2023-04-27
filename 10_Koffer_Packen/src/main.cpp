#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "koffer.h"

using namespace std;

int main() {
    srand(time(0));

    int spielerAnzahl;
    cout << "Wie viele Spieler nehmen am Spiel teil? ";
    cin >> spielerAnzahl;

    vector<string> spielerNamen(spielerAnzahl);
    for (int i = 0; i < spielerAnzahl; i++) {
        cout << "Spieler " << i + 1 << " Name: ";
        cin >> spielerNamen[i];
    }

    if (spielerAnzahl < 2) {
        cout << "Tut mir leid " << spielerNamen[spielerAnzahl - 1] << ", dass Sie alleine sind, aber das Spiel ist für mindestens 2 Spieler." << endl;
        return 0;
    }
    else if (spielerAnzahl > 4) {
        cout << "Bitte sagen Sie ";
        for (int i = 4; i < spielerAnzahl - 2; i++) {
            cout << spielerNamen[i] << ", ";
        }
        cout << spielerNamen[spielerAnzahl - 2] << " und " << spielerNamen[spielerAnzahl - 1] << " nach Hause zu gehen." << endl;
        return 0;
    }

    // anfangsspieler zufall zwischen 1-4 und das dann -1 weil der vector bei 0 anfängt

    int anfangsspieler = rand() % spielerAnzahl;
    anfangsspieler -= 1;

    // Spiel:
    bool spiel = true;

    Koffer koffer;
    while (spiel == true) {
        cout << "Es ist " << spielerNamen[anfangsspieler] << "s Zug." << endl;
        koffer.einpacken(anfangsspieler);
        koffer.print();
        if (koffer.hat_gewonnen(anfangsspieler, 3)) {
            cout << spielerNamen[anfangsspieler] << " hat gewonnen!" << endl;
            spiel = false;
        }
        else {
            anfangsspieler++;
            if (anfangsspieler == spielerAnzahl) {
                anfangsspieler = 0;
            }
        }
    }
}