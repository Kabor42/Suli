#include <iostream>
#include <iomanip>
#include <cmath>

#include "resistor.h"

/**
 * Ohmikus ellenállást modellezõ osztály megvalósítása
 */

 /**
Itt kell megvalósítani a resistor.h-ban deklarált
nem inline függvényeket.
A Jportára ezt a fajlt kell feltölteni.
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
     Két ellenállás soros kapcsolása.
     @param r - ellenállás
     @return  - eredõ ellenállás
    */
Resistor Resistor::operator+(const Resistor& r) const {
    return Resistor( R + r.R);
}

/**
    Két ellenállás párhuzamos kapcsolása.
    @param r - ellenállás
    @return  - eredõ ellenállás
    */
Resistor Resistor::operator%(const Resistor& r) const {
    return Resistor((R*r.R)/(R+r.R));
}

/**
Többszörös: n darab egyforma r ellenállás összege (soros kapcsolása).
@param n - darabszám
@param r - ellenállás
@return  - eredõ ellenállás
*/
Resistor operator*(int n, const Resistor& r) {
    if ( n <= 0)
        throw exc;
    return Resistor( n*r.getR());
}
