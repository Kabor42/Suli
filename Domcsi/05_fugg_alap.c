#include <stdio.h>
#include <math.h>

/*
 * Írj függvényeket, amelyek valós számot vesznek át, és visszatérnek az:
 *
 *     kob() – harmadik hatványával,
 *         abszolut() – abszolút értékével (van fabs() függvény, de most ne használd)! 
 *
 *         Írj programot, amelyik a = −1-től +1-ig, 
 *         tizedenként lépve, kiírja egymás mellé a, a3, |a| és sin(a) értékét, 
 *         mindig négy tizedesjegy pontossággal!
 */

double kob( double n);
double abszolut( double n);

int main() {
  for (int i=-10; i<=10; i++) {
    double n=i/10.0;
    printf(
        "%-2.4lf\t"
        "%.4lf\t"
        "%.4lf\t"
        "%.4lf\n",
        n, kob(n),
        abszolut(n), sin(n)
           );
  }
  return 0;
}

double kob( double n) {
  return n*n*n;
}

double abszolut (double n) {
  return (n >= 0)? n : -n;
}
