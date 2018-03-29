// Copyright 2018 <kabor>

/**
 * \file swap.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 */

#include "./swap.h"

#error "itt valósitsa meg a függvényeket"

void swap(bool& a, bool& b) {
  bool tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void swap(int&a, int&b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swap(char& a, char& b) {
  char tmp = a;
  a = b;
  b = tmp;
}

void swap(double& a, double& b) {
  double tmp = a;
  a = b;
  b = tmp;
}

void swap(const char*& a, const char*& b) {
  const char *tmp;
  tmp = a;
  a = b;
  b = tmp;
}

