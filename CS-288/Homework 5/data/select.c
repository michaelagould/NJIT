#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

int main(int argc, char *argv[]){

    FILE *ifp = NULL;
    long start, end;
    double total;
    int i, num, size;
    size = atoi(argv[1]);
    int sample[size];
    

    ifp = fopen(argv[1], "r");
    for(i = 0; fscanf(ifp, "%d\n", &num) == 1; i++)
        sample[i] = num;
    
    start = clock();
    selectionSort(sample, size);
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time (seconds): %f\n", total);
    return 0;
}


/* Random array functionality
int main(int argc, char *argv[])
{
    long start, end, total;
    int i, size;
    size = atoi(argv[1]);
    int sample[size];
    for(i = 0; i < size-1; i++)
        sample[i] = ((rand() % size) + 1);
    start = clock();
    selectionSort(sample, size);
    end = clock();
    total = end - start;
    printf("Total time: %ld\n", total);
    return 0;
}*/