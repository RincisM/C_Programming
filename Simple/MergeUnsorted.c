#include <stdio.h>
int main() {
    int a[100], b[100], c[200]; 
    int i, n, m, o;
    printf("Enter the Size of 1st array: ");
    scanf("%d", &n);
    printf("Enter the Elements of the 1st Array: \n");
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the Size of 2nd array: ");
    scanf("%d", &m);
    printf("Enter the Elements of the 2nd Array: \n");
    for(i=0; i<m; i++) {
        scanf("%d", &b[i]);
    }
    o=n+m;
    for(i=0; i<o; i++) {
        c[i] = a[i];
    }
    for(i=0; i<o; i++) {
        c[i+n] = b[i];
    }
    printf("Merged Array is: \n");
    for(i=0; i<o; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}