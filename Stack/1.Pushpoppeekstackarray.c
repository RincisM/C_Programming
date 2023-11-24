#include <stdio.h>
#include <stdlib.h>
#define Max 6
int stack[Max];
int top;
void display()
{
    int i;
    if (top == 0)
    {
        printf("The stack is empty");
        return;
    }
    else
    {
        printf("The Elements of the stack are: ");
        for (i = top; i > 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}
void push()
{
    int data;
    if (top == Max)
    {
        printf("The Stack is Overflow");
        return;
    }
    else
    {
        top = top + 1;
        printf("Enter the data to enter: ");
        scanf("%d", &data);
        stack[top] = data;
    }
}

void pop()
{
    if (top == 0)
    {
        printf("The Stack is Empty");
        return;
    }
    else
    {
        printf("The Element poped out is: %d", stack[top]);
        top = top - 1;
    }
}

void peek()
{
    if (top == 0)
    {
        printf("The Stack is Empty");
    }
    else
    {
        printf("The Element at the top is: %d", stack[top]);
    }
}

int main()
{
    int ch = 1;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Choose your option: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter a valid option:\n");
            break;
        }
    } while (ch != 0);
    return 0;
}
