#include <stdio.h>
int main() {
    int i, n, a[100];
    printf("\nEnter the Size of Array: ");
    scanf("%d", &n);
    printf("Enter the Elements of the Array: ");
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("\nThe Elements in the Array are: \n");
    for(i=0; i<n; i++) {
        printf("%d\t", a[i]);
    }
    return 0;
}