#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;


/* 
 * Functions to create and display list
 */
void createList(int n);
void traverseList();
void print();
void reverse(struct node* p);

int main()
{
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);
    reverse(head);
    print();
}

/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }


    // Input data of node from the user
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL


    // Create n - 1 nodes and add to list
    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL 

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
}

void reverse(struct node* p){
 
    if(p->next == NULL){
 
        head = p;
        return;
    }
 
    /* Calling reverse method recursively */
 
    reverse(p->next);
 
    struct node* rev = p->next;
    rev->next = p;
    p->next = NULL;
}
 
void print(){
 
    struct node* p;
    p = head;
    
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}