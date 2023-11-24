#include<stdio.h>
#include<stdlib.h>
int counter();
void display();
void createnode();
int list(int a, int size);
int beg_del(int size);
int end_ins(int size);
int pos_del(int size,int pos);


struct node
{
    int data;
    struct node *ptr;
}*head,*temp,*new,*prev;

void createnode()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data for new node: ");
    scanf("%d",&new->data);
    new->ptr=0;
}

int list(int a,int size)
{   
    int i=0;
    head=0;
    while(i<a)
    {
        createnode();
        if(head==0)
        {
            head=temp=new;
        }
        else
        {
            temp->ptr=new;
            temp=new;
        }
        i++;
    }
    size=counter();
    return size;
}

void display()
{
    temp=head;
    printf("Linked list is: \n");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->ptr;
    }
}

int counter()
{   
    int count=0;
    temp=head;
    while(temp!=0)
    {
        count+=1;
        temp=temp->ptr;
    }
    return count;
}

int beg_del(int size)
{   
    temp=head;
    head=temp->ptr;
    free(temp);
    display();
    size=counter();
    return size;
}

int end_del(int size)
{
    temp=prev=head;
    while(temp->ptr!=0)
    {   
        prev=temp;
        temp=temp->ptr;
    }
    prev->ptr=0;
    free(temp);
    display();
    size=counter();
    return size;
}

int pos_del(int size,int pos)
{
    int i=1;
    temp=prev=head;
    while(i<pos)
    {   
        prev=temp;
        temp=temp->ptr;
        i++;
    }
    prev->ptr=temp->ptr;
    free(temp);
    display();
    size=counter();
    pos=0;
    return size;
}

void main()
{
    int base,dimension=0,pos;
    printf("Enter the size of base Linked list:");
    scanf("%d",&base);
    dimension=list(base,dimension);
    display();
    printf("Enter the position you would like to carry out the deletion operation: ");
    scanf("%d",&pos);
    if(pos==1)
    dimension=beg_del(dimension);
    else if(pos==dimension)
    dimension=end_del(dimension);
    else
    dimension=pos_del(dimension,pos);

}