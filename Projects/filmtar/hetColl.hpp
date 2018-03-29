//
// Created by kabor on 2018.03.29..
//

#ifndef FILMTAR_HETCOLL_HPP
#define FILMTAR_HETCOLL_HPP

#include <iostream>
#include "film.hpp"
#include "csaladi.hpp"
#include "dokumentum.hpp"

class hetColl {
protected:
    unsigned in;
    Film *arr;
public:
    hetColl() :in(0),arr(new Film[in]) {}
    hetColl(unsigned int var);
    hetColl& operator = (const hetColl &);
    virtual ~hetColl();

    unsigned int size() const;

    Film & operator [] (unsigned int id);
    const Film & operator [] (unsigned int id) const;

    void push(Film &);
    Film & pop();
    void del(Film &);

    bool isEmpty() const;
    bool isIn(Film &) const;

    std::ostream & printAll(std::ostream &);

    void save();
    void read();

};

std::ostream & operator << (std::ostream &, hetColl &);

#endif //FILMTAR_HETCOLL_HPP
