#include <stdio.h>
int main() {
    int a[100], i, n, j, flag = 0;
    printf("\nEnter the size of the array:");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            if (a[i] == a[j] && i != j) {
                flag = 1;
                printf("\nDuplicate number %d is found at index %d and %d", a[i], i, j);
            }
        }
    }
    if (flag == 0) {
        printf("\nNo Duplicate");
    }
    return 0;
}