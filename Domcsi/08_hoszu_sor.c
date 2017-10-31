#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 10

int main() {
	char ch;
	int cntr=0, size=BUFF;
	char *str = (char*) malloc(sizeof(char) * size);

	while ( (ch = getchar()) != EOF){
		if (cntr < size){
			str[cntr++] = ch;
		} else {
			size = cntr + BUFF;
			str = (char*) realloc( str, sizeof(char) * size);
		}
	}
	str[cntr] = '\0';

	printf("---------------------------\n");
	puts(str);

	free(str);

	return 0;
}
