#include <iostream>
#include "ChaineDeCharacter.h"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    ChaineDeCharacter ch;
    ChaineDeCharacter ch0("test");
    ChaineDeCharacter ch2("Hello");


    if(ch0 != ch2)
        cout << "pas bien !!";

    cout << ch.longueur() << endl;
    ch = ch2;
    if(ch == ch2)
        cout << "egaux";

    ch.mettreMaj();

    cout << "==========================" << endl;
    ch2 += ch;

    cout << ch2 << endl;
    ch2.ajout_fin('!');
    cout << ch2 << endl;

    return 0;
}
