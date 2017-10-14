#include <stdio.h>

int keres(int *tomb, int meret, int elem) {
    int *p = tomb;
    while (p < tomb+meret){
        if (*p == elem)
            return p-tomb;
        p++;
    }
    return -1;
}

int main() {
    int n;
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 20, 25};
    printf("Adja meg a keresett szamot: ");
    scanf(" %d", &n);
    printf("A keresett szam:");
    if (keres( arr, 15, n) >= 0)
        printf(" %d. elem\n", keres( arr, 15, n));
    else
        printf(" nincs ilyen elem\n");

}
