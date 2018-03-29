/**
 * \file resistor_test2.cpp
 *
 * Ohmikus ellenállást megvalósító osztály tesztelése
 * Laborfeladat
 */
#include <iostream>
#include "gtest_lite.h"
#include "resistor.h"


#define ARAM_FESZULTSEG


int main() {
  Resistor r;

  TEST(Resistor, HazibanAdottR) {
    double d = r.getR();	  	            // Háziban megadott érték
    EXPECT_EQ(21, d);
  } END

  Resistor r1(1000), r2(3000);

  TEST(Resistor, EgyPareteresKonsruktor) {
    double d = r1.getR();	  	            // 1000
    EXPECT_EQ(1000, d);
  } END

  Resistor r11 = r1;

  TEST(Resistor, Masolo) {
    double d = r11.getR();                 // 1000
    EXPECT_EQ(1000, d);
  } END

  TEST(Resistor, Osszeg) {
    double d = (r1 + r2).getR();           // 4000
    EXPECT_EQ(4000, d);
  } END

  TEST(Resistor, Szorzat) {
    double d = (2 * r1).getR();            // 2000
    EXPECT_EQ(2000, d);
  } END

  Resistor::setDef(20);
  Resistor rt[5];

  TEST(Resistor, SetDef) {
    double d = rt[3].getR();                // 20
    EXPECT_EQ(20, d);
  } END

  r1 = r2;

  TEST(Resistor, Ertekadas) {
    double d = r1.getR();	  	            // 3000
    EXPECT_EQ(3000, d);
  } END

  TEST(Resistor, Kievetel) {
    EXPECT_THROW(-1 * r1, const char*);
  } END

#ifdef ARAM_FESZULTSEG
  TEST(ResistorTest, getI) {				// getI
    const Resistor r0(2);
    EXPECT_DOUBLE_EQ(6.06, r0.getI(12.12));
  } END

  TEST(ResistorTest, getU) {				// getU
    const Resistor r0(12.12);
    EXPECT_DOUBLE_EQ(24.24, r0.getU(2));
  } END

  TEST(ResistorTest, EQ) {				    // operator==
    const Resistor r0(1345.6);
	Resistor r = r0;
    EXPECT_TRUE(r0 == r);
    const Resistor r1(13.6);
    EXPECT_FALSE(r0 == r1);
  } END

  TEST(ResistorTest, NE) {				    // operator!=
    const Resistor r0(1345.6);
	Resistor r = r0 + r0;
    EXPECT_TRUE(r0 != r);
    const Resistor r1(1345.6);
    EXPECT_FALSE(r0 != r1);
  } END

#endif // ARAM_FESZULTSEG
    return 0;
}
