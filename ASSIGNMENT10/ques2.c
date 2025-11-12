#include<stdio.h>

int main(){
    int n, i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &adj[i][j]);
        }
    }

    int visited[n];
    for(i=0;i<n;i++)
        visited[i]=0;

    int queue[n], front=0, rear=0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear){
        int node = queue[front++];
        printf("%d ", node);

        for(i=0;i<n;i++){
            if(adj[node][i]==1 && visited[i]==0){
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
