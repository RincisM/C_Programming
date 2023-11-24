#include <stdio.h>
int main() {
    int a[100];
    int n, i, temp=0;
    printf("Enter the size of the Array: ");
    scanf("%d", &n);
    printf("Enter the Elements: ");
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    temp = a[n-2];
    a[n-2] = a[1];
    a[1] = temp;
    printf("The Interchanged Array is: ");
    for(i=0; i< n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}