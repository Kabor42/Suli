//
// Created by kabor on 2018.03.22..
//

#include "csaladi.hpp"

int Csaladi::getKorhatar() {
    return korhatar;
}

void Csaladi::changeKorhatar(int ev) {
    korhatar = ev;
}

std::ostream &Csaladi::printInfo(std::ostream & os) const {
    os << "Cím" << "  " << title << std::endl;
    os << "Hossz" << "  " << duration << "perc" << std::endl;
    os << "Év" << "  " << year << std::endl;
    os << "Korhatár" << korhatar << std::endl;
    return os;
}


