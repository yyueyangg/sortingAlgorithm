# include <stdio.h>

void iSort(int arr[], int n)
{
    int i, j, key;
    for (i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;

        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {2, 4, 1, 4, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    iSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);

    return(0);
}