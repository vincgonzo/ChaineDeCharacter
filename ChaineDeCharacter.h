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
        void affiche();
        void ajout_fin(char c);

        ChaineDeCharacter& operator+=(ChaineDeCharacter const& ChaineDeCharacterToCopy);
        ChaineDeCharacter& operator=(ChaineDeCharacter const& ChaineDeCharacterToCopy);
        friend std::ostream& operator<<(std::ostream &flux, ChaineDeCharacter const& a);
};


#endif // CHAINEDECHARACTER_H_INCLUDED
