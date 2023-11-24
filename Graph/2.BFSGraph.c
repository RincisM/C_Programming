#include <stdio.h>
int n, i, j, visited[10]; 
int queue[10], mat[10][10], front=-1, rear = -1;

void bfs(int v) {
    for(i=1; i<=n; i++) {
        if(mat[v][i] && !visited[i]) {
            queue[++rear] = i;
        }
    }
    if(front<=rear) {
        visited[queue[front]] = 1;
        bfs(queue[front++]);
    }
}

void main() {
    int org, dest, edge, j, v;
    printf("Enter the Number of Nodes to be created: ");
    scanf("%d", &n);
    edge = n*(n-1);
    for(i=1; i<=n; i++) {
        queue[i] = 0;
        visited[i] = 0;
    }
    for(i=1; i<=edge; i++) {
        printf("Edge %d Type(0 0) to exit: ", i);
        scanf("%d %d", &org, &dest);
        if(org==0 && dest ==0) {
            break;
        }
        if(org<=0 || org>n || dest<=0 || dest>n) {
            printf("Invalid");
            i--;
        }
        else{
            mat[org][dest] = 1;
        }
    }
    printf("The Adjacency Matrix is: \n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    printf("Enter the node to start BFS: ");
    scanf("%d", &v);
    bfs(v);
    printf("The Reachable Nodes are : \n");
    for(i=1; i<=n; i++) {
        if(visited[i]) {
            printf("%d\t", i);
        }
        else{
            printf("%d(Unreachable) ", i);
        }
    }
}