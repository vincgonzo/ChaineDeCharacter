#include <iostream>
#include "ChaineDeCharacter.h"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    ChaineDeCharacter ch;
    ChaineDeCharacter ch0("test");
    ChaineDeCharacter ch2("Hello");
    ChaineDeCharacter chInt("12");


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
    cout << ch2 << endl << endl;

    cout << "==========================" << endl;
    cout << "======= Test running =====" << endl;
    cout << "==========================" << endl;

    if(ch0 >= ch2)
        cout << "ch0 is superior or equal to ch2" << endl;
    if(ch2 >= ch0)
        cout << "ch2 is superior or equal to ch0" << endl;
    if(ch0 <= ch2)
        cout << "ch0 is inferior or equal to ch2" << endl;
    if(ch2 <= ch0)
        cout << "ch2 is inferior or equal to ch0" << endl;
    if(ch0 > ch2)
        cout << "ch0 is superior to ch2" << endl;
    if(ch2 > ch0)
        cout << "ch2 is superior to ch0" << endl;
    if(ch0 < ch2)
        cout << "ch0 is inferior to ch2" << endl;
    if(ch2 < ch0)
        cout << "ch2 is inferior to ch0" << endl;

    cout << chInt + 1 << endl;
    return 0;
}
