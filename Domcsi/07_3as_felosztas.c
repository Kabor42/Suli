#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tag(long long n) {
    if (n == 0)
        return;
    else
        tag(n/1000);
    printf("%03lld ", n%1000);
}

int main(int argc, char *argv[]) {
    if (argc < 1) {
        printf("Usage:\n"
                "\t ./%s <num>\n",
                argv[0]
              );
        return -1;
    }
    long long int n = (long long int) atoi(argv[1]);
    printf("[%lld] --> ", n);tag(n);printf("\n");

    return 0;
}
