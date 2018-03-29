/**
 * \file string2_main.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * C++ nyelvre átírt dinamikus String működését teszteli.
 *
 * Ha a javasolt sorrendben oldja meg a feladatot, akkor lépésről-lépésre
 * tesztelheti az elkészített függvényeket. Ehhez a string1.h fájlban definiált
 * ELKESZULT makró értékét kell megfelelően változtatni.
 *
 * A C verzióval ellentétben nem csak szemrevételezéssel ellenőrizzük az egyes
 * függvények helyességét, hanem a gtest_lite EXPECT_... makróival is.
 *
 * C változatnál látott szöveges kiírások akkor látszanak, ha a DEBUG azonosító definiált.
 */

/**
 *
 * A példa a dinamikus memória használatánál előforduló hibákat
 * a labor útmutatóban ismertetett memtrace módszerrel ellenőrzi.
 *
 * Az ellenőrzés aktivizálásához minden fájl elején definiálni kell
 * a MEMTRACE makrót. Ezt célszerű fordítási opcióként megadni.
 * (ld. a labor útmutatójában)
 */

#include <cstring>          /// Sztringműveletekhez
#include <functional>

/// malloc, new felüldefiniálásával készített memóriaszivárgás és konzisztencia ellenőrző
#include "memtrace.h"       /// a standard headerek után kell lennie
#include "gtest_lite.h"

#include "string2.h"

using std::cout;
using std::endl;

int main() {
    TEST(String2, Inic) {
      String a; createString(a);
      EXPECT_EQ((unsigned int)0, StringLen(a));
      EXPECT_EQ((const char*)NULL, StringC_str(a));
    } ENDM

    String a; createString(a, 'x');      /// 'a' létrehozása
    TEST(String2, FromChar) {
      EXPECT_EQ((unsigned int)1, StringLen(a));
      EXPECT_STREQ("x", StringC_str(a));
      printStringDbg(a);	             /// Ezt kellene látni: [1], x|
    } ENDM

// Ha létezik a createString(String&, const char*) függvény.
#if ELKESZULT >= 1
    String b; createString(b, "alma");   /// 'b' létrehozása
    TEST(String2, FromCstr) {
      EXPECT_EQ((unsigned int)4, StringLen(b));
      EXPECT_STREQ("alma", StringC_str(b));
      printStringDbg(b);                 /// Ezt kellene látni: [4], alma|
    } ENDM
#endif

// Ha létezik a createString(String&, const String&) függvény.
#if ELKESZULT >= 2
    String c; createString(c, b);       /// 'c' létrehozása
    TEST(String2, FromStr) {
      EXPECT_EQ((unsigned int)4, StringLen(b));
      EXPECT_STREQ("alma", StringC_str(b));
      printStringDbg(b);                 /// Ezt kellene látni: [4], alma|
    } ENDM
#endif

// Ha létezik a charAtString(const String& s0, unsigned int idx) függvény.
#if ELKESZULT >= 3
    TEST(String2, CharAt3) {
      char ch;
      EXPECT_NO_THROW(ch = charAtString(b, 3));
      EXPECT_EQ('a', ch);
    #ifdef DEBUG
      cout << charAtString(b, 3) << endl; /// Ezt kellene látni: a
    #endif
    } ENDM

    TEST(String2, CharAt4) {
      EXPECT_THROW(charAtString(b, 4), const char*);
    } END

    TEST(String2, CharAt_1) {
      EXPECT_THROW(charAtString(b, -1), const char*);
    } ENDM
#endif

// Ha létezik az addString(cont String&, char) függvény.
#if ELKESZULT >= 4
    String d = addString(a, b);  /// Összefűzzük a két sztringet egy újba
    TEST(String2, AddStr2Str1) {
      EXPECT_EQ((unsigned int)5, StringLen(d));
      EXPECT_STREQ("xalma", StringC_str(d));
      printStringDbg(d);                 /// Ezt kellene látni: [5], xalma|
    } ENDM
#endif

// Ha létezik az addString(const String&, const String& b) függvény.
#if ELKESZULT >= 5
    String e = addString(b, c);
    TEST(String2, AddStr2Str2) {
      EXPECT_EQ((unsigned int)8, StringLen(e));
      EXPECT_STREQ("almaalma", StringC_str(e));
      printStringDbg(e);                 /// Ezt kellene látni: [8], almaalma|
    } ENDM
//
    disposeString(e);                    /// e-t másra akarjuk használni, felszabadítjuk
    e = addString(d, 'A');
    TEST(String2, AddStr2Str2) {
      EXPECT_EQ((unsigned int)6, StringLen(e));
      EXPECT_STREQ("xalmaA", StringC_str(e));
      printStringDbg(e);                 /// Ezt kellene látni: [6], xalmaA|
    } ENDM
#endif

// Attól függően, hogy mi keletkezett, fel is kell azokat szabadítani
#if ELKESZULT >= 5
    disposeString(e);
#endif
#if ELKESZULT >= 4
    disposeString(d);
#endif
#if ELKESZULT >= 2
    disposeString(c);
#endif
#if ELKESZULT >= 1
    disposeString(b);
#endif
    disposeString(a);
    return 0;
}
