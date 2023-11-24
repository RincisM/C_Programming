#include <stdio.h>
int main() {
    int i, j, n, a[100];
    int temp=0;
    printf("Enter the Size of the Array: ");
    scanf("%d", &n);
    printf("Enter %d elements in the array: ", n);
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(a[i]>a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("The Second Largest Element in the Array is: %d", a[n-2]);
    return 0;
}