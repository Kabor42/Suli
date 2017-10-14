#include<stdio.h>
#include <math.h>

int main() {
    int ax, ay, bx, by;
    double length;

    printf("Adja meg az \"A\" pont koordinatait!\n [ax ay]: ");
    scanf("%d %d", &ax, &ay);
    printf("Adja meg az \"B\" pont koordinatait!\n [bx by]: ");
    scanf("%d %d", &bx, &by);

    length = sqrt(pow(ax-bx,2)+pow(ay-by,2));

    printf("A szakasz hossza: %.5lf\n", length);
    
    return 0;
}
