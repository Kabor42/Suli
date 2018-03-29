#include <iostream>
#include <iomanip>
#include <cmath>

#include "resistor.h"

/**
 * Ohmikus ellen�ll�st modellez� oszt�ly megval�s�t�sa
 */

 /**
Itt kell megval�s�tani a resistor.h-ban deklar�lt
nem inline f�ggv�nyeket.
A Jport�ra ezt a fajlt kell felt�lteni.
*/

const char* exc = "M8CFQC";

double Resistor::defR = 21;

Resistor::Resistor() {
    R = defR;
}

Resistor::Resistor( double r) {
    R = r;
}

void Resistor::setDef( double r) {
    defR = r;
}

/**
     K�t ellen�ll�s soros kapcsol�sa.
     @param r - ellen�ll�s
     @return  - ered� ellen�ll�s
    */
Resistor Resistor::operator+(const Resistor& r) const {
    return Resistor( R + r.R);
}

/**
    K�t ellen�ll�s p�rhuzamos kapcsol�sa.
    @param r - ellen�ll�s
    @return  - ered� ellen�ll�s
    */
Resistor Resistor::operator%(const Resistor& r) const {
    return Resistor((R*r.R)/(R+r.R));
}

/**
T�bbsz�r�s: n darab egyforma r ellen�ll�s �sszege (soros kapcsol�sa).
@param n - darabsz�m
@param r - ellen�ll�s
@return  - ered� ellen�ll�s
*/
Resistor operator*(int n, const Resistor& r) {
    if ( n <= 0)
        throw exc;
    return Resistor( n*r.getR());
}
