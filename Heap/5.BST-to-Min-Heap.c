#include <stdio.h>
#include <stdlib.h>
int heap[50];
int GAP=1;
void swap(int *a,int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}
void heapify(int n,int i)
{
	int smallest,left,right;
    smallest=i;
    left=(2*i)+1;
    right=(2*i)+2;
    if (left<n&&heap[left]<heap[smallest])
    	smallest=left;
    if (right<n&&heap[right]<heap[smallest])
    	smallest=right;
    if (smallest!=i)
    {
    	swap(&heap[i],&heap[smallest]);
    	heapify(n,smallest);
    }
}
int insert(int n)
{
	int node,i;
	printf("\nEnter the value: ");
	scanf("%d",&node);
    heap[n]=node;
    n++;
    for(i=n/2-1;i>=0;i--)
    	heapify(n,i);
    return n;
}
void display(int n,int i,int space)
{
	int j,left,right;
    if(i<n) 
    {
        space=space+GAP;
        left=(2*i)+1;
        right=(2*i)+2;
        display(n,right,space);
        printf("\n");
        for(j=GAP;j<space;j++)
            printf("\t");
        printf("%d\n",heap[i]);
        display(n,left,space);
    }
}
void main()
{
    int choice,n=0;
    printf("\n1.Insert\t2.End");
    while(1)
    {
    	printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: n=insert(n);
					display(n,0,0);
					break;
			case 2: exit(0);
                    break;
			default:printf("\nInvalid Choice");
                    break;
		}
    }
}
