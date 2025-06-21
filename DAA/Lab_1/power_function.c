#include<stdio.h>


//iterative method
int main(){
    int x,y,pow=1;
    printf("Enter X and Y:");
    scanf("%d",&x);
    scanf("%d",&y);

    for(int i=1;i<=y;i++){
        pow=pow*x;
    }
    printf("%d Power of %d is %d",y,x,pow);
}




//recursive method

// int power(int x, int y){
//     if(y==0){
//         return 1;
//     }
//     else{
//         return x*power(x,y-1);
//     }
// }

// int main(){
//     int x,y;
//     printf("Enter x and y:");
//     scanf("%d", &x);
//     scanf("%d",&y);
//     printf("%d power of %d is %d",x,y,power(x,y));
//     return 0;
// }