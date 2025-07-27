#include <stdio.h>
#include <time.h>

#define N 100000
// #k = low and l = high

int pivot(int arr[], int k, int l)
{
    int p = arr[k];
    int i = k;
    int j = l + 1;

    k++;
    while (arr[k] <= p && i < l)
    {
        k++;
    }
    l--;
    while (arr[l] > p && l > k)
    {
        l--;
    }

    while (k < l)
    {
        int temp = arr[k];
        arr[k] = arr[l];
        arr[l] = temp;

        k++;
        while (arr[k] <= p && i < l)
        {
            k++;
        }
        l--;
        while (arr[l] > p && l > k)
        {
            l--;
        }
    }
    int temp = arr[k];
    arr[k] = arr[l];
    arr[l] = temp;
    return l;
}

void quick_sort(int arr[], int l, int k)
{
    if (l < k)
    {
        int p = pivot(arr, l, k);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, k);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n ");
}

int readArrayfromFile(const char *filename, int arr[], int n)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("cannot open file %s", filename);
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
    return 1;
}

void main()
{
    int arr[N];
    clock_t start, end;
    double time_taken;

    // best case
    if (readArrayfromFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\average_case_100000.txt", arr, N))
    {
        start = clock();
        quick_sort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("best case time complexity:%f ms\n", time_taken);
    }

    //worst case
    if (readArrayfromFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\worst_case_100000.txt", arr, N))
    {
        start = clock();
        quick_sort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("worst case time complexity:%f ms\n", time_taken);
    }

    // average case
    if (readArrayfromFile("C:\\Users\\nanda\\OneDrive\\Desktop\\Sem-5\\DAA\\Array\\average_case_100000.txt", arr, N))
    {
        start = clock();
        quick_sort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("average case time complexity:%f ms\n", time_taken);
    }
}