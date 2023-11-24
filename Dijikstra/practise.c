#include<stdio.h>
#include<stdlib.h>
#define INFINITY 999
#define Max 10
int g[Max][Max], adj[Max][Max],n, i, j, k , l,m, o, u, mindist, dist[Max], pred[Max], visited[Max], count, nextnode;

void main() {
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            printf("Cost of [%d][%d]: ", i, j);
            scanf("%d", &g[i][j]);
        }
    }
    printf("The Matrix is: ");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            printf("%d\t", g[i][j]);
        }
        printf("\n");
    }
    printf("Enter the Starting Node: ");
    scanf("%d", &u);
    for(i=1; i<=n; i++) {
        dist[i] = g[u][i];
        pred[i] = u;
        visited[i] = 0;
    }
    dist[u] = 0;
    visited[u] = 1;
    count = 1;
    while(count<n-1) {
        mindist = INFINITY;
        for(i=1; i<=n; i++) {
            if(dist[i] < mindist && !visited[i]) {
                mindist = dist[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for(i=1; i<=n; i++) {
            if(!visited[i]) {
                if(mindist + g[nextnode][i] < dist[i]) {
                    dist[i] = mindist + g[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }
    for(i=1; i<=n; i++) {
        if(i!=u) {
            if(dist[i] == 999)
                printf("Path Does not exists");
            else {
                printf("Path distance is:%d", dist[i]);
                printf("Path is %d", i);
                o = i;
                j = i;
                do {
                    j = pred[j];
                    printf("<-%d", j);
                    m = j;
                    adj[m][o] = g[m][o];
                    o = j;
                }while(j!=u);
                printf("Adjacency Matrix: ");
                for(k = 1; k<=n; k++) {
                    for(l=1; l<=n; l++) {
                        printf("%d\t", g[k][l]);
                    }
                    printf("\n");
                }
            }
        }
    }
}