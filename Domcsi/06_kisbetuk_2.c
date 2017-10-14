#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *numLower(char *str){
    char *p = (char *)malloc((strlen(str)+1)*sizeof(char));
    p = strcpy(p, str);

    while (*p != '\0') {
        if (isupper((unsigned char) *p))
            *p = tolower((unsigned char) *p);
        p++;
    }
    return p;
}

int main() {
    char *szoveg = {"Hello world!"};
    printf("[%s]-->", szoveg);
    printf("[%s]\n", numLower(szoveg));

    return 0;
}
