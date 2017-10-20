#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long to_base(long long n, int base){
    if (n == 0)
        return n;
    return (n%base)+to_base(n/base,base)*10;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:\n"
                "\t ./%s <to_base> <num>\n",
                argv[0]
              );
        return -1;
    }
    long long int n = (long long int) atoi(argv[2]);
    int base = (int) atoi(argv[1]);
    printf("A [%lld]-szam [%d] szamrendszerbe [%lld]\n", n, base, to_base(n,base));

}
