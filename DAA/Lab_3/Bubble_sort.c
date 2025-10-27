#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100000

void bubble_sort(int arr[] , int n){
    int i ,j;
    int temp;
    for( i=0;i<n;i++){
        for( j=0 ; j<n-1 ; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                // swap=1;
            } 
        }
        // if(swap =0){
        //     break;
        // }
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int readArrayfromFile(const char *filename , int arr[] , int n){
    FILE *f = fopen(filename,"r");
    if(!f){
        printf("cannot open file %s",filename);
        return 0;
    }
    for(int i=0;i<n;i++){
        fscanf(f,"%d",&arr[i]);
    }
    fclose(f);
    return 1;
}

void main(){
    int arr[N];
    clock_t start , end;
    double time_taken;

    //base case
    if(readArrayfromFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\best_case_100000.txt",arr,N)){
        start = clock();
        bubble_sort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("best case time: %f ms\n", time_taken);
    }

    //worst case
    if(readArrayfromFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\worst_case_100000.txt",arr,N)){
        start = clock();
        bubble_sort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("worst case time: %f ms\n", time_taken);
    }


    //average case
    if(readArrayfromFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\average_case_100000.txt",arr,N)){
        start = clock();
        bubble_sort(arr,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("average case time: %f ms\n", time_taken);
    }


}