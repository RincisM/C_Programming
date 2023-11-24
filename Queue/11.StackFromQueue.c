#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max 6
int Q[Max];
int rear, front;
bool isfull() {
    if(rear==Max-1) {
        return true;
    }
    else {
        return false;
    }
}

bool isEmpty() {
    if(front==-1) {
        return true;
    }
    else {
        return false;
    }
}

void insertQ() {
    int data;
    if(isfull()){
        printf("The Stack is Full");
    }
    else {
        printf("Enter the data: ");
        scanf("%d", &data);
        Q[rear] = data;
        rear++;
    }
}

void deleteQ() {
    int data;
    if(isEmpty()){
        printf("The Stack is Empty");
    }
    else {
        printf("The Element deleted is: %d", Q[--rear]);
    }
}

void display() {
    if(rear==front) {
        printf("The Queue is Empty");
    }
    else {
        printf("The Elements in the Stack are: ");
        for(int i=rear-1; i>=front; i--) {
            printf("%d ", Q[i]);
        }
    }
}

int main()
{
    int ch;
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Exit");
    while (1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertQ();
            break;
        case 2:
            deleteQ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}