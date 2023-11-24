#include<stdio.h>
#include<stdlib.h>

void createnode();
void display();
int counter();
int createbase(int index,int dimension);
void swap();


struct node
{
    struct node *left;
    int data;
    struct node *right;
}*head,*temp,*prev,*new;

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

void swap()
{
    int i=0,var,size=counter();
    temp=prev=head;
    while(temp->right!=0)
        {
            temp=temp->right;
        }
    while(i<(size/2))
    {   
        var=prev->data;
        prev->data=temp->data;
        temp->data=var;
        prev=prev->right;
        temp=temp->left;
        i++;
    }

    printf("\n\nLinked list after swap: ");
    display();

}


void main()
{
    int base,size=0;
    printf("\nEnter no of base node in linked list: ");
    scanf("%d",&base);
    size=createbase(base,size);
    swap();
}