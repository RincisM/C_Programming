#include <stdio.h>
#define MAX 100
int n;
int adj[MAX][MAX];
void main()
{
   int j,i,edges,org,dest;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	edges=n*(n-1);
	
	for(i=1;i<=edges;i++)
	{
		printf("Edges %d(0 0 to quit):",i);
		scanf("%d %d",&org,&dest);
		if((org==0) && (dest==0))
		   break;
		if(org >n || dest>n|| org<=0 ||dest<=0)
		{
			printf("Invalid");
			i--;
		}
		else
		{
			adj[org][dest]=1;
		}
	}
		printf("\n The Adjacency Matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%4d",adj[i][j]);
		}
		printf("\n");
	}

for (i = 1; i <= n; i++)
{
    int outdeg = 0;
    int indeg = 0;
    for (j = 1; j <= n; j++)
    {
        if (adj[i][j] == 1)
        {
            outdeg += 1;
        }
        if (adj[j][i] == 1)
        {
            indeg += 1;
        }
    }
    printf("\nThe outdegree of %d is %d", i, outdeg);
    printf("\nThe indegree of %d is %d", i, indeg);
    printf("\nThe degree of %d is %d", i, outdeg + indeg);
}
}