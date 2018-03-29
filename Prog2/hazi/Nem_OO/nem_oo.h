#ifndef NEM_OO_H
#define NEM_OO_H
/**
 * file nem_oo.h (latin2 kodolasu fajl)
 *
 * A C++ nem OO b�v�t�seinek gyakorl�s�hoz.
 *
 */

#include <cmath>
#include <iostream>
#include "memtrace.h"


namespace sajat {	/// saj�t n�vt�r

/**
 * Saj�t atoi.
 * Sz�mjegysorozat �talak�t�sa int-re
 * A sz�mjegysorozat v�g�t white space, vagy sztring v�ge ('\0') jelzi.
 * Ha a sz�mjegysorozatban olyan sz�mjegy, vagy bet� fordul el�,
 * ami nem �rv�nyes az adott sz�mrendszerben, az hiba.
 * Hiba eset�n egy const char* t�pus� kiv�telt kell dobni, melynek �rt�ke
 * az �n neptun azonos�t�ja!
 * @param p    - pointer a sztringre
 * @param base - sz�mrendszer alapja (0-10)
 * @return     - base sz�mrendszerben �rtelmezett sz�m
 */
int atoi(const char *p, int base = 10);

/**
 * Sajat strcat.
 * K�t cstrring �sszef�z�se
 * Dinamikusan foglal helyet
 * @param p1   - pointer az els� sztringre
 * @param p2   - pointer az m�sik sztringre
 * @return     - dinamikusan foglalt ter�let c�me, ahova az eredm�ny ker�l (h�v�nak kell felszabad�tania)
 */
char *strcat(const char *p1, const char *p2);

/**
 * unique
 * A param�terk�nt kapott k�t pointer k�z�tti karaktersorozatb�l kihagyja az egym�s ut�n ism�tl�d�
 * karaktereket (char). A sorozatot az eredeti hely�n hagyja!
 * @param first - pointer az adatok kezdet�re
 * @param last  - pointer, ami az utols� adat ut�n mutat
 * @return      - pointer, ami az �j sorozat utols� adata ut�n mutat (a kihagy�ssal r�vid�lt a sorozat)
 */
char *unique(char *first, char *last);

/**
 * Az al�bb megval�s�tott adatstrukt�ra �s a hozz� tart�z� f�ggv�nyek
 * A max sablonnal kapcsolatos feladat megval�s�t�s�hoz kellenek.
 *
 * �rtse meg a m�k�d�s�ket!
 * A feladat r�szletes le�r�s�t a max.hpp f�jlban tal�lja, �s abban
 * val�s�tsa meg a v�rt sablont �s annak specializ�ci�j�t!
 */

/**
 * Adatstrukt�ra komplex sz�m t�rol�s�hoz
 */
struct Komplex {
    double re;  // val�s r�sz
    double im;  // k�pzetes r�sz
};

/**
 * Komplex sz�m abszol�t �rt�ke
 * @param k - komplex sz�m
 * @return val�s - a komplex sz�m abszol�t �rt�ke
 */
inline double absKomplex(const Komplex& k) {
    return sqrt(k.re*k.re + k.im*k.im);
}

/**
 * Komplex sz�m ki�r�sa egy ostream t�pus� adatfolyamra
 * @param os - ostream t�pus� objektum
 * @param k - komplex sz�m
 * @return os
 */
inline std::ostream& operator<<(std::ostream& os, const Komplex& k) {
    os << "(" << k.re << "," << k.im << "j)";
    return os;
}


}/// ----------  n�vt�r v�ge ---------------

#endif
