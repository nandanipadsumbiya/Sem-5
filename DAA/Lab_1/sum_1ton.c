#include<stdio.h>


//iterative method

// void main(){
//     int n;
//     int sum=0;
//     int i;

//     printf("Enter a number n:");
//     scanf("%d",&n);

//     for(i=0;i<=n;i++){
//         sum+=i;
//     }
//     printf("sum of %d number %d",n,sum);
// }




//recursive method

int sum_1ton(int n){
    if(n<=1){
        return 1;
    }
    else{
        return n+ sum_1ton(n-1);
    }

}
void main(){
    int n;
    
    printf("Enter a number n:");
    scanf("%d",&n);

    int ans = sum_1ton(n);
    printf("sum of %d number %d",n,ans);

}