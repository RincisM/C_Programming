#include <stdio.h>
#include <stdlib.h>

#define gap 1
int heap[50];
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int n, int i)
{
    int smallest = i;
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;

    if (left < n && heap[left] < heap[i])
    {
        smallest = left;
    }
    if (right < n && heap[right] < heap[i])
    {
        smallest = right;
    }
    if (i != smallest)
    {
        printf("The Given Array is not a Min-Heap tree\n");
        exit(0);
    }
}

int insert(int n)
{
    int i, node;
    printf("\nEnter the value:");
    scanf("%d", &node);
    heap[n] = node;
    n++;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(n, i);
    }
    return n;
}
void display(int n, int i, int space)
{
    int left, right, j;
    if (i < n)
    {
        left = (i * 2) + 1;
        right = (i * 2) + 2;
        space = space + gap;
        display(n, right, space);
        printf("\n");
        for (j = gap; j < space; j++)
            printf("\t");
        printf("%d\n", heap[i]);
        display(n, left, space);
    }
}

void main()
{
    int ch, n = 0;
    printf("1.Insert\t2.Exit");
    while (1)
    {
        printf("\nEnter a Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            n = insert(n);
            display(n, 0, 0);
            printf("The Given Array forms a Min-Heap tree");
            break;
        case 2:
            exit(0);
            break;
        }
    }
}