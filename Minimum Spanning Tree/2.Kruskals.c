#include <stdio.h>
#include <stdlib.h>
int visited[10] = {0}, cost[10][10],parent[10], min, mincost=0, v, u, a, b, i, j;
int find(int i) {
    while(parent[i]){
        i = parent[i];
    }
    return i;
}
int uni(int i, int j){
    if(i!=j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}


void main() {
    int n, k=1;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Cost matrix");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("The Cost matrix");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    while(k<n) {
        for (i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if(cost[i][j] <min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if(uni(u, v)) {
            printf("Edge(%c, %c) is %d", a+64, b+64, min);
            mincost +=min;
            for(i=1; i<=n; i++) {
                for(j=1; j<=n; j++) {
                    printf("%d\t", cost[i][j]);
                }
                printf("\n");
            }
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("The Total Cost is: %d", mincost);
}