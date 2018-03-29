/*
 * \file main.cpp
 *
 * Tesztprogram az Ember, Hallgato �s a Kutato oszt�lyok tesztel�s�hez.
 *
 * �rtse meg a programot �s k�sz�tse el az ember.h �llom�nyt!
 *
 * Megj: A nagy h�zi feladat tesztel�s�hez is hasonl� tesztel�si met�dust aj�nlunk.
 *
 *
 *** FONTOS ***
 * A MEMTRACE makr�nak minden ford�t�si egys�gben defini�lt kell, hogy legyen!
 * Ezt legk�nyelmesebben projekt szint� be�ll�t�ssal tudja el�rni.
 *   (Projekt->Build options->#defines)
 *
 */

#include <iostream>
#include <ctime>
#include "ember.h"
#include "hallgato.h"
#include "kutato.h"
#include "gtest_lite.h" // tesztel�st seg�t� makr�k
#include "memtrace.h"

using std::cout;
using std::endl;
using std::cin;



// Seg�df�ggv�ny a beolvas�sok el�tti �zenetek ki�r�s�hoz
// JPORTA-n nem k�r�nk ilyen ki�r�sokat
inline void prompt(const char *msg) {
#ifndef CPORTA
    cout << msg;
#endif // CPORTA
}

// Ember referenci�t kap. ki�r �s ellen�riz
void kiirEll(Ember& e, int ma, const char* nev, const char *fogl, int szul) {
    EXPECT_STREQ(nev, e.getNev());
    cout << "Nevem: " << e.getNev() << endl;
    EXPECT_EQ(ma-szul, e.getKor(ma));
    cout << "Korom: " << e.getKor(ma) << endl;
    EXPECT_STREQ(fogl, e.foglalkozas()) << "!** virtualis a foglalkozas?" << endl;
    cout << "Foglalkozasom: " << e.foglalkozas() << endl;
    EXPECT_EQ(2020-szul, e.getKor(2020));
    cout << "2020-ban " << e.getKor(2020) << " eves leszek" << endl;
    cout << endl;
}

// Ember pointert kap. ki�r �s ellen�riz
void kiirEllp(Ember *p, int ma, const char* nev, const char *fogl, int szul) {
    EXPECT_STREQ(nev, p->getNev());
    cout << "Nevem: " << p->getNev() << endl;
    EXPECT_EQ(ma-szul, p->getKor(ma));
    cout << "Korom: " << p->getKor(ma) << endl;
    EXPECT_STREQ(fogl, p->foglalkozas());
    cout << "Foglalkozasom: " << p->foglalkozas() << endl;
    EXPECT_EQ(2020-szul, p->getKor(2020));
    cout << "2020-ban " << p->getKor(2020) << " eves leszek" << endl;
    cout << endl;
}

// Ember adattagjainak l�that�s�gi tesztje
// Hallgat� nev�nek (neptun) tesztje
void test_1(int ma) {
    TEST(test1, kiir) {  // lehetne finomabban a teszteket
      Hallgato en;
      cout << "Nevem: " << en.getNev() << endl;
      cout << "Korom: " << en.getKor(ma) << endl;
      EXPECT_STREQ("Hallgato", en.foglalkozas());
      cout << "Foglalkozasom: " << en.foglalkozas() << endl;
      cout << "2020-ban " << en.getKor(2020) << " eves leszek" << endl << endl;
    } ENDM
}

// Hallgat� teszt ember referenci�val
void test_2(int ma) {
    TEST(tesz2, kiir) {
      Hallgato butus("Buta Toni", "BT1234", 1975);
      kiirEll(butus, ma, "Buta Toni", "Hallgato", 1975); // ki�rja �s ellen�rzi az adatokat
    } ENDM
}

// m�sol� konstruktor �s a kiv�telkezel�s m�k�d�s�nek ellen�rz�se
void test_3(int ma) {
    TEST(test3, kiir) {
      Hallgato toni("Okos Toni", "TUDOR6", 1970);
      Hallgato valaki = toni;	// m�sol� konstruktor pr�ba

      EXPECT_STREQ("TUDOR6", valaki.getNeptun()); // lem�sol�dott a neptun is? Ki m�solta le?
      Ember *okos = &valaki;
      kiirEllp(okos, ma, "Okos Toni", "Hallgato", 1970); // ki�rja �s ellen�rzi az adatokat

      // Azt v�rjuk, hogy kiv�telt dobjon
      EXPECT_THROW(cout << okos->getKor(1900), const char*) << "!** virtualis a getkor?" << endl;
      cout << "1900-ban hany eves voltal?" << endl;
      cout << okos->getKor(1900) << endl;
    } ENDM // nem jut ide a kiv�tel miatt
}

// Komplex teszt
void test_4(int ma) {
    TEST(test4, kkir) {
      Hallgato en;        // Annak a NEPTUN-k�dja �s sz�let�si �ve, aki az Ember oszt�lyt k�sz�tette
      Hallgato toni("Okos Toni", "TUDOR6", 1970);
      Hallgato butus("Buta Toni", "BT1234", 1975);
      Hallgato valaki = butus;	// m�sol� konstruktor pr�ba
      Kutato cppFather("Bjarne Stroustrup", 1950);

      toni = toni;        // �rt�kad�s �nmag�nak
      en = valaki;        // �rt�kad�s

      EXPECT_STREQ("BT1234", en.getNeptun()); // lem�sol�dott a neptun is? Ki m�solta le?
      kiirEll(en, ma, "Buta Toni", "Hallgato", 1975);

      kiirEll(cppFather, ma, "Bjarne Stroustrup", "Kutato", 1950); // �rt�kparam�terk�nt kapja

      Ember *gatto = new Hallgato("Hall Gatto", "GAT123", 1987);  // dinamikus p�ld�ny

      kiirEll(*gatto, ma, "Hall Gatto", "Hallgato", 1987);

      kiirEll(toni, ma, "Okos Toni", "Hallgato", 1970);
      EXPECT_STREQ("TUDOR6", toni.getNeptun()); // neptun is j�?

      // dinamikus p�ld�ny t�rl�se alaposzt�ly pointer�re hivatkozva
      cout << "Megszuntetes is megy az alaposztaly felol?" << endl;
      cout << "Kiderul, ha kilep a programbol!" << endl << endl;
      delete gatto;
    } ENDM
}
#include <typeinfo>

int main() {
  Ember e;
  time_t act = time(NULL);
  struct tm *lt = localtime(&act);
  int ma = lt->tm_year+1900;
  int testNr;
  const char *prompt_txt = "Teszteset (1-4) (0: vege): ";
  prompt(prompt_txt);
  while (cin >> testNr && testNr != 0) {  // * 0-ig, vagy am�g tud sz�mot olvasni
    try {
      switch (testNr) {
        case 1: test_1(ma); break;
        case 2: test_2(ma); break;
        case 3: test_3(ma); break;
        case 4: test_4(ma); break;
      }
    } catch (const char *p) {
      cout << p << endl << endl;
    } catch (...) {
      cout << "Baj van!" << endl;
    }
    cout << endl;
    prompt(prompt_txt);
  }
  return 0;
}
