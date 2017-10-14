#include <stdio.h>
#include <string.h>

void trim(char *be, char *ki){
    for (int i=0; i<64; i++)
        ki[i] = '\0';
    char *p = be;
    char *q = be + strlen(be) -1;
    while (p != q && *p == ' ') {
        p++;
    }
    while (q != p && *q == ' ') {
        q--;
    }
    if (q != p)
        q++;
    strncpy(ki,be+(p-be),q-p);
}

int main() {
    char *szoveg = {"    Hello world !   "};
    char cel[100];
    trim(szoveg, cel);
    printf(" \"%s\" --> \"%s\"\n", szoveg, cel);


    char *sample_strings[] =
    {
        "nothing to trim",
        "    trim the front",
        "trim the back     ",
        " trim one char front and back ",
        " trim one char front",
        "trim one char back ",
        "                   ",
        " ",
        "a",
        "",
        NULL
    };
    char test_buffer[64];
    int index;

    for( index = 0; sample_strings[index] != NULL; ++index )
    {
        strcpy( test_buffer, sample_strings[index] );
        trim(sample_strings[index], test_buffer);
        printf("[%s] -> [%s]\n", sample_strings[index],
                test_buffer);
    }

    return 0;
}
