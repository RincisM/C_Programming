#include <stdio.h>
#define Max 6
int q[Max];
int q2[Max];
int front1;
int rear1;
int front2;
int rear2;
void insert()
{
    int data;
    printf("Enter the Data in q1: ");
    scanf("%d", &data);
    if (rear1 == Max - 1)
    {
        printf("The Queue is full");
    }
    else
    {
        q[rear1] = data;
        rear1 = rear1 + 1;
    }
    printf("Enter the Data in q2: ");
    scanf("%d", &data);
    if (rear2 == Max - 1)
    {
        printf("The Queue is full");
    }
    else
    {
        q2[rear2] = data;
        rear2 = rear2 + 1;
    }
}

void display()
{
    int j;
    if (front1 == -1)
    {
        printf("The Queue is Empty");
    }
    else
    {
        printf("The Elements in the Queue 1 are: ");
        for (int i = front1; i < rear1; i++)
        {
            printf("%d ", q[i]);
        }
    }
    if (front2 == -1)
    {
        printf("The Queue is Empty");
    }
    else
    {
        printf("\nThe Elements in the Queue 2 are: ");
        for (int i = front2; i < rear2; i++)
        {
            printf("%d ", q2[i]);
        }
    }
    for (int i = front1, j = front2; i < rear1, j < rear2; i++, j++)
    {
        if (q[i] != q2[j])
        {
            printf("\nDifferent");
            break;
        }
        else
        {
            printf("\nSame");
            break;
        }
    }
}
void main()
{
    int ch;
    do
    {
        printf("\n1.Insert \n2.Display and check \n3.Exit");
        printf("\nEnter one of the Options: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;
        case 3:
            return;
        default:
            printf("Wrong Choice");
            break;
        }
    } while (ch != 4);
}