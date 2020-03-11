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
        int compare(ChaineDeCharacter const& ch) const;

    public:
        ChaineDeCharacter();
        ChaineDeCharacter(const char car[]);
        ChaineDeCharacter(ChaineDeCharacter const& ChaineDeCharacterToCopy);
        ~ChaineDeCharacter();
        unsigned int longueur() const;
        void ajout_fin(char c);
        void mettreMaj();

        ChaineDeCharacter& operator+=(ChaineDeCharacter const& ChaineDeCharacterToCopy);
        ChaineDeCharacter& operator=(ChaineDeCharacter const& ChaineDeCharacterToCopy);
        char operator[](unsigned int const c) const;
        operator int() const;

        friend std::ostream& operator<<(std::ostream &flux, ChaineDeCharacter const& a);

        friend bool operator==(ChaineDeCharacter const& a, ChaineDeCharacter const& b);
        friend bool operator!=(ChaineDeCharacter const& a, ChaineDeCharacter const& b);
        friend bool operator>=(ChaineDeCharacter const& a, ChaineDeCharacter const& b);
        friend bool operator<=(ChaineDeCharacter const& a, ChaineDeCharacter const& b);
        friend bool operator>(ChaineDeCharacter const& a, ChaineDeCharacter const& b);
        friend bool operator<(ChaineDeCharacter const& a, ChaineDeCharacter const& b);
};


#endif // CHAINEDECHARACTER_H_INCLUDED
