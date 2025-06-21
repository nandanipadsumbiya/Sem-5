#include<stdio.h>


//iterative method

// void main(){
//     int n;
//     int sum=1;
//     int i;

//     printf("Enter a number n :");
//     scanf("%d",&n);

//     for(i=n;i>=1;i--){
//         sum = sum*i;
//     }

//     printf("factorial of %d using loop is = %d",n,sum);
// }





//recursive method

int fact(n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n* fact(n-1);
    }

}

void main(){
    int num;
    int sum=1;
    int i;

    printf("Enter a number num :");
    scanf("%d",&num);

    int ans = fact(num);

    printf("factorial of %d using loop is = %d",num,ans);

}