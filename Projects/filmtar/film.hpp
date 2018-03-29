//
// Created by kabor on 2018.03.22..
//

#ifndef FILMTAR_FILM_HPP
#define FILMTAR_FILM_HPP

/** Feladat
 * Készítsen filmeket nyilvántartó rendszert.
 * Minden filmnek tároljuk a címét, lejátszási idejét és kiadási évét.
 * A családi filmek esetében korhatár is van, a dokumentumfilmek esetében egy szöveges leírást is tárolunk.
 * Tervezzen könnyen bővíthető objektummodellt a feladathoz!
 *
 * Demonstrálja a működést külön modulként fordított tesztprogrammal!
 * A megoldáshoz ne használjon STL tárolót!
 */

#include "string.hpp"

class Film {
protected:
    String title;
    int duration;
    int year;
public:
    Film();
    Film(const String & title, int d, int year) :title(title),duration(d),year(year) {}

    String getTitle();
    int getLength();
    int getYear();

    void changeTitle( String);
    void changeLength( int);
    void changeYear( int);

    bool operator == ( const Film & fl);
    bool operator != ( const Film & fl);

    virtual std::ostream& printInfo( std::ostream& ) const;

};

std::ostream & operator << (std::ostream & os, const Film & fl);


#endif //FILMTAR_FILM_HPP
