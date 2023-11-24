#include<stdio.h>
#include<stdlib.h>

int counter();
int createnode(int i);
int createbase(int s,int d);
void display();



struct node
{
int data;
struct node *ptr;
}*head,*temp,*new;



int createnode(int i)
{   
    
    new=(struct node*)malloc((sizeof(struct node*)));
    printf("Enter the data:");
    scanf("%d",&new->data);
    new->ptr=0;
    if(i==0)
    {
        int dummy;
        dummy=new->data;
        return dummy;
    } 
    return 0;   
}



int createbase(int s, int d)
{
	int i=0,x,y;
	head=0;
	while(i<s)
	{   
        if(i==0)
		x=createnode(i);
        else
        y=createnode(i);
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
    new=(struct node*)malloc((sizeof(struct node*)));
    new->data=x;
    new->ptr=0;
    temp->ptr=new;
    temp=new;
	d=counter();
	return d;
}

int counter()
{
	int count=0;
	temp=head;
	while(temp!=0)
	{	
		count++;
		temp=temp->ptr;
	}
	return count;
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


void main()
{

int base,size=0,value,inx=0;
printf("Enter base node size: ");
scanf("%d",&base);
size=createbase(base,size);
printf("The Linked list after making the first element as the last element is: ");
display();
}