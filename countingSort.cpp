// used for chars 

# include <iostream>
# include <string.h>

using namespace std;

# define RANGE 255

// sort the given string arr[] in alphabetical order

void cSort(char arr[])
{
    // the output char arr
    char output[strlen(arr)];

    // create a count arr to store count of indiv char and initialize count arr to 0
    // can use memset to initialize to 0 as well
    int count[RANGE+1] = {0};
    int i;

    // store count for each char 
    for (i=0; arr[i]; i++)
    {
        count[arr[i]]++;
    }

    // store the cumulative count of each arr
    for (i=1; i<=RANGE; i++)
    {
        count[i] += count[i-1];
    }

    // build the output arr
    for (i=0; arr[i]; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // copy output arr to arr 
    for (i=0; arr[i]; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    char arr[] = "141341";
    cSort(arr);
    
    cout << "Sorted array is " << arr << endl;

    return(0);
}