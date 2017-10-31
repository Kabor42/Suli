#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Hany darab szamot akar beirni? ");
	scanf (" %d", &n);

	int *szamok;
	szamok = (int*) malloc(sizeof(int) * n);
	for(int i=0;i<n;i++){
		printf("Adja meg az %2d. szamot: ", i+1);
		scanf(" %d", &szamok[i]);
	}

	printf("---------------------------------------\n");

	for (int i=n-1; i>=0; i--){
	       printf("%d ", szamok[i]);
	}
	printf("\n");

	free(szamok);
	
	return 0;
}	
