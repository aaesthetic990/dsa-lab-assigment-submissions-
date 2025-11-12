#include<stdio.h>

int main(){
    int n, choice, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int adj[n][n];

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &adj[i][j]);
        }
    }

    while(1){
        printf("\n1. Display Adjacency Matrix\n2. Degree of Vertex\n3. In-Degree of Vertex\n4. Out-Degree of Vertex\n5. Adjacent Vertices\n6. Number of Edges\n7. Exit\n");
        scanf("%d", &choice);

        if(choice==1){
            printf("Adjacency Matrix:\n");
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    printf("%d ", adj[i][j]);
                }
                printf("\n");
            }
        }

        else if(choice==2){
            int v, deg=0;
            printf("Enter vertex (0 to %d): ", n-1);
            scanf("%d", &v);
            for(i=0;i<n;i++){
                deg += adj[v][i] + adj[i][v];
            }
            printf("Degree of vertex %d: %d\n", v, deg);
        }

        else if(choice==3){
            int v, indeg=0;
            printf("Enter vertex (0 to %d): ", n-1);
            scanf("%d", &v);
            for(i=0;i<n;i++){
                indeg += adj[i][v];
            }
            printf("In-Degree of vertex %d: %d\n", v, indeg);
        }

        else if(choice==4){
            int v, outdeg=0;
            printf("Enter vertex (0 to %d): ", n-1);
            scanf("%d", &v);
            for(i=0;i<n;i++){
                outdeg += adj[v][i];
            }
            printf("Out-Degree of vertex %d: %d\n", v, outdeg);
        }

        else if(choice==5){
            int v;
            printf("Enter vertex (0 to %d): ", n-1);
            scanf("%d", &v);
            printf("Adjacent vertices of %d: ", v);
            for(i=0;i<n;i++){
                if(adj[v][i]==1)
                    printf("%d ", i);
            }
            printf("\n");
        }

        else if(choice==6){
            int edges=0;
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(adj[i][j]==1)
                        edges++;
                }
            }
            printf("Number of edges: %d\n", edges);
        }

        else
            break;
    }
    return 0;
}
