#include <stdio.h>
#include <conio.h>
#include <string.h>
char prefix[50];
char infix[50];
char opstack[50]; /* operator stack */
int j, top = 0;
void insert_beg(char ch)
{
    int k;
    if (j == 0)
        prefix[0] = ch;
    else
    {
        for (k = j + 1; k > 0; k--)
            prefix[k] = prefix[k - 1];
        prefix[0] = ch;
    }
    j++;
}
void push(char op) /* op – operator */
{
        opstack[top] = op; /* pushing onto stack */
        top++;
}

void main()
{
    char ch;
    int l, i = 0;
    printf("\nEnter Infix Expression : ");
    gets(infix);
    l = strlen(infix);
    while (l > 0)
    {
        ch = infix[--l];
        switch (ch)
        {
        case ' ':
            break;
        case '+':
            push(ch); /* check priority and push */
            break;
        default:
            insert_beg(ch);
        }
    }
    while (top > 0)
    {
        insert_beg(opstack[--top]);
        j++;
    }
    prefix[j] = '\0';
    printf("\nInfix Expression : %s ", infix);
    printf("\nPrefix Expression : %s ", prefix);
}