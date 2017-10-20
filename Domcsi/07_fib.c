#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long fib(unsigned long long n){
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    return fib(n-1)+fib(n-2);
}

int main(int argc, char* argv[]) {
    if (argc < 1){
        printf("Usage:\n"
                "./%s [n]\n"
                "where n-is the nth fibonacci number\n",
                argv[0]
                );
        return 0;
    }
    double t_start, t_stop, t_time;
    t_start = (double) clock();
    unsigned long long n = (unsigned long long) atoi(argv[1]);
    unsigned long long ret_val = 0;
    ret_val = fib(n);
    t_stop = (double) clock();
    t_time = (t_stop - t_start) / 1000;
    printf("%-3llu. fibonacci number is: %llu\n"
            "Calculated in %g miliseconds.\n",
            n, ret_val, t_time);

    return 0;
}
