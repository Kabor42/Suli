#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    long long int num = 0;    // Number out
    int base=0;             // Base conversion
    char dig=0;             // read-in digit
    char S[36]={0};         // Digit base
    // Init digit base
    for (int i=0; i<=9; i++){
        S[i] = '0' + i;
    }
    int b=0;
    int j=0;
    for ( b='A', j=10; b<'Z'; b++,j++) {
        S[j] = b;
    } 
    // Done init digit base
    //
    // Read in the numbers 
    base = (int) atoi(argv[1]);

    int i = 2;              // First number must be 3rd arg
    while (i < argc) {
        num = 0;
        for (int n=0; n<(int) strlen(argv[i]); n++){
            num *= base;
            dig = toupper(argv[i][n]);
            for (int k=0; k<32; k++){
                if (S[k] == dig){
                    num += k;
                    // printf("[DEBUG] \"%s\" [%d]:%c -> num:%lld*%d\n",
                    // argv[i],
                    //n,
                    //argv[i][n],
                    //num,
                    //base);
                }
            }

        }
        printf("%s --> %lld\n", argv[i], num);
        i++;
    }
    return 0;
}
