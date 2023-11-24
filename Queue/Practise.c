#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int priority;
    struct node*next;
};
typedef struct node a;
a*front = NULL;
a*rear = NULL;

int isEmpty() {
    if(front ==NULL)
        return 1;
    else
        return 0;
}

void insert(int data, int priority){
    a*temp, *ptr;
    temp = (a*)malloc(sizeof(a));
    if(temp==NULL){
        printf("Unable to allocate Memory");
        return;
    }
    temp ->data = data;
    temp->priority = priority;
    temp->next = NULL;
    if(isEmpty() || priority>front->priority) {
        temp->next = front;
        front = temp;
    }
    else {
        ptr = front;
        while(ptr->next != NULL && ptr->next->priority > priority) {
            ptr = ptr->next;
        }
        temp -> next = ptr->next;
        ptr->next = temp;
    }
}

void delete() {
    a*temp;
    if(isEmpty()) {
        printf("The Queue is Empty");
        return;
    }
    temp = front;
    printf("The Element deleted from the Queue is: %d", temp->data);
    front = front->next;
    free(temp);
}

void display() {
    a*temp;
    if(isEmpty()) {
        printf("The Queue is Empty");
        return;
    }
    temp = front;
    while(temp!=NULL) {
        printf("%d [priority - %d]", temp->data, temp->priority);
        temp = temp->next;
    }
}

void main() {
    int choice,data, pr;
    printf("\n1.Insert\n2.delete\n3.display\n4.Exit");
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter the Data to be inserted: ");
                    scanf("%d", &data);
                    printf("Enter the Priority: ");
                    scanf("%d", &pr);
                    insert(data, pr);
                    display();
                    break;
            case 2: delete();
                    display();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid Option");
                     break;
        }
    }
}