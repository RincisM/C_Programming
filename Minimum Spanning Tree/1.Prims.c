#include <stdio.h>
int visited[10] = {0}, cost[10][10], min, mincost=0;
void input(int num) {
    int i, j, val;
    printf("Enter the Adjacency Matrix\n");
    for(i=1; i<=num; i++) {
        for(j=1; j<=num; j++) {
            printf("Cost of[%c][%c]: ", i+64, j+64);
            scanf("%d", &cost[i][j]);
        }
    }
    printf("The Cost is: (in Matrix Representation)\n");
    for(i=1; i<=num; i++) {
        for(j=1; j<=num; j++) {
            printf("%3d", cost[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

int prim(int num) {
    int i, j, a, b, min, n=1;
    visited[1]=1;
    while(n<num) {
        for(i=1, min=999; i<=num; i++) {
            for(j=1; j<=num; j++) {
                if(cost[i][j]<min) {
                    if(visited[i]!=0){
                        min = cost[i][j];
                        a = i;
                        b= j;
                    }
                }
            }
        }
        if(visited[a]==0 || visited[b]==0)
		{
			printf("\nEdge %d : (%c, %c) : Cost: %d\n", n++, a+64, b+64, min);
			mincost+=min;
			visited[b]=1;
            printf("The Cost is: (in Matrix Representation)\n");
            for(i=1; i<=num; i++) {
                for(j=1; j<=num; j++) {
                    printf("%3d", cost[i][j]);
                    printf("\t");
                }
                printf("\n");
            }
		}
        
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nThe Total Minimum Cost is: %d", mincost);

}

void main() {
    int num;
    printf("Enter the Number of Nodes: ");
    scanf("%d", &num);
    input(num);
    prim(num);
}