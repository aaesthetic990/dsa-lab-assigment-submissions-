#include<stdio.h>

void dfs(int adj[20][20], int visited[20], int n, int v){
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for(i=0;i<n;i++){
        if(adj[v][i]==1 && visited[i]==0)
            dfs(adj, visited, n, i);
    }
}

int main(){
    int n, i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[20][20];
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &adj[i][j]);
        }
    }

    int visited[20];
    for(i=0;i<n;i++)
        visited[i]=0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(adj, visited, n, start);

    return 0;
}
