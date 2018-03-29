//
// Created by kabor on 2018.03.22..
//

#include "film.hpp"

Film::Film() {
    duration = 0;
    year = -1;
}

String Film::getTitle() {
    return this->title;
}

int Film::getLength() {
    return this->duration;
}

int Film::getYear() {
    return this->year;
}

void Film::changeTitle( String title) {
    this->title = title;
}

void Film::changeLength( int len) {
    this->duration = len;
}

void Film::changeYear( int year) {
    this->year = year;
}

bool Film::operator == ( const Film & fl) {
    if ( title != fl.title)
        return false;
    if ( duration != fl.duration && year != fl.year )
        return true;
    return true;
}

bool Film::operator!= ( const Film & fl) {
    return !(*this == fl);
}

std::ostream & Film::printInfo(std::ostream & os) const{
    os << "Cím" << "  " << title << std::endl;
    os << "Hossz" << "  " << duration << "perc" << std::endl;
    os << "Év" << "  " << year << std::endl;
    return os;
}


std::ostream & operator<<(std::ostream &os, const Film &fl) {
    return fl.printInfo(os);
}
