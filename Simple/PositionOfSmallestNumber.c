#include <stdio.h>
int main() {
    int a[100], size, i, smallest, position;
    printf(" Enter the size of an Array: ");
    scanf("%d ", &size);
    printf("\n Enter %d elements in the Array: \n", size);
    for (i = 0; i <= size; i++) {
        scanf("%d ", &a[i]);
    }
    smallest = a[0];
    for (i = 1; i <= size; i++) {
        if (smallest > a[i]) {
            smallest = a[i];
            position = i;
        }
    }
    printf("\n Smallest element in the Array: %d ", smallest);
    printf("\n Index position of the samllest element: %d ", position);
    return 0;
}