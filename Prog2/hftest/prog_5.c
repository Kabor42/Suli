#include <stdio.h>

char myid[]   = "Nagy Dominik,1MI,15,L4M <nd1531@hszk.bme.hu> M8CFQC\n";
char mytask[] = "Feladat = 5 English\n";

int main() 
{
	setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
	printf(myid); 
	printf(mytask);
	printf("Mail");
	return 0; 
}
