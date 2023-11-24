#include <stdio.h>
#include <stdlib.h>
void append();
void printLL();
void append1();
struct node *merge();
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *head1 = NULL;
void main()
{
    struct node *final;
    int n, i, m;
    printf("\nEnter the number of elements LL1: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        append();
    printf("\nEnter the number of elements LL2: ");
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
        append1();
    final = merge(head, head1);
    printLL(final);
}
void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number to be inserted : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        struct node *curr;
        curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void append1()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number to be inserted : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head1 == NULL)
    {
        head1 = temp;
        return;
    }
    else
    {
        struct node *curr;
        curr = head1;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void printLL(struct node *headd)
{
    struct node *p;
    p = headd;
    while (p)
    {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("None");
}

struct node *merge(struct node *head1, struct node *head2)
{
    struct node *dummy, *lasth1, *Fhead;
    dummy = (struct node *)malloc(sizeof(struct node));
    dummy->data = 0;
    Fhead = dummy;
    while (head1 && head2)
    {
        if (head1->data > head2->data)
        {
            dummy->next = head2;
            dummy = dummy->next;
            head2 = head2->next;
        }
        else
        {
            dummy->next = head1;
            dummy = dummy->next;
            head1 = head1->next;
        }
    }
    while (head1)
    {
        dummy->next = head1;
        dummy = dummy->next;
        head1 = head1->next;
    }
    while (head2)
    {
        dummy->next = head2;
        dummy = dummy->next;
        head2 = head2->next;
    }
    return Fhead = Fhead->next;
}