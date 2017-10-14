#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double x1, x2, d;

    printf("Add meg a masodfoku egyenletet a kovetkezo alakban:\nax^2+bx+c=0:  ");
    scanf("%lf %lf %lf", &a, &b, &c);

    d = b*b - 4*a*c;

    printf("--| %.2lfx^2+%.2lfx+%.2lf=0 |--\n", a, b, c);
    
    if (d > 0) {
        x1 = ((-b) + sqrt(d))/(2*a);
        x2 = ((-b) - sqrt(d))/(2*a);
        printf("Az egyenlet megoldasai:\n x1 = %5.2lf\n x2 = %5.2lf\n", x1, x2);
    } else if (d == 0) {
        x1 = (-b)/(2*a);
        printf("Az egyenlet megoldasa: %lf\n", x1);
    } else {
        printf("A egyenletnek nincs valos megoldasa!\n");
    } 

    return 0;
}
