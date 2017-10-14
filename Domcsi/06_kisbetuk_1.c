#include <stdio.h>
#include <ctype.h>

int numLower(char *str){
    int n=0;
    char *p = str;
    while (*p != '\0') {
        if (islower(*p++))
            n++;
    }
    return n;
}

int main() {
    char *szoveg = {"Hello world!"};
    printf("A \"%s\"-ben %d kisbetu van!\n", szoveg, numLower(szoveg));

    return 0;
}
