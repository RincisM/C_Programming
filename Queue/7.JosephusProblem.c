#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};

int survivor(struct node **head, int k)
{
    struct node *p, *q;
    int i;
    q = p = *head;
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        //printf("%d has been killed.\n", p->num);
        free(p);
        p = q->next;
    }
    *head = p;
    return (p->num);
}

void create(struct node **head)
{
    struct node *temp, *rear;
    int a;
        printf("Enter a number of persons: ");
        scanf("%d", &a);
        for(int i=1; i<=a; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = i;
        temp->next = NULL;
        if (*head == NULL)
            *head = temp;
        else
            rear->next = temp;
        rear = temp; }
    rear->next = *head;
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    printf("%d   ", temp->num);
    temp = temp->next;
    while (head != temp)
    {
        printf("%d   ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    int survive, skip;
    create(&head);
    printf("The persons in circular list are:\n");
    display(head);
    printf("Enter the number of persons to be skipped: ");
    scanf("%d", &skip);
    survive = survivor(&head, skip);
    printf("The person to survive is : %d\n", survive);
    free(head);
    return 0;
}