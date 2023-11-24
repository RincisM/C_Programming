#include<stdio.h>
#include<stdlib.h>

int counter();
void display();
void createnode(int k);
int list(int a, int size);

struct node
{
    int id;
    char name[20];
    float salary;
    float exp;
    struct node *ptr;
}*head,*temp,*new,*prev;

void createnode(int k)
{
    printf("\n\nEnter the below prompted details for emp %d\n\n",k);
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the ID of emp %d: ",k);
    scanf("%d",&new->id);
    printf("Enter the name of emp %d: ",k);
    scanf(" %s",&new->name);
    printf("Enter the salary of emp %d: ",k);
    scanf("%f",&new->salary);
    printf("Enter the experience of emp %d: ",k);
    scanf("%f",&new->exp);
    new->ptr=0;
}

int list(int a,int size)
{   
    int i=0;
    head=0;
    while(i<a)
    {
        createnode(i+1);
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
    int i=1;
    temp=head;
    while(temp!=0)
    {   
        printf("\nDetails of emp %d: ",i);
        printf("\nEmp %d id: %d",i,temp->id);
        printf("\nEmp %d name: %s",i,temp->name);
        printf("\nEmp %d salary: %.2f",i,temp->salary);
        printf("\nEMp %d Experience: %.2f",i,temp->exp);
        temp=temp->ptr;
        i++;
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


void main()
{
    int base,dimension=0,pos;
    printf("\nEnter the number of employee details you would like to add: ");
    scanf("%d",&base);
    dimension=list(base,dimension);
    display();
}