#include <stdio.h>
int main()
{
    int a[100], i, n, x;
    printf("Enter the Number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements of array in Ascending Order : \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("\n Enter a number you want to delete :");
    scanf("%d", &x);

    for (i = 1; i < n; i++)
    {
        if (a[i] < x)
            a[i] = a[i];
        else
            a[i] = a[i + 1];
    }
    printf("\nArray after deleting a number:\n");
    for (i = 1; i < n; i++)
        printf("%d \t", a[i]);
    return 0;
}