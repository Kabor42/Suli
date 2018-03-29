//
// Created by kabor on 2018.03.22..
//

#ifndef FILMTAR_CSALADI_HPP
#define FILMTAR_CSALADI_HPP

#include "film.hpp"

class Csaladi: public Film {
private:
    int korhatar;

public:

    Csaladi(const String & title, int d, int year, int korhatar) :Film(title,d,year),korhatar(korhatar) {}

    int getKorhatar();
    void changeKorhatar( int ev);

    std::ostream& printInfo( std::ostream& ) const;

};


#endif //FILMTAR_CSALADI_HPP
