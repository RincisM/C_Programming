#include<stdio.h>
#include<stdlib.h>

void createnode();
void display();
int counter();
int createbase(int index,int dimension);
int swap(int dimension,int pos);


struct node
{
    struct node *left;
    int data;
    struct node *right;
}*head,*temp,*prev,*new;

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


int swap(int dimension,int pos)
{
    int k=1;
    struct node *linker;
    temp=prev=head;
    while(k<pos)
    {
        prev=temp;
        temp=temp->right;
        k++;
    }
    prev->right=temp->right;
    linker=temp->left;
    prev=prev->right;
    prev->left=linker;
    temp->left=0;
    temp->right=head;
    head->left=temp;
    head=temp;
    dimension=counter();
    display();
    return dimension;

}

void main()
{
    int base,dimension=0,pos;
    printf("Enter the size of base Linked list: ");
    scanf("%d",&base);
    dimension=createbase(base,dimension);
    if(dimension%2==0)
    pos=dimension/2;
    else
    pos=(dimension/2) +1;
    dimension=swap(dimension,pos);
}