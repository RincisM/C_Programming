#include <stdio.h>
#include <stdlib.h>
#define Max 6
int q[Max];
int front, rear;

void insert() {
    int data;
    printf("Enter the Data: ");
    scanf("%d", &data);
    if(rear==Max-1) {
        printf("The Queue is Full");
    }
    else {
        q[rear] = data;
        rear = rear+1;
    }
}

void display() {
    int i, j, t;
    printf("The Elements in the Queue are: ");
    for (int i=front; i<rear; i++) {
        printf("%d", q[i]);
    }
    for(i = front, j= rear; i<j; i++, j--) {
        t = q[i];
        q[i] = q[j];
        q[j] = t;
    }
    printf("\nThe Reversed Order is: ");
    for(int i=front+1; i<=rear; i++) {
        printf("%d", q[i]);
    }
}

void main() {
    int ch;
    do {
        printf("\n1.Insert\n2.Display\n3.Exit");
        printf("\nEnter one of the Options: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert();
                    break;
            case 2: display();
                    break;
            case 3: exit(0);
                    break;
            default: printf("Wrong Choice\n");
                     break;
        }
    }while(ch!=3);
}