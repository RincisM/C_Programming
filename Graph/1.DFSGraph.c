#include <stdio.h>
#include <stdlib.h>
#define Max 50
#define initial 1
#define visited 2
#define finished 3
int mat[Max][Max];
int state[Max];
int n;
void DFS(int v) {
    int i;
    printf(" %d", v);
    state[v]= visited;
    for(i=1; i<=n; i++) {
        if(mat[v][i]==1 && state[i] == initial)
            DFS(i);
    }
    state[v] = finished;
}

void main() {
    printf("Enter the Number of Nodes: ");
    scanf("%d", &n);
    int edge, org, dest, i, j;
    edge = n*(n-1);
    for(i=1; i<=edge; i++) {
        printf("Edge %d Type (0 0 ) to exit: ", i);
        scanf("%d %d", &org, &dest);
        if(org==0 && dest ==0) {
            break;
        }
        if(org>n || dest>n || org<=0 || dest<=0) {
            printf("Invalid");
            i--;
        }
        else{
            mat[org][dest] = 1;
        }
    }
    printf("The Adjacency Matrix is : \n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    int v;
    for(v=1; v<=n; v++) {
        state[v] = initial;
    }
    printf("Enter the node to visit first: ");
    scanf("%d", &v);
    DFS(v);
    for(v=1; v<=n; v++) {
        if(state[v] == initial)
            DFS(v);    
    }
    printf("\n");
}