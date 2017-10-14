#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 0;
    printf("A primszamok 2-tol meddig?");
    scanf ("%d", &n);
    bool arr[n+1];
    for (int i=0; i<=n; i++)
        arr[i] = true;
    for (int i=2; i<=n; i++)
        if (arr[i]){
            int j=2;
            while (j*i <= n) {
                arr[j*i] = false;
                j++;
            }
            printf("%5d", i);
        }
    return 0;
}
