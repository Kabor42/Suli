/**
 * \file string5_test.cpp
 *
 * Tesztprogram az String oszt�ly tesztel�s�hez.
 *
 */

#include <iostream>
#include <sstream>
#include <clocale>
#if defined(WIN32) || defined(_WIN32)
# include <windows.h>
#endif

#include "memtrace.h"     // a standard header-ek ut�n kell lennie
#include "string5.h"
#include "rendez.h"
#include "gtest_lite.h"

using std::cout;
using std::cin;
using std::endl;


int main() {
/**
 *  1. A param�ter n�lk�l h�vhat� konstruktora �res sztringet hozzon �tre!
 */
#if ELKESZULT >= 1
    TEST(Elkeszult1, construct) {
      String ures;
      ures.printDbg("Ures sztring: ");   // debug ki�rat�s
      if (ures.size() == 0)
        SUCCEED() << "Hurra! Van egy sztringem, de nem biztos, hogy ures!" << endl;
      else
        FAIL() << "Baj van a string hosszaval" << endl;
    } ENDM
#endif

/**
 *  2. Van olyan tagf�ggv�nye ( c_str() ), ami C-sztringgel, azaz null�val lez�rt
 *     karaktersorozatra mutat� pointerel (const char *) t�r vissza.
 */
#if ELKESZULT >= 2
    TEST(Elkeszult2, emptyStr) {
      String ures;
      EXPECT_EQ((size_t)0, ures.size()) << "Baj van a string hosszaval" << endl;
      EXPECT_STREQ("", ures.c_str()) << "Nem ures sztring jott letre" << endl;
    } ENDM
#endif

/**
 * 3. Van olyan konstruktora, ami karakterb�l hoz l�tre sztringet.
 */
#if ELKESZULT >= 3
    TEST(Elkeszult3, fromChr) {
      char ch = 'a';
      String a(ch);
      EXPECT_EQ((size_t)1, a.size()) << "Baj van a string hosszaval" << endl;
      EXPECT_STREQ("a", a.c_str()) << "Karakterbol sztring letrehozasa nem silerult!" << endl;
      String b('a');    // konstansb�l is megy?
      EXPECT_STREQ("a", b.c_str()) << "Karakterbol sztring letrehozasa nem silerult!" << endl;
    } ENDM
#endif

/**
 *  4. Van olyan konstruktora, ami C-sztringb�l (const char*) hoz l�tre sztringet.
 */
#if ELKESZULT >= 4
    TEST(Elkeszult4, FromCstr) {
      const char *hello = "Hello sztring";
      String a(hello);
      EXPECT_EQ(strlen(hello), a.size()) << "Baj van a string hosszaval" << endl;
      EXPECT_STREQ(hello, a.c_str()) << "C-szringbol string letrehozasa nem silerult!" << endl;
      const char *p = hello;
      String b(p);      // konstansb�l is megy?
      EXPECT_STREQ(hello, b.c_str()) << "C-szringbol string letrehozasa nem silerult!" << endl;
    } ENDM
#endif

/**
 *  5. Az oszt�lyb�l l�trehozott objektum legyen �tadhat� �rt�kparam�terk�nt!
 */
#if ELKESZULT >= 5
    TEST(Elkeszult5, ctor) {
      const char *hello = "Hello sztring";
      String a(hello);
      String b = a;
      EXPECT_EQ(strlen(hello), b.size()) << "Baj van a string hosszaval!" << endl;
      EXPECT_STREQ(hello, b.c_str()) << "Baj van a masolo konstruktorral!" << endl;
      EXPECT_STREQ(hello, a.c_str()) << "Masolo kontsr. elromlott a forras!" << endl;
      EXPECT_EQ(strlen(hello), a.size()) << "Masolo konstr. alatt elromlott a forras hossza!" << endl;
      const String c = a;
      String d = c;     // konstansb�l is megy?
      EXPECT_STREQ("Hello sztring", d.c_str()) << "Baj van a masolo konstruktorral" << endl;
    } ENDM
#endif

/**
 *  6. T�mogassa a t�bbsz�r�s �rt�kad�st (b = a = a)!
 */
#if ELKESZULT >= 6
    TEST(Elkeszult6, opAssign) {
      const char *hello = "Hello sztring";
      String a(hello);
      String b("Duma1"), c("Duma2");
      EXPECT_STRNE(a.c_str(), b.c_str());
      a = a;
      EXPECT_EQ(strlen(hello), a.size()) << "Baj van az ertekadassal: a = a hossz" << endl;
      EXPECT_STREQ(hello, a.c_str()) << "Baj van az ertekadassal: a = a" << endl;
      c = b = a;
      EXPECT_EQ(strlen(hello), a.size()) << "Ertekedasnal elromlott a forras hossza!" << endl;
      EXPECT_STREQ(hello, a.c_str()) << "Ertekadasnal elromlott a frorras!" << endl;
      EXPECT_EQ(strlen(hello), b.size()) << "Ertekedas: nem jo a hossz!" << endl;
      EXPECT_STREQ(hello, b.c_str()) << "Ertekadas nem sikerult!" << endl;
      EXPECT_EQ(strlen(hello), c.size()) << "Ertekedas: nem jo a hossz!" << endl;
      EXPECT_STREQ(hello, c.c_str()) << "Ertekadas nem sikerult!" << endl;
      const String d("Konst.");
      c = d;        // konstansb�l is megy?
      EXPECT_EQ(c.size(), c.size()) << "Ertekedas konstansbol: nem jo a hossz!" << endl;
      EXPECT_STREQ(d.c_str(), c.c_str()) << "Ertekadas konstansbol nem sikerult!" << endl;
    } ENDM
#endif

/**
 *  7. Legyenek olyan oper�torai (operator+), amivel a sztring v�g�hez sztringet
 *     �s karaktert lehet f�zni!
 */
#if ELKESZULT >= 7
    TEST(Elkeszult7, strPlusStr) {
      String a("Hello ");
      String b("sztring");
      String c;
      c = a + b;
      EXPECT_STREQ("Hello sztring", c.c_str()) << "Nem sikerult a + String muvelet!" << endl;
      EXPECT_STREQ("Hello ", a.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;
      EXPECT_STREQ("sztring", b.c_str()) << "A + muvelet elrontja a jobb oldalt?" << endl;
      const String a1 = a, b1 = b;
      String c1;
      c1 = a1 + b1;          // konstansb�l is megy?
      EXPECT_STREQ("Hello sztring", c1.c_str()) << "Nem sikerult a + String muvelet!" << endl;
    } ENDM

    TEST(Elkeszult7, strPlusChr) {
      String a("Hello ");
      String b;
      b = a + 'B';
      EXPECT_STREQ("Hello B", b.c_str()) << "Nem sikerult a + char muvelet!" << endl;
      EXPECT_STREQ("Hello ", a.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;
      const String a1 = a;
      String b1;
      b1 = a1 + 'B';          // konstansb�l is megy?
      EXPECT_STREQ("Hello B", b1.c_str()) << "Nem sikerult a + char muvelet!" << endl;
      EXPECT_STREQ("Hello ", a1.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;

    } ENDM
#endif

/**
 *  8. Lehessen karakterhez is sztringet f�zni a + oper�torral!
 */
#if ELKESZULT >= 8
    TEST(Elkeszult8, chrPlusStr) {
      String a("ello");
      String b;
      char h = 'H';
      b = h + a;
      EXPECT_STREQ("Hello", b.c_str()) << "Nem sikerult char + Str muvelet!" << endl;
      EXPECT_STREQ("ello", a.c_str()) << "A + muvelet elrontja a jobb oldalt?" << endl;
      String b1;
      b1 = 'H' + a;  // konstanssal is megy?
      EXPECT_STREQ("Hello", b.c_str()) << "Nem sikerult char + Str muvelet!" << endl;
    } ENDM
#endif

/**
 *  9. A t�rolt a karakterek legyenek el�rhet�ek a szok�sos m�don indexel�ssel!
 *     Az indexel�ssel el�rt elem legyen haszn�lhat� bal�rt�kk�nt is!
 *     A konstans objektumok is legyenek indexelhet�k.
 *     Az indexel�s oper�tor hiba eset�n dobjon const char * kiv�telt!
 */
#if ELKESZULT >= 9
    TEST(Elkeszult9, index) {
      String a("Hello 678");
      EXPECT_NO_THROW(a[0]);
      EXPECT_NO_THROW(a[7]);
      EXPECT_NO_THROW(a[8]);
      EXPECT_THROW(a[9], const char *);
      EXPECT_THROW(a[-1], const char *);
      EXPECT_EQ('7', a[7]);
      a[7] = '.';
      EXPECT_EQ('.', a[7]);
    } ENDM
#endif

/**
 * 10. K�sz�tsen olyan << oper�tort, amivel egy sztring ki�rhat� egy ostream t�pus�
 *     objektumra!
 */
#if ELKESZULT >= 10
    TEST(Elkeszult10, extract) {
      String a("Hello sztring");
      std::stringstream ss;
      ss << a;
      EXPECT_STREQ("Hello sztring", ss.str().c_str());
    } ENDM
#endif

/**
 * 11. K�sz�tsen olyan f�zhet� >> oper�tort, amivel be tud olvasni egy sz�t egy sztring-be!
 *     A beolvas� m�k�dj�n �gy, mint a scanf %s, azaz a sz� v�g�t white space hat�rolja!
 *     A sz� eleji white space karaktereket pedig el kell dobni.
 *    *Megj: az istream wshite space kezel�se a flags() tagf�ggv�nnyel szab�lyozhat�
 */
 #if ELKESZULT >= 11
    TEST(Elkeszult11, insert) {
      String a("Hello   sztring \n Lajos12");
      std::stringstream ss;
      ss << a;
      String in1, in2, in3;
      ss >> in1 >> in2;         // f�zhet�nek kell lenni
      while (ss >> in3);        // csak kicsit gonosz a teszt !
      EXPECT_STREQ("Hello", in1.c_str());
      EXPECT_STREQ("sztring", in2.c_str());
      EXPECT_STREQ("Lajos12", in3.c_str());
    } ENDM
#endif

/**
 * 12. Pr�b�lja ki az �kezetes sz�vegekkel az elk�sz�tett String oszt�lyt!
 *     Seg�ts�g�l elk�sz�tett�nk egy egyszer� k�dr�szletet ami szavakat olvas be,
 *     majd qsort() f�ggv�nnyel rendezi azokat.
 *     Az �kezetes karakterek k�dol�s�val kapcsolatban kor�bban m�r volt egy egyszer�
 *     szorgalmi feladat feladat. Most a rendez�sen van a hangs�ly.
 *     �rtse meg a rendez.cpp f�jlban lev� k�d m�k�d�s�t �s futtassa a programot!
 */
#if ELKESZULT == 12
    rendez();
#endif

/**
 * 13. A setlocale f�ggv�nyh�v�s be�ll�tja a karakterek �s sztringek �sszehasonl�t�s�hoz
 *     sz�ks�ges nyelvi k�rnyezetet (LC_COLLATE) pr�b�lja ki! V�ltozott a rendez�si
 *     sorrend?
 */
#if ELKESZULT >= 13
    cout << endl;
    /// be�ll�tja az op.rendszer �ltal haszn�lt nyelvi k�rnyezetet, amit felt�telez�nk, hogy magyar
    cout << "Nyelvi beallitas: " << setlocale(LC_ALL, "") << endl;

 #if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
    /// Windows alatt egy�b var�zslatra is sz�ks�g van ...
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
 #endif
    rendez();
#endif

    TEST(String, MindenFeladatKesz) {
        EXPECT_EQ(10, ELKESZULT) << "Addig nincs siker, "
                                    "amig nem keszult el az elso 10 feladat!" << std::endl;
    } ENDM
    return 0;
}
