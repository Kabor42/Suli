#include <iostream>
#include <stdexcept>


void rendez(double t[], int n) {
    if (n <= 1) return;
    double p = t[n/2];
    double b[n], c[n];
    int i, j = 0, k = 0;
    for (i=0; i < n; i++) {
        if (i == n/2) continue;
        if ( t[i] >= p) b[j++] = t[i];
        else            c[k++] = t[i];
    }
    rendez(b,j);
    rendez(c,k);
    for (i=0; i<j; i++) t[i] =b[i];
    t[j] = p;
    for (i= 0; i<k; i++) t[j+1+i] =c[i];
}

int main(int argc, char **argv)
{
        double arr[10] = { 10, 12, -4, 3, 101, 100, 102, 2, 3, 10 };
        int size = 10;

        for( int i =0; i < size; i++) {
                std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        rendez( arr, size);

        for( int i =0; i < size; i++) {
                std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        return 0;
}

