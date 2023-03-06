#include <iostream>

using namespace std;

class Lego {
    private:
    string farbe;
    Lego *stein = nullptr;
    public:
    Lego(string f) {
        farbe = f;
    }

    void add(Lego *s) {
        if(stein != nullptr) {
            stein->add(s);
        } 
        else {
            stein = s;
        }
        
    } 

    void print() {
        cout << farbe << endl;
        if(stein != nullptr)
        {
            stein->print();
        }
    }
};


int main() {
    Lego l("Grün");
    l.add(new Lego("Blau"));
    l.add(new Lego("Rot"));
    l.print();

    Lego *z = new Lego("Gelb");
    z->add(new Lego("Schwarz"));
    z->add(new Lego("Violett"));
    l.add(z);

    cout << endl;

    l.print();

    return 0;
}