#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

# define LINES 2785

/**
  Problem 4 for Nagy Dominik (M8CFQC):
  Write a C program or shell script that prints to the standard output
  a text of 193 lines in which there are exactly 4 different lines that
  match the following regular expression:

  ^[^#]_?(0)*[0-9]*W6.+[A-Z]*.*qqriq(A|b)

*/

void strByRegex(const char* charset) {
    char ch;
    int key, rnd;
    int ch_len = strlen(charset);
    /** ^[^#] */
    do {
        key = rand() % ch_len;
        ch = charset[key];
    } while( ch == '#');
    putchar(ch);

    /** _? */
    rnd = rand() % 2;
    if (rnd)
        putchar('_');

    /** (0)* */
    rnd = rand() % 100;
    for (int i=0; i<rnd; i++)
        putchar('0');

    /** [0-9]* */
    rnd = rand() % 100;
    for (int i=0; i<rnd; i++){
        key = 52 + (rand() % 10);
        ch = charset[key];
        putchar(ch);
    }

    /** W6 */
    printf("%s", "W6");
    /** .+ */
    rnd = rand() % 100 + 1 ;
    for(int i=0; i<rnd; i++){
        key = rand() % ch_len;
        ch = charset[key];
        putchar(ch);
    }

    /** [A-Z]* */
    rnd = rand() % 100;
    for (int i=0; i<rnd; i++){
        key = 26 + (rand() % 26);
        ch = charset[key];
        putchar(ch);
    }

    /** .* */
    rnd = rand() % 100;
    for (int i=0; i<rnd;i++){
        key = rand() % ch_len;
        ch = charset[key];
        putchar(ch);
    }

    /** qqriq */
    printf("%s", "qqriq");

    /** (A|b) */
    rnd = rand() % 2;
    putchar(rnd ? 'A':'b');

    putchar('\n');
}

void rndStr(size_t length, const char* charset) {
    for (int i=0; i<length;i++){
        int key = rand() % (int)(strlen(charset) - 1);
        putchar(charset[key]);
    }
    putchar('\n');
}

int main(int argc, char *argv[]) {
    const char charset[]=
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    srand(time(NULL));

    /** Neccessary for hftest */
    char myid[]   = "Nagy Dominik,1MI,15,L4M <nd1531@hszk.bme.hu> M8CFQC\n";
    char mytask[] = "Feladat = 4 English\n";
    setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
    printf(myid);
    printf(mytask);
    /** --- */

    int specials[4] = { 10, 50, 100, 150};
    int cntr = 0;

    for (int i = 0; i<LINES; i++){
        if ( i == specials[cntr]) {
            cntr++;
            strByRegex(charset);
        }
        else
            rndStr( rand() % 100, charset);
    }

    return 0;
}
