#include "ChaineDeCharacter.h"
#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <stdlib.h>

using namespace std;

ChaineDeCharacter::ChaineDeCharacter(){
    m_car = new char[1];
    m_car[0] = '\0';
    m_long = 0;
};

ChaineDeCharacter::ChaineDeCharacter(const char car[]): m_long(strlen(car)), m_car(new char[m_long+1])
{
    strcpy(m_car, car);
};

ChaineDeCharacter::ChaineDeCharacter(ChaineDeCharacter const& ChaineDeCharacterToCopy):
    m_long(ChaineDeCharacterToCopy.m_long),
    m_car(ChaineDeCharacterToCopy.m_car)
{
};

ChaineDeCharacter::~ChaineDeCharacter(){
    delete[] m_car;
};

unsigned int ChaineDeCharacter::longueur() const
{
    return m_long;
}

void ChaineDeCharacter::affiche()
{
    std::cout << m_car;
//    int lg = 0;
//    while(m_car[lg] != '\0')
//        std::cout << m_car[lg++];
}

void ChaineDeCharacter::ajout_fin(char c)
{
    char * tmp_car = new char[++m_long+1]; // m_long +1 ??
    strcpy(tmp_car, m_car);
    tmp_car[m_long-1] = c;
    tmp_car[m_long] = '\0';
delete[] m_car;
    m_car = tmp_car;
}

// Operator rewrite
ostream& operator<<(ostream &flux, ChaineDeCharacter const& a )
{
    flux << a.m_car;
    return flux;
}


ChaineDeCharacter& ChaineDeCharacter::operator+=(ChaineDeCharacter const& ChaineDeCharacterToCopy)
{
    int tmp_lg = m_long;
    m_long += ChaineDeCharacterToCopy.m_long;
    char * tmp_car= new char[m_long+1];
    strcpy(tmp_car, m_car);
    strcpy(tmp_car + tmp_lg, ChaineDeCharacterToCopy.m_car);
delete[] m_car;
    m_car = tmp_car;

    return *this;
}

ChaineDeCharacter& ChaineDeCharacter::operator=(const ChaineDeCharacter& ChaineDeCharacterToCopy)
{
        if(this != &ChaineDeCharacterToCopy)
        {
            m_long = ChaineDeCharacterToCopy.m_long;
            delete[] m_car;
            m_car = new char[m_long+1];
            strcpy(m_car, ChaineDeCharacterToCopy.m_car);
        }
        return *this;
}
