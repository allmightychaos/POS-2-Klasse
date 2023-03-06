#include "math.h"
#include <iostream>

using namespace std;

int main() {
    math m;

    double power = m.power(3, 3);
    int fact = m.fact(5);
    int ggT = m.ggT(15, 6);
    int fibo = m.fibo(7);

    cout << "Power: " << power << "\n";
    cout << "Fact: " << fact << "\n";
    cout << "ggT: " << ggT << "\n";
    cout << "Fibo: " << fibo << "\n";

    return 0;
}