/**
 * \file datum.h
 *
 * Datum osztály tagfüggvényinek megvalósítása (definíciója)
 */

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

#include "memtrace.h"
#include "datum.h"

using std::setw;
using std::setfill;

/// Paraméter nélkül hívható konstruktor.
/// Mai napot állítja be
Datum::Datum() {
    time_t tim;
    tim = time(NULL);       // lekérdezzük a jelenlegi időt
    struct tm *tp = localtime(&tim);  // átalakítjuk
    ev = tp->tm_year+1900;
    ho = tp->tm_mon+1;
    nap = tp->tm_mday;
}

/// C sztringre konvertál
/// @return C string (eeee-hh-nn) alakban
const char* Datum::c_str() const {
    std::stringstream ss;
    ss << setw(4) << ev << "-"
       << setw(2) << setfill('0') << ho << "-"
       << setw(2) << nap;
    return ss.str().c_str();
}
