/*
Recursive algorithm 
divides an array into smaller subarrays(half),
sorts each subarray, 
merge the sorted subarrays

Advantages 
worst case time complexity of O(N logN), better than N^2

Disadvantages
requires additional memory space to store mergerd subarrays 
not optimal for small datasets
*/


# include <stdio.h>
# include <stdlib.h>


void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void show(int arr[], int size);


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r -m;
    int L[n1], R[n2];

    for (i=0; i<n1; i++)
    {
        L[i] = arr[l+i];
    }
    for (j=0; j<n2; j++)
    {
        R[j] = arr[m+1+j];
    }

    i=0; j=0; k=l;
    while (i<n1 && j<n2)
    {
        if (L[i] <= R[j])   // >= if want sort in descending order
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
    
    while (i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l<r)
    {
        int m = l + (r-l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void show(int arr[], int size)
{
    int i;
    printf("-----------------------\n");
    for (i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("-----------------------\n");
}

int main(void)
{
    int i, n;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    while (getchar() != '\n' && getchar() != EOF)
        continue;
    int arr[n];
    printf("Enter integers into array:\n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (getchar() != '\n' && getchar() != EOF)
        continue;

    printf("Given array is:\n");
    show(arr, n);
    mergeSort(arr, 0, n-1);
    printf("After merge sort:\n");
    show(arr, n);

    return(0);
}