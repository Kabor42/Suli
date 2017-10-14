#include <stdio.h>
#include <math.h>

void t_t( double *a, double *T, double *V){
    *V = pow(3,*a);
    *T = 6*pow(2,*a);
}

int main() {

    double x = 2.7;
    double T, V;
    t_t ( &x, &T, &V);
        printf ("A %g oldalu kocka terfogata %g felulete %g\n", x, V, T);

    return 0;
}
