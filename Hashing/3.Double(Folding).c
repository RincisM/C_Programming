#include <stdio.h>
#include <stdlib.h>

void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("\t%d", a[i]);
}

void insert(int a[], int size, int hfn, int hgn)
{
    int element, pos, n = 0, j = 0;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    pos = (element%10 + (int)(element /10))%hfn;
    while (a[pos] != -1)
    {
        if (a[pos] == 0)
            break;
        printf("Collision Occured at Index %d\n", pos);
        pos = ((element%hfn) + j*(1+(element%hgn)));
        j++;
        n++;
        if (n == size)
            break;
    }
    if (n == size)
        printf("The Hash Table is Full");
    else
        a[pos] = element;
    display(a, size);
    
}

void main()
{
    int size, hfn, hgn, ch;
    printf("Enter the Size of the Hash Table: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the 1st hash function(enter 10 for mod 10): ");
    scanf("%d", &hfn);
    printf("Enter the 2nd hash function(enter 10 for mod 10): ");
    scanf("%d", &hgn);
    for (int i = 0; i < size; i++)
        a[i] = -1;
    while (1)
    {
        printf("\n1.Insert\n2.Exit");
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(a, size, hfn, hgn);
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Invalid Option");
            break;
        }
    }
}