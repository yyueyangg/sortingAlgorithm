/*
easiest sorting algorithm 
swaps the adjacent elements if they are in the wrong order 
largest element is moved to the most right first 
same for second largest and so on..

Advantages;
easy to understand

Disadvantages:
not suitable for large data sets due to slow efficiency, time complexity O(N^2)
*/


# include <stdio.h>
# include <ctype.h>

int menu(void);
void bbsortasc(void);
void bbsortdsc(void);

int menu(void)
{
    int ch;
    printf("A) Bubble sort integers in ascending order\n");
    printf("B) Bubble sort integers in descending order\n");
    printf("Q) Quit\n");
    ch = getchar();
    while (getchar() != '\n' && getchar() != EOF)
        continue;
    return (toupper(ch));
}

// bubble sort in ascending order 
void bbsortasc(void)
{
    int n, i, inner, outer, temp;
    printf("Enter the number of integers to sort:\n");
    scanf("%d", &n);
    while (getchar() != '\n' && getchar() != EOF)
        continue;

    if (n>=1)
    {
        int num[n];

        printf("Enter the numbers to be sorted:\n");
        for (i=0; i<n; i++)
        {
            scanf("%d", &num[i]);
            while (getchar() != '\n' && getchar() != EOF)
                continue;
        }

        printf("Numbers before sorting:\n");
        for (i=0; i<n; i++)
            printf("%d ", num[i]);
        printf("\n");

        for (outer=0; outer<n-1; outer++)
        {
            for (inner=outer+1; inner<n; inner++)
            {
                if(num[outer] > num[inner])
                {
                    temp = num[outer];
                    num[outer] = num[inner];
                    num[inner] = temp;
                }
            }
        }

        printf("Numbers after sorting:\n");
        for (i=0; i<n; i++)
            printf("%d ", num[i]);
        printf("\n");
    }

    else 
    {
        printf("Invalid\n");
        return;
    }
}

// sort in descending order, almost everything same as bbsortasc
void bbsortdsc(void)
{
    int n, i, inner, outer, temp;
    printf("Enter the number of integers to sort:\n");
    scanf("%d", &n);
    while (getchar() != '\n' && getchar() != EOF)
        continue;
    if (n>=1)
    {
        int num[n];
        printf("Enter the numbers to be sorted:\n");
        for (i=0; i<n; i++)
        {
            scanf("%d", &num[i]);
            while (getchar() != '\n' && getchar() != EOF)
                continue;
        }

        printf("Numbers before sorting:\n");
        for (i=0; i<n; i++)
            printf("%d ", num[i]);
        printf("\n");

        for (outer=0; outer<n-1; outer++)
        {
            for (inner=outer+1; inner<n; inner++)
            {
                if(num[outer] < num[inner])
                {
                    temp = num[outer];
                    num[outer] = num[inner];
                    num[inner] = temp;
                }
            }
        }

        printf("Numbers after sorting:\n");
        for (i=0; i<n; i++)
            printf("%d ", num[i]);
        printf("\n");
    }

    else 
    {
        printf("Invalid\n");
        return;
    }
}

int main()
{
    int choice = '\0';
    printf("Sorting...\n");
    while (choice != 'Q')
    {
        choice = menu();
        switch(choice)
        {
            case 'A':
                bbsortasc();
                break;
            case 'B':
                bbsortdsc();
                break;
            case 'Q':
                break;
        }
    }
    return(0);
}