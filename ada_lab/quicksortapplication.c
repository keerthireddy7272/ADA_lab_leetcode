#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function prototypes
void quicksort(int A[], int low, int high);
int partition(int A[], int low, int high);

int main()
{
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;

    while(1)
    {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                if(n > 15000) {
                    printf("\nNumber of elements exceeds maximum array size (15000).\n");
                    break;
                }
                printf("\nEnter array elements: ");
                for(i = 0; i < n; i++)
                {
                    scanf("%d", &a[i]);
                }
                start = clock();
                quicksort(a, 0, n - 1);
                end = clock();
                printf("\nSorted array is: ");
                for(i = 0; i < n; i++)
                    printf("%d\t", a[i]);
                printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                break;

            case 2:
                n = 500;
                while(n <= 14500)
                {
                    for(i = 0; i < n; i++)
                    {
                        // For random numbers, you could use:
                        // a[i] = rand() % 1000;
                        a[i] = n - i;
                    }
                    start = clock();
                    quicksort(a, 0, n - 1);
                    // Dummy loop to create delay
                    for(j = 0; j < 500000; j++)
                    {
                        temp = 38 / 600;
                    }
                    end = clock();
                    printf("\nTime taken to sort %d numbers is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                    n = n + 1000;
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        // Clear input buffer to remove any extra characters
        while(getchar() != '\n');
    }

    return 0;
}

void quicksort(int A[], int low, int high)
{
    if(low < high)
    {
        int partitionIndex = partition(A, low, high);
        quicksort(A, low, partitionIndex - 1);
        quicksort(A, partitionIndex + 1, high);
    }
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;

    do {
        while(i <= high && A[i] <= pivot)
            i++;
        while(j >= low && A[j] > pivot)
            j--;
        if(i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while(i < j);

    // Place pivot in its correct sorted position
    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
