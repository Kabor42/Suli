//
// Created by kabor on 2018.03.04..
//

#include <iostream>
#include <iomanip>
#include <stdexcept>

/**
 * 8. feladat Nagy Dominik (M8CFQC) részére:
 * Készítsen függvényt, amely a paraméterként kapott valós elemeket tartalmazó
 * tömböt nagyság szerint csökkenõ sorrendbe rendezi! A függvény paraméterként kapja a
 * rendezendõ tömböt és a tömbben levõ elemek számát:
 *
 *  void rendez(double t[], int n);
 *
 *  A függvény felhasználásával készítsen egy olyan osztálysablont, ami double
 *  elemeket tartalmazó fix méretû tömbként mûködik, és képes nagyság szerint csökkenõ
 *  sorrendbe rendezi a tárolt elemeket!
 *  Az osztály legyen átadható értékparaméterként és értékadás jobb és bal oldalán
 *  is szerepelhessen! Legyen továbbá indexelhetõ (bal értékkent is)! Túlindexelés
 *  esetén 'out_of_range' hibát dobjon! A sablon a maximálisan tárolható elemek számát
 *  sablonparaméterként kapja, de tartsa nyilván az aktuálisan tárolt elemek számát
 *  is! Erre azért van szükség, mert a rendezést csak ezekre kell elvégezni, amit a
 *  'void rendez()' tagfüggvénnyel lehet kezdeményezni.
 *
 *  Legyen az osztály speciálisan kiíratható egy std::otsream típusú objektumra
 *  a << operátorral! Ekkor soronként írja ki az alábbi indexû elemeket:
 *
 *          23. 22. 85. 84. 418.
 *
 *  Az értékeket a megadott sorrendben, fix formátumban, soronként írja ki 4 tizedesjegy pontossággal!
 *  Ügyeljen arra, hogy a alapesetben a precision nem a tizedesjegyek számat jelenti.
 *
 *  Legyen továbbá egy 'const char* c_str()' tagfüggvénye is, ami a hftest azonosító elsõ
 *  sorát adja (NÉV,ÉVF,TK,LABOR <E-MAIL> NEPTUN).
 *
 *  A feladat megoldásához az aktuális katalógusban (/home/c/17/nd1531/hftest)
 *  elõkészített f8_main.cc és az f8.mak állományok a tesztelést és fordítást
 *  segítik.
 *
 *  Az Ön feladata megvalósítani az f8.hpp állományban az F8 osztálysablont.
 *
 *  Ha elkészült, fordítsa le, ill. tesztelje az osztályt a következõ paranccsal:
 *      make -f f8.mak
 *
 *  A make lefordítja az f8_main.cc-t és így futtatható a keletkezõ f8 nevû program.
 *  Az f8_main.cc állomány a teszetléshez igénye szerint módosíthatja.
 *
 *  Ha úgy gondolja, hogy helyesen oldotta meg a feladatot, akkor a
 *          make -f f8.mak submit
 *  paranccsal adja be azt az automatikus feladatellenõrzõ rendszernek. Az automatikus
 *  teszt csak az f8.hpp állományban megvalósított F8 osztály mûködését vizsgálja,
 *  azaz, hogy megfelel-e a fent megadott specifikációnak. Így nem veszi figyelembe az
 *  f8_main.cc esetleg módosított tartalmát.
 */

#ifndef PROG8_F8_HPP
#define PROG8_F8_HPP


/** Primary sorting function
 * Sort the array t[], with n values, in reverse order.
 * @param t Array to be sorted.
 * @param n Number of functional values within the array.
 */
void rendez(double t[], int n) {
    if (n <= 1) return;
    double p = t[n/2];
    double b[n], c[n];
    int i, j = 0, k = 0;
    for (i=0; i < n; i++) {
        if (i == n/2) continue;
        if ( t[i] >= p) b[j++] = t[i];
        else            c[k++] = t[i];
    }
    rendez(b,j);
    rendez(c,k);
    for (i=0; i<j; i++) t[i] =b[i];
    t[j] = p;
    for (i= 0; i<k; i++) t[j+1+i] =c[i];
}


/** Feladat 8 class template
 * Creates a vector class to store double datas in an array
 * with class specific operations.
 * @tparam T max size of vector
 */
template <int T>
class F8{
private:
    double *values;                             /** Array for data storage */
    int curr;                                   /** Current occupation */
    int size;                                   /** Maximum size, also class template param */
public:
    F8() {                                      /** CTor */
        curr=0;
        size=T;
        values=new double[size];
    }
    F8(const F8& v) {                           /** Copy ctor */
        curr = v.curr;
        size = v.size;
        values = new double[curr];
        for(int i=0;i<curr;i++){
            values[i] = v.values[i];
        }
    }
    ~F8() {
        delete[] values;
    }
    const char *c_str() {                       /** Prints HFTEST ID string */
        return "Nagy Dominik, 1MI,15,L4M,<nd1531@hszk.bme.hu> M8CFQC";
    }
    void rendez() {                             /** Sorts the array, reverse order */
        ::rendez(values, curr);
    }
    F8& operator=(const F8& v) {                /** Copy the class */
        this->curr = v.curr;
        this->size = v.size;
        delete[] this->values;
        values = new double[curr];
        for(int i=0;i<curr;i++){
            values[i] = v.values[i];
        }
    }
    double& operator[](size_t idx) {            /** Index operator for declaration */
        if( idx >= size){
            throw std::out_of_range ("Index out of bounds!");
        }
        curr++;
        return this->values[idx];
    }
    const double& operator[](size_t idx) const {/** Reference index operator */
        if (idx >= curr) {
            throw std::out_of_range("Index out of bounds!");
        }
        return this->values[idx];
    }
};

/** Output over ostream
 * This prints signature indexed values for HFTEST.
 * @param os output stream.
 * @param v F8 vector.
 * @return gives back the stream.
 */
template <int N> std::ostream& operator << (std::ostream& os, const F8<N> &v) {
    // 23. 22. 85. 84. 418.
    os << std::fixed;
    os << std::setprecision(4);
    os << v[22]  << std::endl;
    os << v[21]  << std::endl;
    os << v[84]  << std::endl;
    os << v[83]  << std::endl;
    os << v[417] << std::endl;
    return os;
}

#endif //PROG8_F8_HPP
