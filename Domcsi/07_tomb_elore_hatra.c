#include <stdio.h>
#include <stdlib.h>

void i_elore(int *arr, int size){
    int *p = arr;
    while (p < arr+size) {
        printf("%d ", *p++);
    }
}

void i_hatra(int *arr, int size) {
    int *p = arr+size-1;
    while (p >= arr) {
        printf("%d ", *p--);
    }
}

void r_elore(int *arr, int size) {
   if (size <= 0)
       return;
   printf("%d ", *arr);
   r_elore(arr+1,size-1);
}

void r_hatra(int *arr, int size) {
    if (size <= 0)
        return;
    printf("%d ", *(arr+size-1));
    r_hatra(arr, size-1);
}

int main() {
    int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //int B[5] = { 10, 20, 30, 40, 50};
    printf("\n#########################\n");
    i_elore( A, 10);
    printf("\n#########################\n");
    i_hatra( A, 10);
    printf("\n#########################\n");
    r_elore( A, 10);
    printf("\n#########################\n");
    r_hatra( A, 10);
    printf("\n#########################\n");

    return 0;
}
