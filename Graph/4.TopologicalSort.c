#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int n;
int adj[MAX][MAX];
void create_graph();
int queue[MAX],rear=-1,front=-1;
void insert_queue(int vertex)
{
	if(rear==MAX-1)
	  printf("Queue Overflow");
	else
	{
		if(front==-1) 
		  front=0;
		rear=rear+1;
		queue[rear]=vertex;
		
	}
}
int is_Empty()
{
	if(front==-1 ||front>rear)
	   return 1;
	else
	return 0;
}
int delete_queue()
{
	int item;
	if(front==-1||front>rear)
	{
	   printf("Queue is underflow");
	   exit(1);
	}
	else
	{
		item=queue[front];
		front=front+1;
		return item;
	}
}
int indegree(int v)
{
	int i,in_dg=0;
	for(i=1;i<=n;i++)
	{
		if(adj[i][v]==1)
	      in_dg++;
	}
	return in_dg;
	  
}
void create_graph()
{
	int j,i,max_edges,origin,destin;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	max_edges=n*(n-1);
	
	for(i=0;i<max_edges;i++)
	{
		printf("Enter edges %d(0 0 to quit):",i);
		scanf("%d %d",&origin,&destin);
		if((origin==0) && (destin==0))
		   break;
		if(origin >n || destin>n|| origin<=0 ||destin<=0)
		{
			printf("Invalid vertex:");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
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
	
}
int main()
{
	int i,v,count,topo_order[MAX],indeg[MAX];
	create_graph();
	for(i=1;i<=n;i++)
	{
		indeg[i]=indegree(i);
		if(indeg[i]==0)
		     insert_queue(i);
	}
	count=0;
	while(!is_Empty()&&count<n)
	{
		v=delete_queue();
		topo_order[++count]=v;
		for(i=1;i<=n;i++)
		{
			if(adj[v][i]==1)
			{
				adj[v][i]=0;
				indeg[i]=indeg[i]-1;
				if(indeg[i]==0)
				  insert_queue(i);
			}
		}
	}
	if(count<n)
	{
	 printf("No topological ordering possible,graph contains cycle:");
	 exit(1);
    }
    printf("Vertices in topological order is:\n");
    for(i=1;i<=count;i++)
     printf("%d ",topo_order[i]);
}