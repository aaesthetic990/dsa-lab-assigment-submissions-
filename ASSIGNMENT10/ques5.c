#include<stdio.h>

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[20][20];
    printf("Enter the adjacency matrix (0 if no edge):\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j] = 999;
        }
    }

    int visited[20];
    for(int i=0;i<n;i++)
        visited[i]=0;

    visited[0] = 1;
    int edges = 0, minCost = 0;

    printf("Edges in MST:\n");

    while(edges < n-1){
        int min = 999, a = -1, b = -1;

        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && cost[i][j] < min){
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(a != -1 && b != -1){
            printf("%d - %d = %d\n", a, b, min);
            visited[b] = 1;
            minCost += min;
            edges++;
        }
    }

    printf("Minimum Cost = %d\n", minCost);
    return 0;
}
