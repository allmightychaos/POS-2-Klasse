#include <stdexcept>
#include <iostream>

#include "rekursionen.h"

using namespace std;


int Rekursionen::summe(int n) {
    if (n < 0) {
        throw std::invalid_argument("n must be greater than 0");
    }
    else if (n == 0) {
        return 0;
    }
    return n + summe(n - 1);
}

void Rekursionen::print_array_backwards(int array[], int length) {
    if (length == 0) {
        return;
    }
    cout << array[length - 1] << " ";
    print_array_backwards(array, length - 1);
}

bool Rekursionen::is_palindrom(string s) {
    if (s.find(" ") != string::npos) {
        s.erase(s.find(" "), 1);
    }
    if (s.length() == 0 || s.length() == 1) {
        return true;
    }
    if (tolower(s[0]) == tolower(s[s.length() - 1])) {
        return is_palindrom(s.substr(1, s.length() - 2));
    }
    return false;
}

bool Rekursionen::binary_search(int array[], int start, int end, int value) {
    if (start > end) {
        return false;
    }
    int middle = (start + end) / 2;
    if (array[middle] == value) {
        return true;
    }
    else if (array[middle] > value) {
        return binary_search(array, start, middle - 1, value);
    }
    else {
        return binary_search(array, middle + 1, end, value);
    }
}

void Rekursionen::print_array(int array[], int length) {
    if (length == 0) {
        return;
    }
    cout << array[0] << " ";
    print_array(array + 1, length - 1);
}