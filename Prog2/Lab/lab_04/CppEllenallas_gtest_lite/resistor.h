#ifndef RESISTOR_H
#define RESISTOR_H

/**
 * Ohmikus ellenállás
 */
class Resistor {
    double R;              	// az ellenállás értéke ohmban
    static double defR;  	// ellenállás alapértelmezett értéke ohmban
public:

    /// Konstruktor.
    /// Alapértelmezett értéket (defR) kap
    Resistor();

    /// Konstruktor.
    /// @param r - ellenállás értéke [ohm]
    Resistor(double r);

    /** Masolo konstruktor
    */
    Resistor(const Resistor& r) :R(r.R) {};

    /// Default ellenállásérték beállítása
    /// @param r - ellenállás értéke [ohm]
    static void setDef(double r);

    /// Ellenállás értékének lekérdezése.
    /// @return - ellenállás értéke [ohm]
    double getR() const {
        return R;
    }

    /// Két ellenállás soros kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredő ellenállás
    Resistor operator+(const Resistor& r) const;

    /// Két ellenállás párhuzamos kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredő ellenállás
    Resistor operator%(const Resistor& r) const;

    /// Értékadás (így működik az implicit op= is)
    /// @param r - ellenállás
    /// @return  - bal oldali operandus az új értékkel
    Resistor& operator=(const Resistor& r);

    /// Két ellenállás összehasonlítása.
    /// @param r - ellenállás
    /// @return  - true, ha azonos
    bool operator==(const Resistor& r) const;

    /// Két ellenállás összehasonlítása.
    /// @param r - ellenállás
    /// @return  - true, ha eltér
    bool operator!=(const Resistor& r) const;

    /// Ellenálláson eső feszültség
    /// @param i - áram
    /// @return  - feszültség
    double getU(double i) const;

    /// Ellenálláson folyó áram
    /// @param u - áram
    /// @return  - áram
    double getI(double u) const;

};

/// Többszörös: n darab egyforma r ellenállás összege (soros kapcsolása).
/// @param n - darabszám
/// @param r - ellenállás
/// @return  - eredő ellenállás
Resistor operator*(int n, const Resistor& r);

/// Ostream kiiras
std::ostream& operator<<(std::ostream& os, const Resistor& r);
#endif



