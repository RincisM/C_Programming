#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;

void createNode(int n);
void traverseNode(struct node *temp);
struct node* copyList(struct node* head2);

int main()
{
    head=NULL;
    int n;
    printf("Enter no. of terms: ");
    scanf("%d",&n);
    createNode(n);
    struct node* dup = copyList(head);
    traverseNode(dup);
}

void createNode(int n){
    struct node *newnode,*ptr;
    int item,i;
    head=(struct node *)malloc(sizeof(struct node *));
    if(head==NULL){
        printf("Cannot allocate memory");
        exit(0);
    }
    printf("Enter element 1: ");
    scanf("%d",&item);
    head->data=item;
    head->next=NULL;
    ptr=head;
    for(int i=2;i<=n;i++){
        newnode=(struct node *)malloc(sizeof(struct node *));
        if(newnode==NULL){
            printf("Cannot allocate memory");
            break;
        }
        printf("Enter element %d: ",i);
        scanf("%d",&item);
        newnode->data=item;
        newnode->next=head;
        ptr->next=newnode;
        ptr=newnode;
    }
}

struct node* copyList(struct node* head2)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    if (head2 == NULL) {
        return NULL;
    }
    if(head2->next==head){
        newNode->data = head2->data;
        newNode->next = head;
        return newNode;
    }
    else {
        newNode->data = head2->data;
        newNode->next = copyList(head2->next);
        return newNode;
    }
}

void traverseNode(struct node *temp){
    printf("Elements of copied List are: ");
    struct node *ptr;
    ptr=temp;
    do{
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}