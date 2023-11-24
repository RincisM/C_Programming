#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

}*head,*temp,*new,*prev,*linker;
void createnode()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data for new node: ");
    scanf("%d",&new->data);
    new->next=0;
}

int counter()
{   
    int count=0,flag=0;
    temp=head;
    linker=temp;
    while(1)
    {   
        if(linker==temp && flag!=0)
        break;
        count+=1;
        temp=temp->next;
        flag=1;
    }
    return count;
}

void display()
{   
    int flag=0;
    temp=head;
    linker=temp;
    while(1)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        if(linker==temp&& flag!=0)
        break;
        flag=1;
    }
}

int pos_ins(int size,int pos)
{   
    createnode();
    int i=1;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    new->next=temp->next;
    temp->next=new;
    display();
    size=counter();
    pos=0;
    return size;
}

int beg_ins(int size)
{   
    createnode();
    new->next=head;
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    head=new;
    temp->next=head;
    display();
    size=counter();
    return size;
}

int beg_del(int size)
{   
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    temp=head;
    head=temp->next;
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
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    display();
    size=counter();
    pos=0;
    return size;
}

int list(int a, int size) {
    int i=0;
    head = 0;
    while(i<a) {
        createnode();
        if(head == 0) {
            head = temp = new;
        }
        else {
            temp->next = new;
            temp = new;
        }i++;
    }
    temp->next = head;
    display();
    size = counter();
    return size;
}

void menu()
{
        printf("\n1: Create Base Linked List");
        printf("\n2: Do Insertion Operation");
        printf("\n3: Do deletion Operation");
        printf("\n4: Exit from the menu");
}

void main()
{
    int choice=1,i,option,base,dimension=0,pos;
    menu();
    while(choice)
    {   
        printf("\nEnter your option: ");
        scanf("%d",&option);
        switch(option)
        {
            case(1):
            printf("Enter no of base node in linked list: ");
            scanf("%d",&base);
            dimension=list(base,dimension);
            break;
            
            case(2):
            printf("Enter the position to insert: ");
            scanf("%d", &pos);
            if(pos==1)
            dimension=beg_ins(dimension);
            else
            dimension=pos_ins(dimension,pos);
            break;
            
            case(3):
            printf("Enter the position to delete: ");
            scanf("%d",&pos);
            if(pos==1)
            dimension=beg_del(dimension);
            else
            dimension=pos_del(dimension,pos);
            break;

            case(4):exit(0);
            break;
            
            default:
            printf("\nWrong Option entered try again\n");
            break;           
        }
    }
}