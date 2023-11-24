#include <stdio.h>
int main() {
    int a[100];
    int i, j;
    int sum;
    printf("Enter the Sum: ");
    scanf("%d", &sum);
    for(i=1; i<=100; i++) {
        a[i-1] = i;
    }
    for(i=0; i<100; i++) {
        for(j=i; j<100; j++) {
            if(a[i] + a[j] == sum) {
                printf("(%d, %d), ", a[i], a[j]);
            }
        }
    }
    return 0;
}