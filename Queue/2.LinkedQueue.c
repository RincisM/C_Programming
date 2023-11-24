#include <stdlib.h>
#include <conio.h>
struct queue
{
    int data;
    struct queue *next;
};
typedef struct queue node;
node *front = NULL;
node *rear = NULL;
node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("\nEnter data ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    return temp;
}
void insertQ()
{
    node *newnode;
    newnode = getnode();
    if (newnode == NULL)
    {
        printf("The Queue is Full");
        return;
    }
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void deleteQ()
{
    node *temp;
    if (front == NULL)
    {
        printf("Empty Queue..");
        return;
    }
    temp = front;
    front = front->next;
    printf("\nDeleted element from queue is %d ", temp->data);
    free(temp);
}
void displayQ()
{
    node *temp;
    if (front == NULL)
    {
        printf("Empty Queue ");
    }
    else
    {
        temp = front;
        printf("\nElements in the Queue are: ");
        while (temp != NULL)
        {
            printf("%5d ", temp->data);
            temp = temp->next;
        }
    }
}
int menu()
{
    int ch;
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}
void main()
{
    int ch;
    do
    {
        ch = menu();
      switch (ch)
        {
        case 1:
            insertQ();
            break;
        case 2:
            deleteQ();
            break;
        case 3:
            displayQ();
            break;
        case 4:
            return;
        }
    } while (ch != '4');
}