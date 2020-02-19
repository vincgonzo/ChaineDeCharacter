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

void ChaineDeCharacter::ajout_fin(char c)
{
    char * tmp_car = new char[++m_long+1]; // m_long +1 ??
    strcpy(tmp_car, m_car);
    tmp_car[m_long-1] = c;
    tmp_car[m_long] = '\0';
delete[] m_car;
    m_car = tmp_car;
}

void ChaineDeCharacter::mettreMaj()
{
    for(int i=0; i < m_long; i++)
    {
        m_car[i] = toupper(m_car[i]);
    }
}

bool ChaineDeCharacter::isEgal(ChaineDeCharacter const& ch) const
{
    return (m_long == ch.m_long && (strcmp(m_car, ch.m_car)==0))? true : false;
}


// Operator rewrite
ChaineDeCharacter& ChaineDeCharacter::operator+=(ChaineDeCharacter const& ChaineDeCharacterToCopy)
{
    int tmp_lg = m_long;
    m_long += ChaineDeCharacterToCopy.m_long;
    char * tmp_car = new char[m_long+1];
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

// External rewrite
ostream& operator<<(ostream &flux, ChaineDeCharacter const& a )
{
    flux << a.m_car;
    return flux;
}

bool operator==(ChaineDeCharacter const& a, ChaineDeCharacter const& b)
{
        return a.isEgal(b);
}

bool operator!=(ChaineDeCharacter const& a, ChaineDeCharacter const& b)
{
        return a.isEgal(b);
}
