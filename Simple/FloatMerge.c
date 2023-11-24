#include <stdio.h>
int main() {
    float a[100], b[100], c[200]; 
    int i, j, n, m, o, temp=0;
    printf("Enter the Size of 1st array: ");
    scanf("%d", &n);
    printf("Enter the Elements of the 1st Array: \n");
    for(i=0; i<n; i++) {
        scanf("%f", &a[i]);
    }
    printf("Enter the Size of 2nd array: ");
    scanf("%d", &m);
    printf("Enter the Elements of the 2nd Array: \n");
    for(i=0; i<m; i++) {
        scanf("%f", &b[i]);
    }
    o=n+m;
    for(i=0; i<o; i++) {
        c[i] = a[i];
    }
    for(i=0; i<o; i++) {
        c[i+n] = b[i];
    }
    printf("Merged Array is: \n");
    for(i=o-1; i>=0; i--) {
        printf("%.2f ", c[i]);
    }
    return 0;
}