#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *ptr;
}*head,*temp,*new,*prev;

void createnode()
{
new=(struct node*)malloc((sizeof(struct node*)));
printf("Enter the data: ");
scanf("%d",&new->data);
new->ptr=0;
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
	d=counter();
	return d;
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


int check()
{	
	int flag1=0;
	temp=prev=head;
	while(temp->ptr!=0)
	{
		prev=temp;
		temp=temp->ptr;
		if(prev->data > temp->data)
		{	
			flag1=1;
			break;
		}
		
	}
	if(flag1==0)
	return 0;
	else
	return 1;
}
	
void sort()
{   
    int inter,control=1;
    while(control)
    {
        temp=prev=head;
        while(temp->ptr!=0)
        {
            prev=temp;
            temp=temp->ptr;
            if((prev->data) > (temp->data))
            {
                inter=prev->data;
                prev->data=temp->data;
                temp->data=inter;
            }
            else
            {
                continue;
            }
        }
        control=check();  
    }
    printf("\nSorted linked list: ");
    display();
}


int beg_ins(int size)
{   
    createnode();
    new->ptr=head;
    head=new;
    display();
    size=counter();
    return size;
}

int end_ins(int size)
{
    createnode();
    temp=head;
    while(temp->ptr!=0)
    {
        temp=temp->ptr;
    }
    temp->ptr=new;
    display();
    size=counter();
    return size;
}

int pos_ins(int size,int pos)
{   
    createnode();
    int i=1;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->ptr;
        i++;
    }
    new->ptr=temp->ptr;
    temp->ptr=new;
    display();
    size=counter();
    pos=0;
    return size;

}

int beg_del(int size)
{   
    temp=head;
    head=temp->ptr;
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
    display();
    size=counter();
    pos=0;
    return size;
}

void wholedelete()
{   
    temp=head;
    while(head!=0)
    {
        temp=head;
        head=head->ptr;
    }
    printf("\nSuccessfully deleted\n");
    display();


}

void main()
{
int i;
int base,dimension=0,value,pos;
printf("Enter base node size: ");
scanf("%d",&base);
dimension=createbase(base,dimension);
do {
printf("Enter the position you would like to carry out the insertion operation: ");
            scanf("%d", &pos);
            if(pos==1)
            dimension=beg_ins(dimension);
            else if(pos==dimension+1)
            dimension=end_ins(dimension);
            else
            dimension=pos_ins(dimension,pos);
printf("\nEnter the position you would like to carry out the deletion operation: ");
            scanf("%d",&pos);
            if(pos==1)
            dimension=beg_del(dimension);
            else if(pos==dimension)
            dimension=end_del(dimension);
            else
            dimension=pos_del(dimension,pos);
printf("\nTo continue press any number, to end press 0: ");
scanf("%d", &i);
}while(i!=0);
printf("\nThe Unsorted Linked List is: ");
display();
sort();
wholedelete();
}