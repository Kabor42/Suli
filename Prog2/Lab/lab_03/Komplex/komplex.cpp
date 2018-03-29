// Copyright 2018.02.25 <kabor>

/**
 * \file komplex.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 *
 * Komplex osztályt megvalósító függvények definíciója
 *
 * Folytassa a megvalósítást a complex.h fájlban levő
 * feladatoknak megfelelően!
 *
 */

// Valószínű, hogy a kiíráshoz majd kell
#include <iostream>
// ... és ez is.
#include <iomanip>
// Valószínű, hogy az abszolút értékhez majd kell.
#include <cmath>
// Ebben van a Komplex osztály, és néhány globális függvény deklarációja
#include "./komplex.h"
// using std::...  // soroljuk fel az std névtérből használt elemeket

// 0, 1 és 2 paraméteres konstruktor
// Figyelje meg, hogy a default argumentumokat CSAK a deklarációnál
// adtuk meg!
Komplex::Komplex(double r, double im) {
    re = r;
    // ha nincs névütközés, nem kell kiírni a this-t
    this->im = im;
}

// Előre elkészített tagfüggvények

#if ELKESZULT >= 3
// 3. feladathoz (ELKESZULT 3)
// összehasonlítás
/// Egyenlőtlenség vizsgálat
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return hamis - ha a képzeets és a valós rész is azonos, egyébként false
bool Komplex::operator!=(const Komplex& k) const {
  // visszavezetjük az egyenlőség vizsgálatra
  return !(*this == k);
}
#endif

#if ELKESZULT >= 5
// 5. feladathoz (ELKESZULT 5)
// a += művelet viszont módosítja önmagát!

/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
Komplex& Komplex::operator+=(double d) {
    re += d;
    return *this;
}
#endif

// TODO(kabor): A hiányzó tag- és globális függvények itt következnek


double Komplex::getRe() const {
  return re;
}

double Komplex::getIm() const {
  return im;
}

void Komplex::setRe(double re) {
  this->re = re;
}

void Komplex::setIm(double im) {
  this->im = im;
}

bool Komplex::operator==(const Komplex& k) const {
  return ( (re == k.re) && (im == k.im) );
}

/******************   4.                                                      */

Komplex Komplex::operator+(const Komplex& k) const {
    return Komplex( re+k.re, im+k.im);
}

Komplex Komplex::operator+(double d) const{
    return Komplex( re+d, im);
}

Komplex operator+(double d, const Komplex& k){
    return Komplex( d+k.getRe(), k.getIm());
}

/******************   5.                                                      */

Komplex& Komplex::operator+=(const Komplex& k) {
    re = re + k.re;
    im = im + k.im;
    return *this;
}

/******************   6.                                                      */

double Komplex::abs() const {
    return(std::sqrt(std::pow(re, 2) + std::pow(im , 2)));
}

/******************   7.                                                      */

std::ostream& operator<<(std::ostream& os, const Komplex& k){
    os << k.getRe();
    if (k.getIm() >= 0)
        os << '+';
    os << k.getIm() << "j";
    return os;
}

std::istream& operator>>(std::istream& is, Komplex& k) {
    double re, im;

    is >> re;
    is >> im;
    is.ignore( 256, 'j');

    k.setRe(re);
    k.setIm(im);

    return is;
}

/******************   8.                                                      */

Komplex Komplex::operator~() const{
    return Komplex( re, -im);
}

/******************   9.                                                      */

Komplex Komplex::operator*(const Komplex& k) const {
    return Komplex(re*k.re - im*k.im, re*k.im + im*k.re);
}

Komplex Komplex::operator*(double d) const {
    return Komplex( re*d, im*d);
}

Komplex& Komplex::operator*=(const Komplex& k) {
    double tmp = re;
    re = tmp*k.re - im*k.im;
    im = tmp*k.im + im*k.re;
    return *this;
}

Komplex& Komplex::operator*=(double d) {
    re = re * d;
    im = im * d;
    return *this;
}

Komplex operator*(double d, const Komplex& k) {
    return Komplex( d*k.getRe(), d*k.getIm());
}
