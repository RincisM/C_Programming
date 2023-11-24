#include <stdio.h>
 
int main()
{
    float a[100], x;
    int i, pos, n;
    printf("Enter the size of the Array: ");
    scanf("%d", &n);
    
    printf("Enter the %d elements in the Array: ", n);
    for (i = 0; i < n; i++)
        scanf("%f", &a[i]);
 
    printf("Enter the Element to be inserted: ");
    scanf("%f", &x);
 
    printf("Enter the Position to place the element: ");
    scanf("%d", &pos);
    n++;
    for (i = n-1; i >= pos; i--)
        a[i] = a[i - 1];
    a[pos - 1] = x;
 
    printf("\nUpdated Array: \n");
    for (i = 0; i < n; i++)
        printf("%.2f ", a[i]);
    return 0;
}