/**
 * \file: console.h
 */
#ifndef POTMETER_H
#define POTMETER_H

#include "resistor.h"

/**
 * Vegyünk egy potmétert melynek a névleges ellenállása legyen R (a két végkivezetés között).
 * A kezelőszerv forgatásával az egyik végpont és a középső pont között az
 * ellenállás R 1%-a és 99%-a között változtatható.
 *
 *                      ^
 *             +-------/--+
 *        o----|    R /   |-----o
 *             +-----/----+
 *        o---------/
 *
 * Modellezzük a potméter két végpontjának összekötésével létrejövő áramköri elemet: (SimPoti)!
 *
 * Az elemet úgy használjuk, hogy a középkivezetést és az összekötött végpontokat kötjük be
 * az áramkörbe.
 *
 * A végpontok összekötésével létrejövő elem (SimPoti) működése két párhuzamosan kötött
 * változtatható ellenállással (r1, r2) modellezhető:
 *           +--[R1]--+
 *        o--+        +---o
 *           +--[R2]--+
 * ahol:
 * R1 + R2 = R
 * R1 = R*POS/100,
 * R2 = R*(100-POS)/100
 * POS = a kezelőszerv állása: 1..99
 *
 */

/**
 * FELADAT:
 * A fentiek alapján tervezze meg és valósítsa meg a SimPoti osztályt!
 * Legyen az osztálynak:
 *  - Konstruktora, amivel megadható a potméter névleges ellenállása!
 *    A konstruktor középre (50%) állítsa a potméter kezelőszervét!
 *  - Legyen lekérdezhető a kezelőszerv aktuális állása!
 *  - Legyenek olyan tagfüggvények (pre inkremens, és post dekremens operator), amivel a kezelőszerv
 *    állása 1-1%-kal növelhető és csökkenthető! A legkisebb állás 1, a legnagyobb 99 legyen!
 *  - Legyen lekérdezhető az összekötött végpontok, és a középső kivezetés közötti ellenállás!
 * A megvalósításhoz használja fel a Resistor osztályt, de azt ne módosítsa!
 */

/**
 * ÖTLET:
 * A kezelőszerv pozíciója és a potméter ellenállása r1 és r2 meghatározható.
 * Ezek párhuzamos kapcsolását a Resistor osztály segítségével egyszerű elvégezni.
 */

/**
 * Segítségül megadjuk a SimPoti osztály deklarációjának publikus részét.
 * Egészítse azt ki a privát résszel!
 * Ezután másolja át a tagfüggvények deklarációit a potmeter.cpp fájlba
 * és valósítsa meg abban a függvényeket.
 * Annak ellenére így járjon el, hogy a függvények törzse csak 1-2 soros lesz.
 */

class SimPoti {
double R; int pos;
// #error "Itt van az osztaly privat resze"
// #error "Ne taroljon olyan adatot, amit ki is tud szamolni"
public:
    /// Konstruktor.
    /// @param r - ellenállás értéke [ohm]
    /// A konstruktor állítsa középállásba (50) a kezelőszervet!
    SimPoti(double r);

    /// Kezelőszerv pozíciójának lekérdezése
    /// @return - pozíció (1..50)
    int getPos() const;

    /// Két végpont és a középpont közötti eredő ellenállás
    /// @return - Eredő ellenállás (Resistor)
    Resistor getRes() const;

    /// Kezelőszerv fogatása (növel)
    /// A pozíció értéke nő, 99-nél fennakad
    /// @return pillanatnyi pozíció
    int operator++();

    /// Kezelőszerv fogatása (csökkent)
    /// A pozíció értéke csökken, 1-nél fennakad
    /// @return pillanatnyi pozíció
    int operator--();
};

#endif // POTMETER_H
