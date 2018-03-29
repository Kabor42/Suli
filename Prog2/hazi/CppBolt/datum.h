#ifndef DATUM_H
#define DATUM_H

/**
 * \file datum.h
 *
 * Datum osztály deklarációja és inline függvényei
 */

#include <iostream>

class Datum {
    int ev;     ///< év
    int ho;     ///< hónap
    int nap;    ///< nap
  public:
    /// Paraméter nélkül hívható konstruktor.
    /// Mai napot állítja be
    Datum();

    /// Adott napot beállító konstruktor
    /// @param ev - év
    /// @param hó - hónap
    /// @param nap - nap
    Datum(int ev, int ho, int nap) :ev(ev), ho(ho), nap(nap) {}

    /// C sztringre konvertál
    /// @return C string (eeee-hh-nn) alakban
    const char* c_str() const;

    /// Két dátum egyezőségét vizsgálja
    /// @param d - jobb oldali operandus
    /// @return true, ha egyezik a két dátum
    bool operator==(const Datum& d) const {
        return ev == d.ev && ho == d.ho && nap == d.nap;
    }
};

/// Globális inserter
/// @param os - output stream referencia
/// @param s - Datum referencia
/// @return output stream referencia
inline std::ostream& operator<<(std::ostream& os, const Datum& d) {
    return os << d.c_str();
}

#endif // DATUM_H
