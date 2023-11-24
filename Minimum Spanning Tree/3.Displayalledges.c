#include <stdio.h>
int visited[10] = {0}, cost[10][10], min, i, j, a, b, num, n=1;
void input(int num) {
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
    for (i=1; i<=num; i++) {
        for(j=1; j<=num; j++) {
            if(cost[i][j]==0) {
                cost[i][j]=999;
            }
        }
    }
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
        printf("\nEdge %d : (%c-->%c)", n++, a+64, b+64);  
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                printf("%d\t", cost[i][j]);
            }
            printf("\n");
        } 
        visited[b]=1;
        cost[a][b] = cost[b][a] = 999;
    }
}

void main() {
    printf("Enter the Number of Nodes: ");
    scanf("%d", &num);
    input(num);
    prim(num);
}





