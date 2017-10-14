#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  long long int num = 0;      // Number out
  int from_base = 0;          // Base conversion
  int to_base = 0;
  char dig=0;                 // read-in digit
  char S[36]={0};             // Digit base
  char out[100];              // output buffer
  // Init digit base
  for (int i=0; i<=9; i++){
    S[i] = '0' + i;
  }
  int b=0;
  int j=0;
  for ( b='A', j=10; b<'Z'; b++,j++) {
    S[j] = b;
  }
  // Done init digit base
  //
  // Read in the numbers
  from_base = (int) atoi(argv[1]);
  to_base = (int) atoi(argv[2]);
  
  int i = 3;              // First number must be 3rd arg
  while (i < argc) {
    num = 0;
    for (int n=0; n<(int) strlen(argv[i]); n++){
      num *= from_base;
      dig = toupper(argv[i][n]);
      for (int k=0; k<32; k++){
        if (S[k] == dig){
          num += k;
          // printf("[DEBUG] \"%s\" [%d]:%c -> num:%lld*%d\n",
          // argv[i],
          //n,
          //argv[i][n],
          //num,
          //base);
        }
      }
      
    }
    int n=0;        // output number (char)
    int p = 0;      // pointer to output
    while (num != 0){
      n = num%to_base;
      num = num/to_base;
      
      out[p] = S[n];
      p++;
    }
    printf("b\'%2d:%s <==> b\'%2d:", from_base, argv[i], to_base);
    while (p>=0) {
      if (to_base==2) {
        if ((p+1)%4==0)
          printf("\'");
      }
      else if((p+1)%3==0)
        printf("\'");
      printf("%c", out[p--]);
    }
    printf("\n");
    i++;
  }
  return 0;
}
