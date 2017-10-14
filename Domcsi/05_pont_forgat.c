#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define PI  3.14159265359

/*
  Elforgatás egy pont körül

  Készíts függvényt, amely egy x és y koordinátával rendelkező pontot
  elforgat egy másik adott pont körül, adott szöggel!
  A függvény visszatérési értéke az elforgatott pont legyen.
  (A forgatáshoz való képletet megtalálod a függvénytáblában is.)
 */

typedef struct Pont{
  double x,y;
} Pont;

Pont rot(Pont p, Pont x, double a) {
  Pont t;
  double b, om;
  double R = sqrt(pow((p.x-x.x),2)+pow((p.y-x.y),2));
  b = acos((p.x-x.x)/R);
  a = PI*a/180.0;
  om = a + b;
  t.x = x.x + R*cos(om);
  t.y = x.y + R*sin(om);

  return t;
}

int main(int argc, char *argv[]) {
  Pont p, a, t;
  int alp;

  a.x = atof(argv[1]);
  a.y = atof(argv[2]);
  p.x = atof(argv[3]);
  p.y = atof(argv[4]);
  alp = atoi(argv[5]);
  
  t = rot( p, a, alp);
  printf("Az elforgatott pont: [%lf,%lf]\n", t.x, t.y);
  return 0;
}
