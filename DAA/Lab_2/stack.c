#include<stdio.h>
#define size 100

int stack[size];
int top=-1;

void push(int element){
   if(top==size-1){
        printf("stack overflow");
   }
   else{
        stack[++top]=element;
   }
}

int pop(){
    if(top<=-1){
        printf("stack underflow");
    }
    else{
        return stack[top--];
    }
}

void display(){
    for(int i=top ; i>=0 ; i--){
        printf("%d\n", stack[i]);
    }
}

int main(){
    int choice, element;
    while (1)
    {
        printf("...................Stack list.................\n");
        printf("Enter a 1 then call push function\n");
        printf("Enter a 2 then call pop function\n");
        printf("Enter a 3 then call display method\n");
        printf("Enter a choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter a element of push\n");
            scanf("%d",&element);
            push(element);
            break;

        case 2:
            pop();
            break;
        
        case 3:
            display();
        
        default:
            break;
        }
    }
    
    
}
