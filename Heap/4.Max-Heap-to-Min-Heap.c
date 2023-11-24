#include <stdio.h>
#include <stdlib.h>
int GAP = 1;
int heap[50];
int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int heapify(int n, int i)
{
    int largest, left, right;
    largest = i;
    left = (2 * i) + 1;
    right = (2 * i) + 2;
    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;
    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        heapify(i, largest);
    }
}
int insert(int n)
{
    int element, i;
    printf("\nEnter a value:");
    scanf("%d", &element);
    heap[n] = element;
    n++;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(n, i);
    }
    return n;
}

int maxtomin(int n)
{
    int i;
    for (i = n - 1; i > 0; i--)
    {
        swap(&heap[i], &heap[0]);
        heapify(i, 0);
    }
}
int display(int n, int i, int space)
{
    int j, left, right;
    if (i < n)
    {
        space = space + GAP;
        left = (2 * i) + 1;
        right = (2 * i) + 2;
        display(n, right, space);
        printf("\n");
        for (j = GAP; j < space; j++)
        {
            printf("\t");
        }
        printf("%d\n", heap[i]);
        display(n, left, space);
    }
}
int main()
{
    int choice, n = 0;
    printf("\n1.Insert\t2.MaxHeap to Minheap\t3.Exit");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            n = insert(n);
            display(n, 0, 0);
            break;

        case 2:
            maxtomin(n);
            display(n, 0, 0);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }
}