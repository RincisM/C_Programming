#include <stdio.h>
int smallest(int a[], int size) {
    int i, j;
    j = a[0];
    for(i=1; i<size; i++) {
        if(j>a[i]) {
            j = a[i];
        }
    }
    return j;
}
void main() {
    int n, i, a[50], c[50], b[50], j, k, m ,o, small, pos=0;
    printf("Enter the Size of the Array: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        a[i] = i+1;
    }
    small = smallest(a, n);
    printf("The Smallest Number is : %d\n", small);
    for(i=n-1; i>=0; i--) {
        printf("%d ", a[i]);
    } 
    
}