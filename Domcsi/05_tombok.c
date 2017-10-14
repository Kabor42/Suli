#include <stdio.h>

int main() {
  double arr[] = {2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8};
  int neg = 0;
  for (int i=0; i<10; i++)
    if (arr[i] < 0)
      neg++;

  int p = 0;
  int idx[neg];

  for (int i=0; i<10; i++)
    if (arr[i] < 0)
      idx[p++] = i;

  printf("Osszesen 10 szam van:\n");
  for (int i=0; i<10; i++)
    printf("[%d]=%g ", i, arr[i]);
  printf("\n\n");
  printf("Ebbol %d szam negativ:\n", p);
  for (int i=0; i<p; i++)
    printf("[%d]=%g ", idx[i], arr[idx[i]]);
  printf("\n");

  return 0;
}
