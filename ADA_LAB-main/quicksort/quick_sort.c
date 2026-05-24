#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int arr[MAX];

int partition(int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int low, int high)
{
    if(low < high)
    {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main()
{
    srand(time(NULL));

    printf("Input Size\tTime Taken (seconds)\n");

    for(int n = 10000; n <= 50000; n += 10000)
    {
        for(int i = 0; i < n; i++)
            arr[i] = rand() % 100000;

        clock_t start = clock();

        quickSort(0, n - 1);

        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t\t%f\n", n, time_taken);
    }

    return 0;
}
