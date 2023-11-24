#include <stdio.h>
int smallest(int [], int);
int main()
{
    int a[100], small, i, size;
    printf("Enter Array Size: ");
    scanf("%d", &size);
    printf("Enter %d Array Elements: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &a[i]);
    small=smallest(a, size);
    printf("\nSmallest Number = %d", small);
    return 0;
}
int smallest(int a[], int n)
{
    int i=0, small;
    small=a[i];
    while(i<n)
    {
        if(small>a[i])
            small = a[i];
        i++;
    }
    return small;
}