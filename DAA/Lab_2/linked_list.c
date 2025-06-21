#include<stdio.h>


struct node
{
    int data;
    struct node* link;
    
};
struct node *first= NULL;


void insertlast(int element){
    struct node *newNode = (struct node*)(malloc(sizeof(struct node)));

    printf("Enter a data:\n");
    scanf("%d",&newNode->data);

    struct node *save;
    newNode->link =NULL;
    save=first;

    if(first==NULL){
        first = newNode;
        return;
    }
    while (save->link !=NULL)
    {
        save= save->link;
    }
    save->link = newNode;
    
}


void deletefromlast(){
    if(first==NULL){
        printf("linked list is empty");
        return;
    }
    struct node *pred=first;
    struct node *save=first->link;

    if(first->link==NULL){
        printf("delete a node is %d",first->data);
        free(first);
        first=NULL;
    }

    while (save->link!=NULL)
    {
        pred=save;
        save=save->link;
    }
    printf("delete a node is %d",save->data);
    pred->link=NULL;
    free(save);
}


void display(){
    struct node *save=first;
    printf("Linked List\n");
    while (save!=0)
    {
        printf("%d->",save->data);
        save=save->link;
    }
    printf("\n");
}


int main(){
    int choice,element;

    while (1)
    {
        printf(".............linked list.............\n");
        printf("1.insertlast\n");
        printf("2.deletefromlast\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("Enter a choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            // printf("Enter a element ");
            // scanf("%d",&element);
            insertlast(element);
            break;
        case 2:
            deletefromlast();

        case 3:
            display();

        case 4:
            break;
            
        default:
            break;
        }
    }
    
}