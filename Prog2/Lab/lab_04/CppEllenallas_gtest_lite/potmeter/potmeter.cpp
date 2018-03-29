#include "potmeter.h"


/**
 *  Itt valósítsa meg a SimPoti osztály tagfüggvényit!
 */


SimPoti::SimPoti( double r) {
    R = r;
    pos = 50;
}

int SimPoti::getPos() const {
    return pos;
}

Resistor SimPoti::getRes() const {
    return Resistor(R*pos/100.0) % Resistor(R*(100-pos)/100.0);
}

int SimPoti::operator++() {
    return (pos < 99) ? ++pos : pos;
}

int SimPoti::operator--() {
    return (pos > 1) ? --pos : pos;
}

