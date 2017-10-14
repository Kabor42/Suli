#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

long long int reset() {
    return 1;
}

long long add( long long n) {
    return n+1;
    }

long long rev(long long n) {
    return -n;
}

long long mult( long long n) {
    return 2*n;
}

int main() {
    long long int a = 1;
    const int end_ch = 9;
    int sel = 0;
    do {
    printf(
            "%2d\tAlapertek viszallitasa (a=1)\n"
            "%2d\tHozzaad 1-et\n"
            "%2d\tMegforditja az elojelet\n"
            "%2d\tSzorozza 2-vel\n"
            "%2d\tKilepes\n"
            ,0,1,2,3,9
            );
    scanf(" %d", &sel);
    switch (sel) {
        case 0:
            a = reset();
            break;
        case 1:
            a = add(a);
            break;
        case 2:
            a = rev(a);
            break;
        case 3:
            a = mult(a);
            break;
        case 9:
            break;
        default:
            printf("Please chose:\n");
    }
    } while (sel != end_ch);
    printf("\n\nYout get from [1] -- %lld\n", a);
}
