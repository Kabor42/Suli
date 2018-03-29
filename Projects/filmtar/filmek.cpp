//
// Created by kabor on 2018.03.22..
//

#include "filmek.hpp"

Filmek::Filmek() {
    piece = 0;

}

Filmek::Filmek(size_t many) {
    piece = many;
    for( int i=0; i<many; i++) {
        data.push_back(new Film());
    }
}

void Filmek::addNew( Film &fl ) {
    data.push_back(&fl);
    piece++;
}

void Filmek::addNew(Dokumentum & df) {
    data.push_back(&df);
    piece++;

}

void Filmek::addNew(Csaladi & cf) {
    data.push_back(&cf);
    piece++;
}

std::ostream &Filmek::printFilms(std::ostream &os) const {
    for(int i=0;i<piece;i++){
        os << "+-------------------------------------------------------------+" << std::endl;
        os << *data[i];
        os << "+-------------------------------------------------------------+" << std::endl;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Filmek &flmk) {
    return flmk.printFilms(os);
}
