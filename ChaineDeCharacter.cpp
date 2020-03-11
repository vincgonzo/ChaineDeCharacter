#include "ChaineDeCharacter.h"
#include <iostream>
#include <cstring>
#include <string>
#include <memory>
#include <cmath>
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

int ChaineDeCharacter::compare(ChaineDeCharacter const& ch) const
{
    return strcmp(m_car, ch.m_car);
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

ChaineDeCharacter::operator int() const
{
    int tmp(0);
    for(int i(0); i < m_long; i++)
    {
     // clockwise thinking
     //tmp += (m_car[i] - '0') * pow(10, ((m_long-i)-1));
     // or
     tmp *= 10;
     tmp += (m_car[i] - '0');
    }
    return tmp;
    //return atoi(m_car); // LAZY version ;)
}

ChaineDeCharacter& ChaineDeCharacter::operator=(ChaineDeCharacter const& ChaineDeCharacterToCopy)
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

char ChaineDeCharacter::operator[](unsigned int const c) const
{
    return m_car[c];
}

// External rewrite
ostream& operator<<(ostream &flux, ChaineDeCharacter const& a )
{
    flux << a.m_car;
    return flux;
}

bool operator==(ChaineDeCharacter const& a, ChaineDeCharacter const& b)
{
    return (a.compare(b) == 0)? true : false;
}

bool operator!=(ChaineDeCharacter const& a, ChaineDeCharacter const& b)
{
    return (a.compare(b) != 0)? true : false;
}

bool operator>=(ChaineDeCharacter const& a, ChaineDeCharacter const& b)
{
    return (a.compare(b) >= 0)? true : false;
}

bool operator<=(ChaineDeCharacter const& a, ChaineDeCharacter const& b)
{
    return (a.compare(b) <= 0)? true : false;
}

bool operator>(ChaineDeCharacter const& a, ChaineDeCharacter const& b)
{
    return (a.compare(b) > 0)? true : false;
}

bool operator<(ChaineDeCharacter const& a, ChaineDeCharacter const& b)
{
    return (a.compare(b) < 0)? true : false;
}
