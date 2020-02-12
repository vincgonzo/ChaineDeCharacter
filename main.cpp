#include <iostream>
#include "ChaineDeCharacter.h"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    ChaineDeCharacter ch;
    ChaineDeCharacter ch2("Hello");

    cout << ch.longueur() << endl;
    ch = ch2;

    cout << ch << endl;
    cout << ch2 << endl;

    cout << "==========================" << endl;
    ch2 += ch;

    cout << ch2 << endl;
    ch2.ajout_fin('!');
    cout << ch2 << endl;

    return 0;
}
