#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top;
    }
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        struct Node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void peek(int counter) {
    if (counter == -1)
        printf("\nStack Underflow\n");
    else
        printf("The peek of the stack is %d\n", counter);
}

void display() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("The stack is: ");
        struct Node *temp = top;
        while (temp->next != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n", temp->data);
    }
}

int main() {
    int choice, value, count = -1;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            push(value);
            count++;
            break;
        case 2:
            printf("Popped element is :%d", pop());
            count--;
            break;
        case 3:
            display();
            break;
        case 4:
            peek(count);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong Choice");
        }
    }
}
