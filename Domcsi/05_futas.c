#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Datum {
    int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir (Datum v);
bool comp_d (Datum d1, Datum d2);
void versenyzo_kiir( Versenyzo v);
//----------------------------------------------------------------------------/
int main() {
    Versenyzo versenyzok[5] = {
        { "Am Erika",       {1984, 5, 6},   1},
        { "Break Elek",     {1982, 9, 30},  3},
        { "Dil Emma",       {1988, 8, 25},  2},
        { "Kasza Blanka",   {1979, 6, 10},  5},
        { "Reset Elek",     {1992, 4, 5},   4},
    };
    /* 0-s versenyző neve - printf %s */
    printf("[1] --> %s\n", versenyzok[0].nev);

    /* 2-es versenyző helyezése */
    printf("[2] --> %d\n", versenyzok[2].helyezes);

    /* 4-es versenyző születési dátumát a megadott függvénnyel */
    printf("[3] --> ");datum_kiir(versenyzok[4].szuletes);

    /* 1-es versenyző nevének kezdőbetűjét (ne feledd, a sztring karaktertömb) */
    printf("[4] --> %c\n", versenyzok[1].nev[0]);

    /* az 1-es versenyző dobogós-e? igen/nem, akár ?: operátorral, de egy printf-fel */
    printf("[5] --> %s\n", (versenyzok[1].helyezes >= 3)?"igen":"nem");

    /* az 4-es versenyző gyorsabb-e, mint a 3-as versenyző? */
    printf("[6] --> %s\n", (versenyzok[3].helyezes > versenyzok[4].helyezes)?"igen":"nem");

    /* az 1-es versenyző ugyanabban az évben született-e, mint a 2-es? */
    printf("[7] --> %s\n", (comp_d(versenyzok[1].szuletes, versenyzok[2].szuletes))?"igen":"nem");

    /* egészítsd ki a versenyzo_kiir() függvényt,
     * aztán írd ki az 1-es versenyző osszes adatát */
    printf("[8] --> \n");
    versenyzo_kiir(versenyzok[1]);

    /* végül listázd ki az összes versenyzőt sorszámozva, összes adatukkal. */
    printf("[9] --> \n");
    for (int i=0; i<5; i++)
        versenyzo_kiir(versenyzok[i]);
    return 0;
}
//----------------------------------------------------------------------------/

void datum_kiir (Datum d) {
    printf("%d.%d.%d.\n", d.ev, d.ho, d.nap);
}

bool comp_d (Datum d1, Datum d2){
    if (d1.ev != d2.ev)
        return false;
    if (d1.ho != d2.ho)
        return false;
    if (d1.nap != d2.nap)
        return false;
    return true;
}

void versenyzo_kiir (Versenyzo v) {
    printf(
            "%s\t"
            "%d.%d.%d.\t"
            "[%d]\n",
            v.nev,
            v.szuletes.ev,
            v.szuletes.ho,
            v.szuletes.nap,
            v.helyezes
            );
}
