# include <iostream>

using namespace std;

// get max value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i=1; i<n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }

    return mx;
}

// counting sort of arr[] 
// according to the digit represented by exp 
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i;
    int count[10] = {0};

    // store count of occurrences in count[]
    for (i=0; i<n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (i=1; i<10; i++)
    {
        count[i] += count[i-1];
    }

    // building the output arr
    for (i=n-1; i>=0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // copy arr
    for (i=0; i<n; i++)
    {
        arr[i] = output[i];
    }
}

void rSort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp=1; m/exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {34, 14, 23542, 13, 141, 24, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    rSort(arr, n);
    printArray(arr, n);
    printf("\n");

    return(0);
}