#include<stdio.h>
#include<stdlib.h>

void createnode();
void display();
int createbase(int index,int dimension);
void sort();
int check();


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
}

void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->right;
    }
}

int check()
{	
	int flag1=0;
	temp=prev=head;
	while(temp->right!=0)
	{
		prev=temp;
		temp=temp->right;
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
        while(temp->right!=0)
        {
            prev=temp;
            temp=temp->right;
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
    display();
}

void main()
{
    int base,dimension=0;
    printf("Enter the Number of nodes: ");
    scanf("%d",&base);
    dimension=createbase(base,dimension);
    printf("\nBefore Sort:");
    display();
    printf("\nAfter Sort: ");
    sort();
}