//
// Created by kabor on 2018.03.22..
//

#ifndef FILMTAR_FILMEK_HPP
#define FILMTAR_FILMEK_HPP

#include <vector>
#include "film.hpp"
#include "csaladi.hpp"
#include "dokumentum.hpp"

class Filmek {
    size_t piece;
    std::vector <Film*> data;
public:
    Filmek();
    Filmek(size_t);

    void addNew(Film & );
    void addNew(Csaladi &);
    void addNew(Dokumentum &);

    std::ostream & printFilms( std::ostream & os) const;

};

std::ostream & operator << (std::ostream & os, const Filmek & flmk);


#endif //FILMTAR_FILMEK_HPP
