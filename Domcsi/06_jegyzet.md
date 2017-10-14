% Pointerek és sztringek
% Nagy Dominik
% 2017.10.11

# Pelda program

Keresés és a hely megjellése:

```c
int hol_van(double tomb[], int meret, double keresett){
    int inx;
    for (idx=0;idx<meret,++idx)
        if(tomb[idx] = keresett)
            return idx;
    return -1;
}

int main(void) {
    double samok[5] = {};

    int idx = hol_van(szamok, 5, -6.9);
    if (idx != -1)
        printf("%d. elem, erteke %f", idx, szamok[idx]);
    else
        printf("Nincs benne ilyen");
    return 0;
}
```

Itt látjuk, hogy a tömb elemét csak 2 dologgal tudjuk előhívni, ami a tömb neve és a tömb indexe.
Jó lenne ha ezt 1 elemmel tudnánk kezelni, ez lesz a pointer.

Memóriacímet pointernek adni így tudunk: `double *p = &szamok[3];`

# Pointerek

Pointer dereferálása:
: `*p`
: Pointer memóriájának értékének a viszaadása.
: A pointer értékével tudunk így dolgoni.

```c
#include <stdio.h>

int main(void){
    double x=5.6;
    double u = 10.9;
    double *p;

    p = &x;
    printf("p = %p \n", p);
    printf("*p = %g \n", *p);
    printf("\n");

    p = &y;
    printf("p = %p \n", p);
    printf("*p = %g \n", *p);
    printf("\n");

    return 0;
}
```

# Cím szerinti paraméteradás

```c
void csere(int a, int b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void csere_p( int *pa, int *pb) {
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
int main(void){
    int x=3, y=4;
    csere( x, y);
    printf("%d,%d\n", x, y);
    csere_p( &x, &y);
    printf("%d,%d\n", x, y);
}
```

Ez a program ténylegesen kicseréli a 2 memóriacím közti értéket.
A sima csere függvény csak az értékét cseréli fel a paramétereknek,
anélkül hogy őket magukat megváltoztatnánk.

# Cím aritmetika

   [0][1][2][3][4]
    ^        ^  ^
    |       /    \
    p1     p2   &tomb[4]

    int tomb[5], *p1, *p2, tav;
    p1 = &tomb[0];
    p1 = tomb; // ekvivalens

    p2 = &tomb[4] - 1; // [4-1] elem cime
    tav = p2-p1


    double t[100];
    double *p;

    // p=t+0 $\rightarrow$ t+99, t+100 nem
    for(p=t; p != t+100; ++p)
        *p = 0.0

> Pointeren mindig indexet hasznaljunk: `p[idx]`, nem `*(p+2)`


# Tömböt átvevő függvények

```c
void kiir(double *tomb, int meret) {
    int i;
    for(i=0;i!=meret;++i)
        printf("%g ", tomb[i]);
    printf("\n");
}

void beolvas(double tomb[], int meret);

// Hivas
double szamok[10];
beolvas(szamok, 10);
kiir(szamok,10);
```

# Keresés és NULL pointerek

```c
double *hol_van(double *tomb, int meret, double keresett) {
    for (int idx=0; idx<meret;++idx)
        if(tomb[idx]==keresett)
            return &tomb[idx];
    return NULL
}

int main(void){
    double szamok[5] = {};

    double *ptr = hol_van(szamok, 5, -6.9);
    if (ptr != NULL)
        printf("%p helyen, erteke: %f\n", ptr, *ptr);
    else
        printf("Nincs benne ilyen\n");
    return 0;
}
```

# Sztringek

String
: A C-be nullával lezárt karaktertömbök ('\0')
: `[h][e][l][l][o][\0]`

Sztring inicializálása:

    char szoveg1[50] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char szoveg2[50] = "hello";


