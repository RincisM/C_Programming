#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display(int a[], int size) {
    for (int i = 0; i < size; i++)
        printf("\t%d", a[i]);
}

void insert(int a[], int size, int hfn) {
    int element, pos, n = 0, j = 0;
    float s, g;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    float const A = (sqrt(5) - 1)/2;
    s = element*A;
    g = s - (int)s;
    pos = ((int)(size * g));
    while (a[pos] != -1) {
        if (a[pos] == 0)
            break;
        printf("Collision Occured at Index %d\n", pos);
        pos = (pos + (2 * j * j)) % hfn;
        j++;
        n++;
        if (n == size)
            break;
    }
    if (n == size)
        printf("Cannot Insert the Element");
    else
        a[pos] = element;
    display(a, size);
}

void main()
{
    int size, hfn, ch;
    printf("Enter the Size of the Hash Table: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the hash function(enter 10 for mod 10): ");
    scanf("%d", &hfn);
    for (int i = 0; i < size; i++)
        a[i] = -1;
    while (1) {
        printf("\n1.Insert\n2.Exit\nEnter the Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(a, size, hfn);
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