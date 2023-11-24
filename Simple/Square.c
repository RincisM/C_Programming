#include<stdio.h>

int square(int);

void main()
{
     int a, result;
    
     printf("Enter a number: ");
     scanf("%d", &a);
    
     result = square(a);
    
     printf("Square of %d is %d.", a, result);
}

int square(int n)
{
     return(n*n);
}