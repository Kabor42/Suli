#include <stdio.h>

void fugg(char *str) {
    for (char *p = str; *p; p++)
        printf("%c\n", *p);
}

int main() {
    char nev[100];
    scanf("%s", nev);
    fugg(nev);

    return 0;
}
