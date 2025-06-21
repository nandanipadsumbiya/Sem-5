#include<stdio.h>


//iterative method

// void main(){
//     int number ;
//     int count=0;
//     int ans =1;

//     printf("Enter a number :");
//     scanf("%d",&number);

//     while (number>0)
//     {
//         count+=1;
//         number/=10;
//     }
//     printf("count a number %d",count); 
// }





//recursive method

int digit_count(int n){
    if(n<=0){
        return 0;
    }
    else{
        return 1 + digit_count(n/10);
    }
    
}
void main(){
    int number ;
    int count=0;

    printf("Enter a number :");
    scanf("%d",&number);

    int result = digit_count(number);
    printf("count of number %d",result);
}