#include<stdio.h>

struct  Edge
{
    int source;
    int dest;
    int weight;
};



void sort(struct Edge edges[] , int E){
    for(int i=1 ;i<E ;i++){
        struct Edge key = edges[i];

        int j=i-1;

        while (j>=0 && key.weight<edges[j].weight)
        {
            edges[j+1] = edges[j];
            j--;
        }
        
        edges[j+1] = key;
    }
    printf("sort\n");
}

int find(int parent[],int i){
    if(parent[i]==i)
        return i;

    printf("find\n");
    return find(parent , parent[i]);
    
}


void unionset(int parent[] , int u , int v){
    parent[u]=v;
    printf("unionset\n");

}


void krushkal(int V , int E , struct Edge edges[]){
    int parent[V];
    printf("kruskal\n");

    int edge = 0;
    struct Edge mst[V-1];

    for(int i=0 ;i<V ;i++){
        parent[i] = i;
    }

    sort(edges , E);

    for(int i=0 ; i<E && edge < V-1 ;i++){
        int u = edges[i].source;
        int v = edges[i].dest;

        int ucomp = find(parent , u);
        int vcomp = find(parent , v);

        printf("%d %d \n",vcomp,ucomp);

        if(ucomp != vcomp){
            mst[edge] = edges[i];
            unionset(parent , ucomp , vcomp);
            edges++;
        }
        if(edge == V-1)
            break;
    }
}

void printGraph(struct Edge edges[], int E) {
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < E; i++) {
        printf("%d --> %d == %d\n", edges[i].source, edges[i].dest, edges[i].weight);
    }
    printf("print\n");
}


void main(){

    int V = 7;
    int E = 11;

    struct Edge edges [] ={
        {0,1,7},
        {0,3,5},
        {1,2,8},
        {1,3,9},
        {1,4,7},
        {2,4,5},
        {3,4,15},
        {3,5,6},
        {4,5,8},
        {4,6,9},
        {5,6,11}
    };

    krushkal(V, E , edges);
    printGraph(edges , V-1);
    printf("main\n");
    
}


