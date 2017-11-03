#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *kihagy( int i1, int i2, char const *str){
    int a = (i1<0) ? 0: i1;
    int b = (i2 > strlen(str)) ? strlen(str) : i2;

    int j=0;
    char *tmp = (char*) malloc(sizeof(char) * (strlen(str)-(b-a)+1));
    for (int i=0;i<strlen(str);i++){
        if (i<a || i>=b)
            tmp[j++] = str[i];
    }
    tmp[j] = '\0';

    return tmp;
}

int main(){
    char str[] = "almafa";
    char *prt = kihagy( 2, 4, str);
    for(int i=0;i<strlen(str);i++)
        printf("%2d", i);
    printf("\n");
    for(int i=0;i<strlen(str);i++)
        printf("%2c", str[i]);
    printf("\n");
    printf(
            "Eredeti: \"%s\"\n"
            "Kicsi: \"%s\"\n",
            str,
            prt
            );
    free(prt);
    return 0;
}
