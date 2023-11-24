#include <stdio.h>
int main() {
    int i, n, a[100], sum=0, average;
    printf("Enter the No. of Elements: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ", n);
    for(i=0;i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("The Sum of the Array is: ");
    for(i=0; i<n; i++) {
        sum = sum + a[i];
    }
    printf("%d\n", sum);
    average = sum/n;
    printf("The Average of %d element is: %d", n, average);
    return 0;
}