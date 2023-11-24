#include<stdio.h>
#include<stdlib.h>

void createnode();
int createbase(int s,int d);
void display();

struct node
{
int data;
struct node *ptr;
}*head,*temp,*new,*prev,*next;

void createnode()
{
new=(struct node*)malloc((sizeof(struct node*)));
printf("Enter the data: ");
scanf("%d",&new->data);
new->ptr=0;
}

int createbase(int s, int d)
{
	int i=0;
	head=0;
	while(i<s)
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

}


void display()
{
	temp=head;
	while(temp!=0)
	{
		printf("%d ",temp->data);
		temp=temp->ptr;
	}
}

void reverse()
{
    temp=next=head;
    prev=0;
    while(next!=0)
    {
        next=temp->ptr;
        temp->ptr=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    printf("Linked list reversed: ");
    display();
}

void main()
{
int base,size=0,value,inx=0;
printf("Enter base node size: ");
scanf("%d",&base);
size=createbase(base,size);
reverse();
}