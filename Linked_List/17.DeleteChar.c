#include<stdio.h>
#include<stdlib.h>


int counter();
void display();
void createnode();
int list(int a, int size);
int beg_del(int size);
int end_ins(int size);
int pos_del(int size,int pos);
int posFinder1(char value);
int posFinder2(char value);
void findanddelete(char value);



struct node
{
    char data;
    struct node *ptr;
}*head,*temp,*new,*prev,*curr;

void createnode()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter a character data for new node: ");
    scanf(" %c",&new->data);
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
    printf("Linked list is: ");
    while(temp!=0)
    {
        printf("%c ",temp->data);
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


int posFinder1(char value)
{
    int i=1,linker;
    temp=head;
    while(temp!=0)
    {
        if(temp->data==value)
        {
            linker=i;
            break;
        }
        temp=temp->ptr;
        i++;
    }
    return linker;
}


int posFinder2(char value)
{
    int i=1,linker;
    temp=head;
    while(temp!=0)
    {
        if(temp->data==value)
        linker=i;
        temp=temp->ptr;
        i++;
    }
    return linker;
}


void findanddelete(char value)
{
    int i=1,linker,dimension=0;
    curr=head;
    while(curr!=0)
    {   
        int flag=0;
        if(curr->data==value)
        {
            linker=i;
            if(linker==1)
            {   
                dimension=beg_del(dimension);
                curr=head;
                i=1;
                flag=1;
            }
            else if(linker==dimension)
            {
                curr=curr->ptr;
                dimension=end_del(dimension);
                i=1;
                flag=1;
            }
            else
            {   
                curr=curr->ptr;
                dimension=pos_del(dimension,linker);
                curr=head;
                i=1;
                flag=1;
            }         
        }      
        if(flag==0)
        {
            i++;
            curr=curr->ptr;
        }
        else
        continue;
    }

}

void main()
{   
    int base,dimension=0,pos;
    char val;
    printf("Enter the size of base Linked list: ");
    scanf("%d",&base);
    dimension=list(base,dimension);
    display();
    printf("\nEnter data which to be removed on it's first occurrence: ");
    scanf(" %c",&val);
    pos=posFinder1(val);
            if(pos==1)
            dimension=beg_del(dimension);
            else if(pos==dimension)
            dimension=end_del(dimension);
            else
            dimension=pos_del(dimension,pos);
    printf("\nEnter data which to be removed on it's last occurrence: ");
    scanf(" %c",&val);
    pos=posFinder2(val);
            if(pos==1)
            dimension=beg_del(dimension);
            else if(pos==dimension)
            dimension=end_del(dimension);
            else
            dimension=pos_del(dimension,pos);
    printf("\nEnter the data which is to be removed at every occurrence: ");
    scanf(" %c",&val);
    findanddelete(val);
    display();

}