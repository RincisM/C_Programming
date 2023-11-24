#include<stdio.h>
#include<stdlib.h>

void createnode();
void display();
int createbase(int index,int dimension);
void add();



struct node
{
    struct node *left;
    int data;
    struct node *right;
}*head,*temp,*prev,*new,*curr;

void createnode()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&new->data);
    new->left=0;
    new->right=0;
}

int createbase(int index,int dimension)
{   
    int i=0;
    head=0;
    while(i<index)
    {   
        createnode();
        if(head==0)
        {
            head=temp=prev=new;
        }
        else
        {
            prev->right=new;
            temp=temp->right;
            temp->left=prev;
            prev=temp;
        }
        i++;
    }
}


void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->right;
    }
}


void add()
{
    temp=head;
    while(temp!=0)
    {
        temp->data=(temp->data)+10;
        temp=temp->right;
    }
    printf("Linked List after addition is: ");
    display();
}

void main()
{
    int base,dimension=0,pos;
    printf("Enter the size of base Linked list: ");
    scanf("%d",&base);
    dimension=createbase(base,dimension);
    add();
}