#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

/*
 * Elmozdulás egy adott ponttól
 *
 * Készíts függvényt, mely egy pont x és y koordinátáival tér vissza.
 * A függvény paraméterként kapja egy pont x és y koordinátáját (egy pontot),
 * valamint egy szöget és egy távolságértéket.
 * Számítsd ki a visszatérési értékként szereplő pont x és y koordinátáit,
 * hogy az a megadott ponttól meghatározott szögben és távolságban legyen.
 */


typedef struct Pont {
    double x,y;
} Pont;

Pont elm(Pont p, double a, double r) {
    Pont t;
    t.x = p.x + r*cos(PI*a/180.0);
    t.y = p.y + r*sin(PI*a/180.0);
    return t;
}

void print_point( Pont p) {
    printf("[%.2lf,%.2lf]", p.x, p.y);
}

int main() {

    Pont p;
    double r;
    int a;

    printf("Adja meg egy pont koordinatait [x,y]: ");
    scanf(" %lf,%lf", &p.x, &p.y);
    printf("Adja meg az elmozdulas nagysagat: ");
    scanf(" %lf", &r);
    printf("Adja meg az elmozdulas szoget: (fok)");
    scanf(" %d", &a);
    printf("-------------------------------------\n");

    printf("A megadott ponttol :");
    print_point(p);
    printf(" %d szogu es %g tavolsagu pont az: ", a, r);
    print_point(elm(p,a,r));
    printf("\n");
}
