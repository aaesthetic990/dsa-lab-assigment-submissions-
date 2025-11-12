#include<stdio.h>

int main(){
    int n, start;
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

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    int dist[20], visited[20];
    for(int i=0;i<n;i++){
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for(int count=1; count<n-1; count++){
        int min = 999, next = -1;

        for(int i=0;i<n;i++){
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                next = i;
            }
        }

        visited[next] = 1;

        for(int i=0;i<n;i++){
            if(!visited[i] && dist[next] + cost[next][i] < dist[i])
                dist[i] = dist[next] + cost[next][i];
        }
    }

    printf("Shortest distance from vertex %d:\n", start);
    for(int i=0;i<n;i++){
        printf("%d -> %d = %d\n", start, i, dist[i]);
    }

    return 0;
}
