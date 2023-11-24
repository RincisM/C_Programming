#include <string.h>
#include <conio.h>
#include <stdlib.h>
char postfix[50];
char infix[50];
char opstack[50]; /* operator stack */
int i, j, top = 0;
int lesspriority(char op, char op_at_stack)
{
    int k;
    int pv1; /* priority value of op */
    int pv2; /* priority value of op_at_stack */
    char operators[] = {'+'};
    int priority_value[] = {0};
}

void push(char op) /* op - operator */
{
        opstack[top] = op; /* pushing onto stack */
        top++;

}

void main()
{
    char ch;
    printf("\nEnter Infix Expression : ");
    gets(infix);
    while ((ch = infix[i++]) != '\0')
    {
        switch (ch)
        {
        case ' ':
            break;
        case '+':
            push(ch); /* check priority and push */
            break;
        default:
            postfix[j] = ch;
            j++;
        }
    }
    while (top >= 0)
    {
        postfix[j] = opstack[--top];
        j++;
    }
    postfix[j] = '\0';
    printf("\nInfix Expression : %s ", infix);
    printf("\nPostfix Expression : %s ", postfix);
}