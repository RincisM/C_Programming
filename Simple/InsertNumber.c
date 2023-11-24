#include <stdio.h>
 
int main()
{
    int a[100];
    int i, x, pos, n;
    printf("Enter the size of the Array: ");
    scanf("%d", &n);
    
    printf("Enter the %d elements in the Array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
 
    printf("Enter the Element to be inserted: ");
    scanf("%d", &x);
 
    printf("Enter the Position to place the element: ");
    scanf("%d", &pos);
    n++;
    for (i = n-1; i >= pos; i--)
        a[i] = a[i - 1];
    a[pos - 1] = x;
 
    printf("\nUpdated Array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}