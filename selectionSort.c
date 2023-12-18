# include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sSort(int arr[], int n)
{
    int i, j, min_ind;

    for (i=0; i<n-1; i++)
    {
        min_ind = i;
        for (j=i+1; j<n; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }

        if (min_ind != i)
        {
            swap(&arr[min_ind], &arr[i]);
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {32, 54, 12, 452, 1, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    sSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);

    return(0);
}