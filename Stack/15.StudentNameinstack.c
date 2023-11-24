#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//structure to implement the stack

typedef struct node
{
    char info[1000];//character array to store names
    struct node*next;//pointer to structure to store address of next node
}node;

//pushing elements into the stack
void push(node **t,char data[])
{
    node *temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        //if node is not able to allocate in memory
        printf("Not enough memory\n");

    }
    else
    {
        //storing the names in the stack
        for(int i=0;i<data[i]!='\0';i++)
            temp->info[i]=data[i];
           temp->info[strlen(data)]='\0';
        if(*t==NULL)
        {
         *t=temp;
         temp->next=NULL;
        }
        else
        {
            temp->next=*t;
            *t=temp;
        }
    }

}

void display(node *t)
{
    if(t==NULL)
        printf("Stack is empty\n");
    else
    {
      while(t!=NULL)
      {
        printf("%s\n",t->info);
        t=t->next;
      }
    }
}

void main()
{
    int n;char ch;
    char name[100];
    node *top=NULL;
    do{
         printf("Enter name of student to be stored in stack: ");
         fflush(stdin);
         scanf("%s",&name);
         push(&top,name);

        printf("Do you want to continue(y/n)?: ");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    printf("\nNames stored in stack are:\n");
    display(top);

}
