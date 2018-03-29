//
// Created by kabor on 2018.03.22..
//

#include "dokumentum.hpp"

String Dokumentum::getDescripion() {
    return description;
}

void Dokumentum::changeDescription(const String &st) {
    description = st;
}

std::ostream &Dokumentum::printInfo(std::ostream &os) const {
    os << "Cím" << "  " << title << std::endl;
    os << "Hossz" << "  " << duration << "perc" << std::endl;
    os << "Év" << "  " << year << std::endl;
    os << "Leírás" << description << std::endl;
    return os;
}
