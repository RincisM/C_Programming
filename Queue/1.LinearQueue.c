#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
        printf("The Queue is Full");
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
        printf("The Queue is Empty");
    }
    else {
        printf("The Element deleted is: %d", Q[front]);
        front++;
    }
}

void display() {
    if(rear==front) {
        printf("The Queue is Empty");
    }
    else {
        printf("The Elements in the Queue are: ");
        for(int i=front; i<rear; i++) {
            printf("%d ", Q[i]);
        }
    }
}

void reverse() {
    int i, j, t;
    for(i=front, j=rear; i<j; i++, j--) {
        t = Q[i];
        Q[i] = Q[j];
        Q[j] = t;
    }
    printf("The Reversed Queue is: ");
    for(i=front+1; i<=rear; i++) {
            printf("%d ", Q[i]);
        }
    
}

int menu()
{
    int ch;
    printf("\n \tQueue operations using ARRAY..");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}
void main()
{
    int ch;
    do
    {
        ch = menu();
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
            reverse();
            break;
        case 5:
            return;
        }
    } while (1);
}