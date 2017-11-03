#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * @brief This function creates the dynamic version of the string
 *
 * If the string is empty, then it creates an empty string, not a NULL pointer.
 * If memory allocation fails, returns a NULL;
 *
 * @param *str string constant
 * @return pointer to dynamic string
 */

char *masol(char const *str){
    char *d = (char*) malloc(sizeof(str) + 1);
    if (d == NULL) return NULL;
    strcpy(d, str);
    return d;
}

char *hozzafuz(char *a, char const *b){
	char *tmp = (char*) realloc( a, sizeof(char) * (strlen(a)+strlen(b)+1));
	strcat( tmp, b);
	return tmp;
}

int main() {
    char *str;
    str = masol("alma ");
    printf(
            "Szoveg foglalasa dinamikusan:\n"
            "\"%s\" -> %p\n",
            str,
            str
            );
    str = hozzafuz( str, "fa");
    printf(
            "Szoveg foglalasa dinamikusan:\n"
            "\"%s\" -> %p\n",
            str,
            str
            );
    free(str);
    return 0;
}
