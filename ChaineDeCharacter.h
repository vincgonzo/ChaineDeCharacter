#ifndef CHAINEDECHARACTER_H_INCLUDED
#define CHAINEDECHARACTER_H_INCLUDED

#include <iostream>
#include <cstring>
#include <string>
#include <memory>
class ChaineDeCharacter
{
    int m_long;
    char *m_car;

    public:
        ChaineDeCharacter();
        ChaineDeCharacter(const char car[]);
        ChaineDeCharacter(ChaineDeCharacter const& ChaineDeCharacterToCopy);
        ~ChaineDeCharacter();
        unsigned int longueur() const;
        void ajout_fin(char c);
        void mettreMaj();
        bool isEgal(ChaineDeCharacter const& ch) const;

        ChaineDeCharacter& operator+=(ChaineDeCharacter const& ChaineDeCharacterToCopy);
        ChaineDeCharacter& operator=(ChaineDeCharacter const& ChaineDeCharacterToCopy);

        friend std::ostream& operator<<(std::ostream &flux, ChaineDeCharacter const& a);
};

bool operator==(ChaineDeCharacter const& a, ChaineDeCharacter const& b);
bool operator!=(ChaineDeCharacter const& a, ChaineDeCharacter const& b);

#endif // CHAINEDECHARACTER_H_INCLUDED
