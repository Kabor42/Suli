/**
 * file Komplex_teszt.cpp
 *
 * Komplex osztály tesztesetei gtest_lite/gtest eszközkészletével megvalósítva.
 *
 * A laborfeladat megoldásához ebben az állományban nem kell módosítani.
 *
 * A komplex.h-ban definiált ELKESZULT makró vezérli az egyes tesztesetek
 * fordítását. A legutolsó teszteset az ELKESZULT értékét vizsgálja.
 *
 */
#include <iostream>
#include <sstream>

/**
 * Ha a GTEST definiált, akkor ez a tesztprogram a Google gtest keretrendszerével
 * működik együtt.
 * (Ehhez természetesen telepíteni kell a Google gtest keretrendszert.)
 */

#include "gtest_lite.h"

#include "komplex.h"

int main() {

/// Konstruktorok létezésének tesztje
TEST(KomplexTest000, Proba) {
    Komplex k, k1(1), k2(1,2);
    EXPECT_EQ(1, k1.getRe());
} END

#if ELKESZULT >= 1
/// Már van getRe() és getIm(), így tesztelhetõk a konstruktorok
TEST(KomplexTest1, Ctor0) {		// 0 paraméteres konstruktor
    const Komplex k;
    EXPECT_EQ(0, k.getRe());
    EXPECT_EQ(0, k.getIm());
} END
TEST(KomplexTest1, Ctor1) {		// 1 paraméteres konstruktor
    const Komplex k(3.14);
    EXPECT_EQ(3.14, k.getRe()); // valósra az egyenlóség vizsg. itt még jó, mert ez nem számított eredmény
    EXPECT_EQ(0, k.getIm());
} END
TEST(KomplexTest1, Ctor2) {		// 2 paraméteres konstruktor
    const Komplex k(3.14, -2.71);
    EXPECT_EQ(3.14, k.getRe()); // valósra az egyenlóség vizsg. itt még jó, mert ez nem számított eredmény
    EXPECT_EQ(-2.71, k.getIm());
} END
#endif

#if ELKESZULT >= 2
/// Get-Set tesztek
TEST(KomplexTest2, GetSetRe) {	// valós rész
    Komplex k;
    EXPECT_EQ(0, k.getRe());
    k.setRe(3.14);
    EXPECT_EQ(3.14, k.getRe()); // valósra az egyenlóség vizsg. itt még jó, mert ez nem számított eredmény
    k.setIm(55);			    // azt nézzük, hogy elrontja-e a setIm a valós részt
    EXPECT_EQ(3.14, k.getRe());
} END
TEST(KomplexTest2, GetSetIm) {	// képzetes rész
    Komplex k, k1;
    EXPECT_EQ(0, k.getIm());
    k.setIm(3.14);
    EXPECT_EQ(3.14, k.getIm());
    k.setRe(55);			    // azt nézzük, hogy elrontja-e setRe a képzetes részt
    EXPECT_EQ(3.14, k.getIm());
    k1.setIm(3);			    // ha static lenne az adattag, akkor elromolna ez a teszt
    EXPECT_EQ(3.14, k.getIm());
} END
#endif

#if ELKESZULT >= 3
/// == és != operátorok tesztje
TEST(KomplexTest3, Equals) {
    const Komplex k1(1,2), k2(2,3), k3(1,2);
    EXPECT_FALSE(k1 == k2);
    EXPECT_TRUE(k1 == k3);
    EXPECT_TRUE(k1 == k1);
} END
TEST(KomplexTest3, NotEquals) {
    const Komplex k1(1,2), k2(2,3), k3(1,2);
    EXPECT_TRUE(k1 != k2);
    EXPECT_FALSE(k1 != k3);
    EXPECT_FALSE(k1 != k1);
} END
#endif

#if ELKESZULT >= 4
/// + operátorok tesztje
TEST(KomplexTest4, Add) {    // komplex + komplex
    const Komplex sum = Komplex(3.14,2.71) + Komplex(1,2);
    EXPECT_DOUBLE_EQ(4.14, sum.getRe());   // itt már nem pontos egyenlõséget vizsgálunk
    EXPECT_DOUBLE_EQ(4.71, sum.getIm());
} END
TEST(KomplexTest4, AddDbl) { // komplex + double
    const Komplex sum = Komplex(3.14,2.71) + 1.0;
    EXPECT_DOUBLE_EQ(4.14, sum.getRe());
    EXPECT_DOUBLE_EQ(2.71, sum.getIm());
} END
TEST(KomplexTest4, DblAdd) { // double + komplex
    const Komplex sum = 1.0 + Komplex(3.14,2.71);
    EXPECT_DOUBLE_EQ(4.14, sum.getRe());
    EXPECT_DOUBLE_EQ(2.71, sum.getIm());
} END
#endif

#if ELKESZULT >= 5
/// += operatorok tesztje
TEST(KomplexTest5, AssignmentPlus) {    // komplex += komplex
    Komplex sum(3.14,2.71);
    sum += Komplex(1,2);
    EXPECT_DOUBLE_EQ(4.14, sum.getRe());
    EXPECT_DOUBLE_EQ(4.71, sum.getIm());
} END
TEST(KomplexTest5, AssignmentPlusDbl) { // komplex + double
    Komplex sum(3.14,2.71);
    sum += 1.0;
    EXPECT_DOUBLE_EQ(4.14, sum.getRe());
    EXPECT_DOUBLE_EQ(2.71, sum.getIm());
} END
#endif

#if ELKESZULT >= 6
/// abszolútérték tagfüggvény tesztje
TEST(KomplexTest6, Abs) {
    EXPECT_DOUBLE_EQ(5, Komplex(3,-4).abs());
    EXPECT_DOUBLE_EQ(13, Komplex(5,12).abs());
} END
#endif

#if ELKESZULT >= 7
/// beolvasás és kiírás tesztje
TEST(KomplexTest7, Write) {
    std::ostringstream oss;     // stringstream-be írunk, és szövegesen hasonlítunk !
    oss << Komplex(-3.14, 2.71) << '\t' << Komplex(3.14, -2.71);
    EXPECT_EQ("-3.14+2.71j\t3.14-2.71j", oss.str());
} END
TEST(KomplexTest7, Read) {
    Komplex k1, k2;
    std::istringstream iss("3.14-2.71j 0+2j");
    iss >> k1 >> k2;
    EXPECT_EQ(Komplex(3.14, -2.71), k1);
    EXPECT_EQ(Komplex(0, 2), k2);
} END
#endif

#if ELKESZULT >= 8
/// konjugált műveletének tesztje
TEST(KomplexTest8, Conj) {
    EXPECT_EQ(Komplex( 3,-4), ~Komplex( 3, 4));
    EXPECT_EQ(Komplex( 3, 4), ~Komplex( 3,-4));
    EXPECT_EQ(Komplex(-3, 4), ~Komplex(-3,-4));
    EXPECT_EQ(Komplex(-3,-4), ~Komplex(-3, 4));
} END
#endif

#if ELKESZULT >= 9
/// szorzások tesztje
TEST(KomplexTest9, Mul) {
    const Komplex prod = Komplex(3.14,2.71) * Komplex(1,2);
    EXPECT_DOUBLE_EQ(-2.28, prod.getRe());
    EXPECT_DOUBLE_EQ(8.99, prod.getIm());
} END
TEST(KomplexTest9, AssignmentMul) {
    Komplex prod(3.14,2.71);
    prod *= Komplex(1,2);
    EXPECT_DOUBLE_EQ(-2.28, prod.getRe());
    EXPECT_DOUBLE_EQ(8.99, prod.getIm());
} END
#endif

/// Itt a vége
TEST(KomplexTest10, MindenFeladatKesz) {
    int _ELKESZULT = ELKESZULT; /// csak a kiírás szépségéért
    EXPECT_EQ(9, _ELKESZULT) << "Addig nincs teljes siker, "
        "amig nem keszult el minden" << std::endl;

} END

  return 0;
}
