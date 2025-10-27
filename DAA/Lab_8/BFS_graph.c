#include<stdio.h>
#define V 5
#define size 5

int queue[size];
int front=-1 , rear=-1;

void ENqueue(int element){
    if(rear>=size -1){
        printf("Queue overflow");
    }
    else{
        rear++;
        queue[rear]=element;

        if(front==-1){
            front=0;
        }
    }
}

int DEqueue(){
    int delete = queue[front];
    if(front==-1){
        printf("stack underflow");
        return 0;
    }
    if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
    // printf("%d",queue[front]);
    return delete;
}

int isempty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}


void bfs(int graph[V][V]){
    int visited[V]={0};

    visited[0]=1;
    ENqueue(0);
    while(isempty()){
        int u= DEqueue();
        printf("%d" , u+1);
        for(int i=0 ; i<V ; i++){
            if(visited[i]!=1){
                visited[i] =1;
                ENqueue(i);
            }
        }

    }
}


void main(){
    int graph[V][V]={
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
    };
    
    printf("BFS stating from vertex 0:\n ");
    bfs(graph);
    printf("\n ");
}