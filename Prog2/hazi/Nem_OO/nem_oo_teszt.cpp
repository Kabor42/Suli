/**
 * \file nem_oo_teszt.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * A C++ nem OO b�v�t�seinek gyakorl�s�hoz.
 *
 * FELADATOK:
 *  1. Val�s�tsa meg a nem_oo.h �llom�nyban deklar�lt f�ggv�nyeket!
 *  2. Val�s�tson meg a max.hpp f�jlban, a Sajat n�vt�ren bel�l egy olyan sablont, ami
 *     alapt�pusok eset�n a param�terk�nt kapott �rt�k k�z�l a nagyobbat adja.
 *  3. Specializ�lja a sablont a nem_oo.h �llom�nyban deklar�lt Komplex t�pusra
 *     �gy hogy a nagyobb abszol�t �rt�k� Komplex sz�mot adja vissza!
 *
 *  Ellen�rizze a megval�s�tott f�ggv�nyek  �s sablonok m�k�d�s�t az al�bbi tesztprogrammal!
 *
 * SZORGALMI FELADAT:
 *  Az ekezetes() f�ggv�ny egy lehet�s�get mutat az �kezetes
 *  karakterek C++ k�db�l val� ki�r�s�ra/kezel�s�re.
 *  Elemezze, �rtse meg a k�dr�szletet.
 *  Egy magyar nyelv�re �ll�tott Windows Windows-1250 karakterk�dol�st haszn�l,
 *  ami l�nyeg�ben megfelel a Latin-2 k�dol�snak.
 *  R�szben ez�rt, r�szben pedig az�rt Latin-2 haszn�lata a javasolt, mert
 *  1 bet�t 1 karakteren k�dol.
 *
 *  Egy sz�vegf�jl k�dol�s�nak megv�ltoztat�s�ra sz�mos m�dszer van pl:
 *  1. Megnyit�s notepad++ seg�ts�g�vel, ment�s a k�v�nt k�l�ssal
 *  2. Megnyit�s a CodeBlocks editor�ban, Settings -> Editor -> Other settings -> Encoding
 *  3. iconv konverter haszn�lata (https://www.gnu.org/software/libiconv)
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
 * Ezt a tesztprogramot futtatja a JPORTA �gy, hogy a CPORTA defini�lt
*/
//#define CPORTA

int main() {
#ifndef CPORTA
    ekezetes();
#endif
    try {
#ifndef CPORTA
        cout << "\nSaj�t atoi pr�ba.\n\"100\" 10-es, 8-as, �s 2-es sz�mrendszerben:" << endl;
#endif // CPORTA
        cout << sajat::atoi("100") << endl;     /// 10-es sz�mrendszerben: 100
        cout << sajat::atoi("100", 8) << endl;  /// 8-asban: 64
        cout << sajat::atoi("100", 2) << endl;  /// 2-esben: 4

       /// kipr�b�ljuk az strcat-ot:
#ifndef CPORTA
        cout << "\nSaj�t strcat pr�ba:" << endl;
#endif // CPORTA
        char *str = sajat::strcat("Ez egy mondat.", " Ez kicsit hosszabb mondat.\n");
        cout << str;
        delete[] str;                /// Nek�nk kell felszabad�tani!

       /// kipr�b�ljuk a max-ot
#ifndef CPORTA
        cout << "\nSaj�t max pr�ba:" << endl;
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

        /// kipr�b�ljuk a unique-ot
        char test[] = "ssszia C+++++ + !";      /// sok ism�tl�d� kar.
#ifndef CPORTA
        cout << "\ntest t�mb tartalma a uniq h�v�sa el�tt\n";
        memtrace::mem_dump(&test, sizeof(test));
#endif // CPORTA
        cout << test << endl;
        char *p = sajat::unique(test, test+strlen(test));
#ifndef CPORTA
        cout << "\nuniq h�v�sa ut�n p: " << (void*)p << endl;
        memtrace::mem_dump(&test, sizeof(test));
#endif // CPORTA
        *p = 0;                      /// p az �j sorozat v�g�re mutat
        cout << test << endl;;
#ifndef CPORTA
        if (strcmp(test, "szia C+ + !") != 0)
            cout << "*** Hib�s a unique ****" << endl;
        if (p != test + 11)
            cout << "*** Hib�s unique: nem j� a visszat�r�si �rt�k ***" << endl;
        char test2[19] = "sss\0zia C+++++ + !";      /// lez�r� null�val egy�tt 19 byte hossz=18
        p = sajat::unique(test2, test2+18);
        *p = '#';
        if (memcmp(test2, "s\0zia C+ + !#", 13) != 0) {
            cout << "*** Hibas unique: \\0 v�gjelet keres, vagy nem j� visszat�r�si �rt�ket ad. ***" << endl;
            memtrace::mem_dump(&test2, 19);
        }
#endif // CPORTA
        /// itt egy nagyobb pr�ba k�vetkezik a standard inputr�l
        int base = 9;				/// ebben a sz�mrendszerben v�rjuk az els� sort
#ifndef CPORTA
        cout << "Sz�mot v�runk (base: " << base << "):";
#endif // CPORTA
        char buf1[SORHOSSZ];
        while (cin.getline(buf1, SORHOSSZ)) {       /// am�g van adat
            char buf2[SORHOSSZ];
            buf2[0] = 0;
#ifndef CPORTA
            cout << "Tetsz�leges sz�veget v�runk: ";
#endif // CPORTA
            if (!cin.getline(buf2, SORHOSSZ))
                break;                              /// v�ratlanul f�j v�ge j�tt
            str = sajat::strcat(buf1, buf2);        /// k�t soronk�nt �sszef�zz�k az inputot
#ifndef CPORTA
            cout << "A k�t sor �sszef�zve: ";
#endif // CPORTA
            cout << str << endl;                    /// ki�rjuk
#ifndef CPORTA
            cout << "Unique ut�n:";
#endif // CPORTA
            p = sajat::unique(str, str+strlen(str));
            *p = 0;
            cout << str << endl;
            delete[] str;                           /// nem kell tov�bb a string
#ifndef CPORTA
            cout << "A beolvasott sz�m �talak�tva: ";
#endif // CPORTA
            int val = sajat::atoi(buf1, base); 	    /// �talak�t�s base rendszerb�l
            cout << val << endl; 			        /// ki�rjuk
            base  = val % 9 + 2;			        /// ebben a sz�mrendszerben v�rjuk legk�zelebb
#ifndef CPORTA
            cout << "Sz�mot v�runk (base: " << base << "):";
#endif // CPORTA
        }
        cout << "Nem dobott kiv�telt!" << endl;
    } catch (const char *p) {
        cout << "const char* kiv�tel j�tt: " << p << endl;
    } catch (...) {
        cout << "Baj van: Nem vart kiv�tel j�tt" << endl;
    }
    return 0;
}

void ekezetes() {
    /// Alap�rtelmezett k�rnyezet be�ll�t�sa (rem�lhet�leg latin2).
    /// Ha nem latin2, akkor az �kezetes ki�r�sok nem j�l l�tszanak,
    /// mert ez a f�jl latin2 k�dol�s�
    char *p = setlocale(LC_ALL, "");
#if WINX
    SetConsoleCP(1250);           /// Windows alatt ez is kell
    SetConsoleOutputCP(1250);
#endif
    cout << "\nA be�ll�tott k�rnyezet: " << p << endl;
    cout << "�rv�zt�r� t�k�rf�r�g�p" << endl;
    cout << "�rj be egy sz�veget: ";
    char buf1[SORHOSSZ];
    cin.getline(buf1, SORHOSSZ);
    cout << "Ezt �rtad: " << buf1 << endl;
}

/**
 * Ellen�rizz�k, hogy val�ban k�sz�tett-e max sablont:
 *  Specializ�ljuk, ha tudjuk, akkor t�nyleg sablon.
 */
namespace sajat {
    template<>
    bool max(bool a, bool b) { return 0;} /// Nem haszn�ljuk, csak tr�kk:
    /// Ha itt ford�t�si hib�t kap, akkor nem sablonnal oldotta meg a max f�ggv�nyt!
}
