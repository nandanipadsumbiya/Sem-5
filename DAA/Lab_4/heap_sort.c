#include<stdio.h>
#include<time.h>

#define N 10000

int heapify(int arr[],int n,int i){
    int largest = i;
    int left = i*2 +1;
    int rigth = i*2+2;
    int temp;

    if(left <n && arr[left]>arr[largest]){
        largest = left;
    }

    if(rigth<n && arr[rigth]>arr[largest]){
        largest=rigth;
    }

    if(largest!=i){
        temp =arr[i];
        arr[i]=arr[largest];
        arr[largest] = temp;

        heapify(arr,n,largest);
    }
}


void heapsort(int arr[],int n){
    int temp;
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    for(int i=n-1;i>0;i--){
        temp= arr[0];
        arr[0]=arr[i];
        arr[i]=temp;

        heapify(arr,i,0);
    }
}

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
}

int readfile(const char* filename, int arr[],int n){
    FILE *f = fopen(filename,"r");

    if(!f){
        printf("cannot open thi file %s\n",filename);
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
    clock_t start,end;
    double time_taken;

    //best case
    if(readfile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\best_case_10000.txt",arr,N)){
        start = clock();
        heapsort(arr,N);
        end= clock();
        time_taken=((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("best case time complexity:%f ms\n",time_taken);
    }

    //worst case
    if(readfile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\worst_case_10000.txt",arr,N)){
        start = clock();
        heapsort(arr,N);
        end= clock();
        time_taken= ((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("worst case time complexity:%f ms\n",time_taken);
    }

    //average case
    if(readfile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\average_case_10000.txt",arr,N)){
        start=clock();
        heapsort(arr,N);
        end=clock();
        time_taken=((double)(end-start))/CLOCKS_PER_SEC*1000;
        printf("average case time complexity:%f ms\n",time_taken);
    }
}