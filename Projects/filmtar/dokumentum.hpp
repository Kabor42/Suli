//
// Created by kabor on 2018.03.22..
//

#ifndef FILMTAR_DOKUMENTUM_HPP
#define FILMTAR_DOKUMENTUM_HPP

#include "film.hpp"

class Dokumentum: public Film {
private:
    String description;
public:
    Dokumentum(const String & title, int d, int year, const String & description)
            :Film(title, d, year),description(description) {}

    String getDescripion();
    void changeDescription(const String &);

    std::ostream& printInfo( std::ostream& ) const;

};


#endif //FILMTAR_DOKUMENTUM_HPP
