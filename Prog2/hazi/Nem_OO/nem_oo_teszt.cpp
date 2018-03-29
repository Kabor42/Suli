/**
 * \file nem_oo_teszt.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * A C++ nem OO bõvítéseinek gyakorlásához.
 *
 * FELADATOK:
 *  1. Valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *  2. Valósítson meg a max.hpp fájlban, a Sajat névtéren belül egy olyan sablont, ami
 *     alaptípusok esetén a paraméterként kapott érték közül a nagyobbat adja.
 *  3. Specializálja a sablont a nem_oo.h állományban deklarált Komplex típusra
 *     úgy hogy a nagyobb abszolút értékû Komplex számot adja vissza!
 *
 *  Ellenõrizze a megvalósított függvények  és sablonok mûködését az alábbi tesztprogrammal!
 *
 * SZORGALMI FELADAT:
 *  Az ekezetes() függvény egy lehetõséget mutat az ékezetes
 *  karakterek C++ kódból való kiírására/kezelésére.
 *  Elemezze, értse meg a kódrészletet.
 *  Egy magyar nyelvûre állított Windows Windows-1250 karakterkódolást használ,
 *  ami lényegében megfelel a Latin-2 kódolásnak.
 *  Részben ezért, részben pedig azért Latin-2 használata a javasolt, mert
 *  1 betût 1 karakteren kódol.
 *
 *  Egy szövegfájl kódolásának megváltoztatására számos módszer van pl:
 *  1. Megnyitás notepad++ segítségével, mentás a kívánt kólással
 *  2. Megnyitás a CodeBlocks editorában, Settings -> Editor -> Other settings -> Encoding
 *  3. iconv konverter használata (https://www.gnu.org/software/libiconv)
 *
 *
 */
#include <iostream>
#include <cstring>
#include <locale>

#define WINX defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#if WINX
#include <windows.h>
#endif // WINX

#include "nem_oo.h"
#include "max.hpp"

#define SORHOSSZ 1000

using std::cout;
using std::cin;
using std::endl;

void ekezetes();

/**
 * Ezt a tesztprogramot futtatja a JPORTA úgy, hogy a CPORTA definiált
*/
//#define CPORTA

int main() {
#ifndef CPORTA
    ekezetes();
#endif
    try {
#ifndef CPORTA
        cout << "\nSaját atoi próba.\n\"100\" 10-es, 8-as, és 2-es számrendszerben:" << endl;
#endif // CPORTA
        cout << sajat::atoi("100") << endl;     /// 10-es számrendszerben: 100
        cout << sajat::atoi("100", 8) << endl;  /// 8-asban: 64
        cout << sajat::atoi("100", 2) << endl;  /// 2-esben: 4

       /// kipróbáljuk az strcat-ot:
#ifndef CPORTA
        cout << "\nSaját strcat próba:" << endl;
#endif // CPORTA
        char *str = sajat::strcat("Ez egy mondat.", " Ez kicsit hosszabb mondat.\n");
        cout << str;
        delete[] str;                /// Nekünk kell felszabadítani!

       /// kipróbáljuk a max-ot
#ifndef CPORTA
        cout << "\nSaját max próba:" << endl;
#endif // CPORTA
        int i1 = 10;
        int i2 = 200;
#ifndef CPORTA
        cout << "max(" << i1 << ", " << i1 <<")= ";
#endif // CPORTA
        cout << sajat::max(i1, i2) << endl;

        double d1 = 123.5;
        double d2 = -34.4;
#ifndef CPORTA
        cout << "max(" << d1 << ", " << d2 <<")= ";
#endif // CPORTA
        cout << sajat::max(d1, d2) << endl;
        sajat::Komplex k1 = { 1, -3};
        sajat::Komplex k2 = { -40, 100 };
#ifndef CPORTA
        cout << "max(" << k1 << ", " << k2 <<")= ";
#endif // CPORTA
        cout <<  sajat::max(k1, k2) << endl;

        /// kipróbáljuk a unique-ot
        char test[] = "ssszia C+++++ + !";      /// sok ismétlõdõ kar.
#ifndef CPORTA
        cout << "\ntest tömb tartalma a uniq hívása elõtt\n";
        memtrace::mem_dump(&test, sizeof(test));
#endif // CPORTA
        cout << test << endl;
        char *p = sajat::unique(test, test+strlen(test));
#ifndef CPORTA
        cout << "\nuniq hívása után p: " << (void*)p << endl;
        memtrace::mem_dump(&test, sizeof(test));
#endif // CPORTA
        *p = 0;                      /// p az új sorozat végére mutat
        cout << test << endl;;
#ifndef CPORTA
        if (strcmp(test, "szia C+ + !") != 0)
            cout << "*** Hibás a unique ****" << endl;
        if (p != test + 11)
            cout << "*** Hibás unique: nem jó a visszatérési érték ***" << endl;
        char test2[19] = "sss\0zia C+++++ + !";      /// lezáró nullával együtt 19 byte hossz=18
        p = sajat::unique(test2, test2+18);
        *p = '#';
        if (memcmp(test2, "s\0zia C+ + !#", 13) != 0) {
            cout << "*** Hibas unique: \\0 végjelet keres, vagy nem jó visszatérési értéket ad. ***" << endl;
            memtrace::mem_dump(&test2, 19);
        }
#endif // CPORTA
        /// itt egy nagyobb próba következik a standard inputról
        int base = 9;				/// ebben a számrendszerben várjuk az elsõ sort
#ifndef CPORTA
        cout << "Számot várunk (base: " << base << "):";
#endif // CPORTA
        char buf1[SORHOSSZ];
        while (cin.getline(buf1, SORHOSSZ)) {       /// amíg van adat
            char buf2[SORHOSSZ];
            buf2[0] = 0;
#ifndef CPORTA
            cout << "Tetszõleges szöveget várunk: ";
#endif // CPORTA
            if (!cin.getline(buf2, SORHOSSZ))
                break;                              /// váratlanul fáj vége jött
            str = sajat::strcat(buf1, buf2);        /// két soronként összefûzzük az inputot
#ifndef CPORTA
            cout << "A két sor összefûzve: ";
#endif // CPORTA
            cout << str << endl;                    /// kiírjuk
#ifndef CPORTA
            cout << "Unique után:";
#endif // CPORTA
            p = sajat::unique(str, str+strlen(str));
            *p = 0;
            cout << str << endl;
            delete[] str;                           /// nem kell tovább a string
#ifndef CPORTA
            cout << "A beolvasott szám átalakítva: ";
#endif // CPORTA
            int val = sajat::atoi(buf1, base); 	    /// átalakítás base rendszerbõl
            cout << val << endl; 			        /// kiírjuk
            base  = val % 9 + 2;			        /// ebben a számrendszerben várjuk legközelebb
#ifndef CPORTA
            cout << "Számot várunk (base: " << base << "):";
#endif // CPORTA
        }
        cout << "Nem dobott kivételt!" << endl;
    } catch (const char *p) {
        cout << "const char* kivétel jött: " << p << endl;
    } catch (...) {
        cout << "Baj van: Nem vart kivétel jött" << endl;
    }
    return 0;
}

void ekezetes() {
    /// Alapértelmezett környezet beállítása (remélhetõleg latin2).
    /// Ha nem latin2, akkor az ékezetes kiírások nem jól látszanak,
    /// mert ez a fájl latin2 kódolású
    char *p = setlocale(LC_ALL, "");
#if WINX
    SetConsoleCP(1250);           /// Windows alatt ez is kell
    SetConsoleOutputCP(1250);
#endif
    cout << "\nA beállított környezet: " << p << endl;
    cout << "Árvíztûrõ tükörfúrógép" << endl;
    cout << "Írj be egy szöveget: ";
    char buf1[SORHOSSZ];
    cin.getline(buf1, SORHOSSZ);
    cout << "Ezt írtad: " << buf1 << endl;
}

/**
 * Ellenõrizzük, hogy valóban készített-e max sablont:
 *  Specializáljuk, ha tudjuk, akkor tényleg sablon.
 */
namespace sajat {
    template<>
    bool max(bool a, bool b) { return 0;} /// Nem használjuk, csak trükk:
    /// Ha itt fordítási hibát kap, akkor nem sablonnal oldotta meg a max függvényt!
}
