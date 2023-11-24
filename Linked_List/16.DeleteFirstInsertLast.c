#include<stdio.h>
#include<stdlib.h>

void createnode();
void display();
void rev_dis();
int counter();
int createbase(int index,int dimension);
int interchange(int dimension);



struct node
{
    struct node *left;
    int data;
    struct node *right;
}*head,*temp,*prev,*new,*curr;

void createnode()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
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
    dimension=counter();
    return dimension;
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

void rev_dis()
{
    temp=head;
    while(temp->right!=0)
    {
        temp=temp->right;
    }
    while(temp!=0)
    {
        printf("%d ", temp->data);
        temp=temp->left;
    }
}

int counter()
{
    int count=0;
    temp=head;
    while(temp!=0)
    {
        count++;
        temp=temp->right;
    }
    return count;
}


int interchange(int dimension)
{
    temp=head;
    head=temp->right;
    head->left=0;
    temp->right=0;
    curr=head;
    while(curr->right!=0)
    {
        curr=curr->right;
    }
    curr->right=temp;
    temp->left=curr;
    dimension=counter();
    printf("\n\nAfter Swapping: \n\n");
    display();
    printf("\n\n");
    return dimension;

}

void main()
{
    int base,dimension=0,pos;
    printf("\nEnter the size of base Linked list: ");
    scanf("%d",&base);
    dimension=createbase(base,dimension);
    dimension=interchange(dimension);

}