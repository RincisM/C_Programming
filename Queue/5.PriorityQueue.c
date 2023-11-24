#include <stdio.h>
#include <stdlib.h>
int data, pr;

struct ode {
    int data;
    int priority;
    struct ode*next;
};
typedef struct ode node;
node*front = NULL; 
node*rear = NULL;

int isEmpty() {
    if(front==NULL)
        return 1;
    else
        return 0;
}

void insert(int data, int pr) {
    node*temp, *ptr;
    temp = (node*)malloc(sizeof(node));
    if(temp == NULL) {
        printf("Unable to Allocate Memory");
        return;
    }
    temp->data = data;
    temp->priority = pr;
    temp->next = NULL;
    if(isEmpty() || pr>front->priority) {
        temp->next = front;
        front = temp;
    }
    else {
        ptr = front;
        while(ptr->next!=NULL &&ptr->next->priority > pr) {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void delete() {
    node*temp;
    if(isEmpty()) {
        printf("Queue is Empty");
        return;
    }
    temp = front;
    printf("\nThe Item deleted is: %d", temp->data);
    front = front->next;
    free(temp);
}

void display() {
    node*temp;
    if(isEmpty()) {
        printf("Queue is Empty");
        return;
    }
    temp = front;
    printf("\nThe Elements in the Queue are: ");
    while(temp!=NULL) {
        printf("%d [priority = %d]", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    int choice;
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