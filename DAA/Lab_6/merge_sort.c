#include<stdio.h>
#include<time.h>
#include<stdalign.h>

#define N 100000

void merge(int arr[], int left , int mid ,int right ){
    int n1 = mid-left+1;
    int n2 = right-mid;

    int L[n1], R[n2];

    for(int i=0 ; i<n1 ;i++){
        L[n1] = arr[left +i];
    }
    for(int j=0 ; j<n2 ;j++){
        R[n2] = arr[mid+1+j];
    }

    int i= 0 ,  j = 0 , k=left;

    while (i<n1 && j<n2)
    {
        if(L[i]<=R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while(i<n1){
        arr[k++] = L[i++];
    }
    while (j<n2)
    {
        arr[k++] = R[j++];
    }
    
    
}

void mergesort(int arr[], int left , int right){
    if(left<right){
        int mid = left + (right - left)/2; // range ni vache rakhava aano use thai chhe element rang ni bar no jai  or (left+right)/2 no use kari sakai

        mergesort(arr , left , mid);
        mergesort(arr , mid+1 , right);

        merge(arr , left , mid , right);
    }
}



void printArray(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n ");
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
    int key;
    clock_t start , end;
    double time_taken;

    //base case
    if(readArrayfromFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\best_case_100000.txt",arr,N)){
        start = clock();
        mergesort(arr,0,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("best case time: %f ms\n", time_taken);
    }

    //worst case
    if(readArrayfromFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\worst_case_100000.txt",arr,N)){
        start = clock();
        mergesort(arr,0,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("worst case time: %f ms\n", time_taken);
    }


    //average case
    if(readArrayfromFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\average_case_100000.txt",arr,N)){
        start = clock();
        mergesort(arr,0,N);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("average case time: %f ms\n", time_taken);
    }


}