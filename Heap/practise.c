#include <stdio.h>
#include <stdlib.h>
#define Count 10
int heap[10];

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int n, int i) {
    int left = (2*i)+1, right = (2*i)+2, largest =i;
    if(left<n &&heap[left]>heap[largest])
        largest = left;
    if(right<n &&heap[right]>heap[largest])
        largest = right;
    if(largest!=i) {
        swap(&heap[i], &heap[largest]);
        heapify(n, largest);
    }
}

void display(int n, int i, int space) {
    int j, left, right;
    if(i<n) {
        space = space + Count;
        left = (2*i)+1;
        right = (2*i)+2;
        display(n, right, space);
        printf("\n");
        for(j=Count; j<space; j++) {
            printf(" ");
        }
        printf("%d\n", heap[i]);
        display(n, left, space);
    }
}

int insert(int n) {
    int a, i;
    printf("Enter the Data: ");
    scanf("%d", &a);
    heap[n] = a;
    n++;
    for(i=n/2-1; i>=0; i--) {
        heapify(n, i);
    }
    return n;
}

void main() {
    int ch, n=0;
    printf("\t1.Insert\t2.Exit");
    while(1) {
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:n = insert(n);
                   display(n, 0, 0);
                   break;
            case 2: exit(0);
            default: printf("Invalid Choide");
                     break;
        }
    }
}