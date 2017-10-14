#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
 * Írj függvényt, amelyik megmondja egy betűről, hogy magánhangzó-e!
 * Alakítsd át úgy a programot, hogy a megírt függvényt használod a main()-ben!
 *
 * Hogyan lehetne megoldani azt, hogy a nagybetűvel kezdődő szavakat is
 * helyesen kezelje a program?
 * Pl. az „Alma” szóra azt kell kiírnia, hogy „Avalmava”.
 * Ehhez fel kell tudnia ismerni a nagybetűvel írt magánhangzókat is.
 * Kiíráskor a v betű előtt az eredeti karaktert kell kiírni, utána pedig a kisbetűsítettet.
 * Használhatod a meglévő maganhangzo() függvényt is,
 * csak a beolvasott karaktert kisbetűsítve kell odaadnod neki.
 */

bool is_vovel( char ch);
void to_madar ( char ch);

int main() {
    char c;
    while (scanf(" %c", &c) != EOF ) {
        if (c == '\n') break;
        to_madar(c);
    }

    return 0;
}

bool is_vovel( char ch) {
    switch (ch){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

void to_madar ( char ch) {
    if (is_vovel(ch))
        printf("%cv%c", ch, tolower(ch));
    else
        printf("%c", ch);
}

