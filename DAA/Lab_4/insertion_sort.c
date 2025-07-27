#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100000


void insertionSort(int arr[]){
    for (int i = 1; i < N; i++){
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int size){
    for(int i = 0 ; i < size ; i++ ){
        printf("%d",arr[i]);
    }
}

int readFile(const char* filename , int arr[] , int n){
    FILE *f = fopen(filename , "r");
    if(!f){
        printf("cannot open file %s \n",filename);
        return 0;
    }
    for(int i = 0 ; i < n ; i++){
        fscanf(f , "%d", &arr[i]);
    }
    fclose(f);
    return 1;
}

void main(){
    int arr[N];
    clock_t start , end ;
    double time_taken;

    if(readFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\best_case_100000.txt",arr , N)){
        start = clock();
        insertionSort(arr);
        end = clock();
        time_taken = ((double) (end-start)) / CLOCKS_PER_SEC * 1000;
        printf("time taken for best case %f ms \n",time_taken);
    }

    if(readFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\worst_case_100000.txt",arr , N)){
        start = clock();
        insertionSort(arr);
        end = clock();
        time_taken = ((double) (end-start)) / CLOCKS_PER_SEC * 1000;
        printf("time taken for worst case %f ms \n",time_taken);
    }
    if(readFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\average_case_100000.txt",arr , N)){
        start = clock();
        insertionSort(arr);
        end = clock();
        time_taken = ((double) (end-start)) / CLOCKS_PER_SEC * 1000;
        printf("time taken for average case %f ms \n",time_taken);
    }
    
}