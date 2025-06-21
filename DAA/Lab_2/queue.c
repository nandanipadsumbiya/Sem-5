#include<stdio.h>
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
    if(front==-1){
        printf("stack underflow");
        return 0;
    }
    if(front==rear){
        front=rear=0;
    }
    else{
        front++;
    }
    printf("%d",queue[front]);
    return queue[front];
}


void display(){
    for(int i=front ; i<=rear ; i++){
        printf("%d\n", queue[i]);
    }
    printf("\n"); 
    
}




int main(){
    int choice, element;
    while (1)
    {
        
        printf("Enter a 1 then call ENqueue function\n");
        printf("Enter a 2 then call DEqueue function\n");
        printf("Enter a 3 then call display method\n");
        printf("Enter a choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter a element of ENqueue\n");
            scanf("%d",&element);
            ENqueue(element);
            break;

        case 2:
            DEqueue();
            break;
        
        case 3:
            printf("...................queue list.................\n");
            display();
            break;
        
        default:
            break;
        }
    }
    
    
}

