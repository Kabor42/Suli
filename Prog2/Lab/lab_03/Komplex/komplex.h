// Copyright 2018.02.25 <kabor>

/**
 * \file komplex.h
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 *
 * Az előadáson látott Komplex osztályhoz hasonló osztály és a
 * hozzá kapcsolódó globális függvények deklarációja.
 */
#ifndef KOMPLEX_KOMPLEX_H_
#define KOMPLEX_KOMPLEX_H_
/**
 * Az Ön feladata a komplex.cpp fájlban megvalósítani (definiálni) az egyes
 * függvényeket. Ahogyan halad a megvalósítással egyre több tesztesetet kell
 * lefuttatni, ezért az ELKESZULT makró értéket folyamatosan növelje a
 * feladatsorszámoknak megfelelően!
 */
#define ELKESZULT 9
/**
 *Feladatok:
 *
 * 0. Készítsen paraméter nélküli, valamint egy- és két paraméteres konstruktort!
 * (ezt elkészítettük)
 * 1. Írjon lekérdező függvényeket a valós és képzetes rész lekérdezésére:
 *    getRe(), getIm()! Ügyeljen arra, hogy konstans objektumra is működjön!
 *    (Konstans objektumra csak olyan tagfüggvény alkalmazható, ami nem
 *    változtatja az objektum állapotát.)
 *    A példában a getRe() függvénynek van const és nem const változata is.
 *    Esetünkben ez értelmetlen, de azt kívánja demonstrálni, hogy ez két külön
 *    tagfüggvény.
 * 2. Írjon beállító függvényeket a valós és képzetes rész beállítására!
 *    setRe(double), setIm(double)
 * 3. Készítsen egyenlőségvizsgáló (==) operátort!
 *    A != operátort már elkészítettük, ami az == -re vezeti vissza a feladatot.
 * 4. Készítsen + operátort (összeadás)! Működjön valóssal balról és jobbról is!
 *    (A double + Komplex esetben a bal oldali operandus nem objektum,
 *    így globális operátorfüggvénnyel kell megvalósítani a feladatot.)
 * 5. Készítsen += operátort!
 *    Megj: A += valós változatot már elkészítettük!
 * 6. Készítsen abs() metódust, ami visszaadja a komplex szám abszolút értékét.
 *
 * Szorgalmi feladatok:
 * 7. Legyen kiírható a komplex adat egy ostream típusú objektumra a << operátorral
 *    1+34j ill. 1-34j alakban!
 *    Be lehessen olvasni egy istream típusú objektumból a >> operátorral
 *    ugyanilyen (1+34j) alakban!
 *    Megj: A kért kiírási formátumban a képzetes rész előtt ki kell írni a képzetes rész
 *    előjelét (a pozitívat is), de a valós rész előtt csak a negatív előjel
 *    jelenjen meg! (tipp: showpos, noshowpos, ignore)
 * 8. Valósítsa meg a ~ operátort, amely a komplex szám konjugáltját képzi.
 * 9. Készítsen * operátort (szorzás)! Működjön valóssal balról és jobbról is!
 *    Készítsen *= operátort! Működjön valóssal (double) is!
 */

/// Komplex osztály deklarációja
/// Lesz olyan feladat, amelynél ezt is bővítenie kell!
class Komplex {
    double re, im;
 public:
    /// 0, 1 és 2 paraméteres konstruktor
    /// @param re - valós rész
    /// @param im - képzetes rész
    Komplex(double re = 0, double im = 0);

    /// Valós rész lekérdezése
    /// @return - valós rész
    double getRe() { return re; }   // itt nincs értelme, csak demo

#if ELKESZULT >= 1
    // konstansra is alkalmazható lekérdező függvények
    /// Valós rész lekérdezése
    /// @return - valós rész
    double getRe() const;

    /// Képzetes rész lekérdezése
    /// @return - képzetes rész
    double getIm() const;
#endif

#if ELKESZULT >= 2
    // beállító függvények
    /// Valós részt beállító függvény
    /// @param r - valós rész
    void setRe(double re);

    /// Képzetes részt beállító függvény
    /// @param im - képzetes rész
    void setIm(double im);
#endif

#if ELKESZULT >= 3
    // összehasonlítás
    /// Egyenlőség vizsgálat
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return true - ha a képzetes és a valós rész is azonos, egyébként false
    bool operator==(const Komplex& k) const;

    /// Egyenlőtlenség vizsgálat
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return hamis - ha a képzetes és a valós rész is azonos, egyébként false
    bool operator!=(const Komplex& k) const;
#endif

#if ELKESZULT >= 4
    // összeadás, a + nem módosítja önmagát ezért konstans fv.
    /// Komplex + Komplex
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return egy új komplex adat - a két komplex adat összege
    Komplex operator+(const Komplex& k) const;

    /// Komplex + double
    /// @param rhs_d - jobb oldali operandus (double)
    /// @return egy új komplex adat - a két adat összege
    Komplex operator+(double d) const;

    /// double + Komplex csak globális függvénnyel valósítható meg,
    /// mivel a bal oldal nem osztály
    /// Ld. az osztály deklarációja után!
#endif

#if ELKESZULT >= 5
    // a += művelet viszont módosítja önmagát!
    /// Komplex + Komplex
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_k-t
    Komplex& operator+=(const Komplex& k);

    /// Komplex + double
    /// @param rhs_d - jobb oldali operandus (double)
    /// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
    Komplex& operator+=(double d);
#endif

#if ELKESZULT >= 6
    /// Abszolútérték lekérdezése
    /// @return - abszolútérték
    double abs() const;
#endif

#if ELKESZULT >= 8
    // az osztály a 8. feladattól
    // a feladatnak megfelelően további tagfüggvényekkel bővítendő
    // ....
    // komplex konjugált
    /// ~Komplex
    /// @return egy új adat, amiben a konjugált érték van
Komplex operator~() const;
#endif

#if ELKESZULT >= 9
    // szorzás, a * nem módosítja önmagát ezért konstans fv.
    /// Komplex * Komplex
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return egy új komplex adat - a két komplex adat szorzata
Komplex operator*(const Komplex& k) const;

    /// Komplex * double
    /// @param rhs_d - jobb oldali operandus (double)
    /// @return egy új komplex adat - a két adat szorzata
Komplex operator*(double d) const;

    /// double * Komplex csak globális függvénnyel valósítható meg,
    /// mivel a bal oldal nem osztály
    /// Ld. az osztály deklarációja után!

    // a *= művelet viszont módosítja önmagát!
    /// Komplex * Komplex
    /// @param rhs_k - jobb oldali operandus (Komplex)
    /// @return eredeti (bal oldali) objektum ref., amit megszorosztunk
Komplex& operator*=(const Komplex& k);

    /// Komplex + double
    /// @param rhs_d - jobb oldali operandus (double)
    /// @return eredeti (bal oldali) objektum ref., amit megszoroztunk
Komplex& operator*=(double d);
#endif
};

#if ELKESZULT >= 4
// double + Komplex csak globális függvénnyel valósítható meg,
// mivel a bal oldal nem osztály
/// double + Komplex
/// @param lhs_d - bal oldali operandus (double)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return egy új komplex adat - a két adat összege
Komplex operator+(double d, const Komplex& k);
#endif

#if ELKESZULT >= 7
// cout << Komplex is csak globális függvénnyel valósítható meg, mivel
// az baloldali osztály (ostream) nincs a kezünkben, nem módosítható
/// Kiírás egy ostream-re
/// @param os - bal oldali operandus (ostream)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return ostream&, hogy fűzhető legyen
std::ostream& operator<<(std::ostream& os, const Komplex& k);

/// Beolvasás egy istream-ről
/// @param is - bal oldali operandus (istream)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return istream&, hogy fűzhető legyen
std::istream& operator>>(std::istream& is, Komplex& k);
#endif

#if ELKESZULT >= 9
// double * Komplex csak globális függvénnyel valósítható meg,
// mivel a bal oldal nem osztály
/// double * Komplex
/// @param lhs_d - bal oldali operandus (double)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return egy új komplex adat - a két adat szorzata
Komplex operator*(double d, const Komplex& k);
#endif

#endif
