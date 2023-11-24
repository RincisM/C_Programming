#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*head,*dup;

void createNode(int n);
struct node* copyList(struct node* head1);
void disp();

int main()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    createNode(n);
    dup = copyList(head);
    disp();
}

void createNode(int n){
    struct node *newnode,*temp;
    int item,i;
    head=(struct node *)malloc(sizeof(struct node *));
    printf("Enter element 1: ");
    scanf("%d",&item);
    head->data=item;
    head->next=NULL;
    temp=head;
    for(i=2;i<=n;i++){
        newnode=(struct node *)malloc(sizeof(struct node *));
        printf("Enter element %d: ",i);
        scanf("%d",&item);
        newnode->data=item;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
}

struct node* copyList(struct node* top)
{
    struct node* newNode;
    if (top->next == NULL){
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data = top->data;
        newNode->next = NULL;
        return newNode;
    }
    else {
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data = top->data;
        top=top->next;
        newNode->next = copyList(top->next);
        return newNode;
    }
}

void disp(){
    struct node *ptr;
    ptr=dup;
    printf("The Alternate Elements List is: ");
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}