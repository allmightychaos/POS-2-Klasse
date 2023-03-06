#include "math.h"

double math::power(double x, int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return x * power(x, n - 1);
    }
}

long math::fact(int n) { 
    if (n == 1) {
        return 1;
    }
    else {
        return fact(n - 1) * n;
    }
}

int math::ggT(int x, int y) {
    if (x == y) {
        return x;
    }
    else if (x > y) {
        return ggT(x - y, y);
    }
    else {
        return ggT(x, y - x);
    }
}

long math::fibo(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibo(n - 1) + fibo(n - 2);
    }
}