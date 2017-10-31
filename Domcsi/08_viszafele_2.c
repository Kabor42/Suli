#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	int n = 0;
	bool vege = false;
	int *szamok = (int*) malloc(sizeof(int));
	int d;

	do{ 
		printf("Uj szam: (-1 --> vege) \t");
		scanf("%d", &d);
		if ( d == -1)
			vege = true;
		else {
			n++;
			szamok = (int*) realloc(szamok, sizeof(int) * n);
			szamok[n-1] = d;
		}
	} while (!vege);

	printf("---------------------------------------\n");

	for (int i=n-1; i>=0; i--){
	       printf("%d ", szamok[i]);
	}
	printf("\n");

	free(szamok);
	
	return 0;
}	
