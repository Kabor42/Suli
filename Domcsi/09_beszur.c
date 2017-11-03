#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *beszur( char const *src, int n, char const *str){
    char *tmp = (char*) malloc(sizeof(char) * (strlen(str) + strlen(src) + 1));
    int j = 0;
    for(int i=0; i<strlen(src); i++){
        if( i == n)
            for(int k=0; k<strlen(str);k++)
                tmp[j++] = str[k];
        tmp[j++] = src[i];
    }
    tmp[j] = '\0';
    return tmp;
}

int main(){
    char str[] = "Hello!";
    char what[] = ", world";
    char *res = beszur( str, 5, what);
    printf("beszur( \"%s\", %d, \"%s\")\n"
            "\"%s\"\n",
            str,
            5,
            what,
            res
            );
    free(res);
    return 0;
}
