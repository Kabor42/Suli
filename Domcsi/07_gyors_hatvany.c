#include <stdio.h>
#include <stdlib.h>

unsigned long long hatv( unsigned long long n, int k){
    if (k%2==0) {
        if ( k == 2) return n*n;
        return hatv(hatv( n, k/2), 2);
    }
    else
        return n*hatv( n, k-1);
}

int main(int argc, char* argv[]) {
    if (argc < 2){
        printf("Usage:\n"
                "./%s [x] [n]\n"
                "where x-is the base and n is the exponenet\n",
                argv[0]
                );
        return 0;
    }
    unsigned long long a = (unsigned long long) atoi(argv[1]);
    int n = (int) atoi(argv[2]);
    printf("%llu^%d = [%llu]\n", a, n, hatv(a,n));
    return 0;
}
