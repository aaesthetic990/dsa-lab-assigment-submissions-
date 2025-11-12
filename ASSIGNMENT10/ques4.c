#include<stdio.h>

int find(int parent[], int i){
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int parent[], int u, int v){
    int a = find(parent, u);
    int b = find(parent, v);
    parent[a] = b;
}

int main(){
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    int u[e], v[e], w[e];
    printf("Enter edges (u v w):\n");
    for(int i=0;i<e;i++)
        scanf("%d%d%d", &u[i], &v[i], &w[i]);

    for(int i=0;i<e-1;i++){
        for(int j=i+1;j<e;j++){
            if(w[i] > w[j]){
                int t = w[i]; w[i] = w[j]; w[j] = t;
                t = u[i]; u[i] = u[j]; u[j] = t;
                t = v[i]; v[i] = v[j]; v[j] = t;
            }
        }
    }

    int parent[n];
    for(int i=0;i<n;i++)
        parent[i] = i;

    int count = 0, i = 0, minCost = 0;
    printf("Edges in MST:\n");
    while(count < n-1 && i < e){
        int a = find(parent, u[i]);
        int b = find(parent, v[i]);

        if(a != b){
            printf("%d - %d = %d\n", u[i], v[i], w[i]);
            minCost += w[i];
            unionSet(parent, a, b);
            count++;
        }
        i++;
    }

    printf("Minimum Cost = %d\n", minCost);
    return 0;
}
