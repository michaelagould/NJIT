#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(int argc, char *argv[]){

    FILE *ifp = NULL;
    long start, end, total;
    int i, num, size;
    size = atoi(argv[1]);
    int sample[size];
    
    ifp = fopen(argv[1], "r");
    for(i = 0; fscanf(ifp, "%d\n", &num) == 1; i++)
        sample[i] = num;
    
    start = clock();
    mergeSort(sample, 0, size - 1);
    end = clock();
    total = end - start;
    printf("Total time: %ld\n", total);
    return 0;
}

/* random array function
int main(int argc, char *argv[])
{
    long start, end, total;
    int i, size;
    size = atoi(argv[1]);
    int sample[size];
    for(i = 0; i < size-1; i++)
        sample[i] = ((rand() % size) + 1);
    start = clock();
    mergeSort(sample, 0, size - 1);
    end = clock();
    total = end - start;
    printf("Total time: %ld\n", total);
    return 0;
}*/