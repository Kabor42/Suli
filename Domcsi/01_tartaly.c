#include <stdio.h>

int main() {
    // h -- height
    // d -- diameter
    double h = 0, d = 0;
    double anne = 0;
    double pi = 3.14;
    printf("Ez a program kiszamolja a tartaly lefestendo feluletet!\n");
    
    printf ("Kerem adja meg a tartaly magassagat: ");
    scanf ("%lf", &h);

    printf ("Kerem adja meg a tartaly atmerojet: ");
    scanf ("%lf", &d);

    anne = 2*pi*d*((d/2) + h)/2;

    printf ("-----------------------------------\n");
    printf ("A henger felulete: %.2lf m^2\n", anne);
    printf ("Ennek lefestesehez %d doboz festek szukseges.\n", (int)anne/2+1);

    return 0;
}
