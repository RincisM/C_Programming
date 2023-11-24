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
    int i,j,t,count=0;
    if(front==-1) {
        printf("The Queue is Empty");
    }
    printf("The Elements in the Queue are: ");
    for (i=front; i<rear; i++) {
        printf("%d\t", q[i]);
        count++;
    }
    printf("\nThe NUmber of Elements in the Queue is: %d", count);
}

void main() {
    int ch;
    do {
        printf("\n1.Insert\n2.Display and Count\n3.Exit");
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