#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define size 1000

int partition(int a[], int low, int high) {
    int i, j, temp, key;
    key = a[low];
    i = low + 1;
    j = high;

    while (i <= j) {
        while (i <= high && a[i] < key) {
            i++;
        }
        while (a[j] > key) {
            j--;
        }
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int main() {
    clock_t start, end;
    int i, ch = 1, a[size], n;

    srand(time(NULL));

    while (ch) {
        printf("Enter no of elements: ");
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            a[i] = rand() % 1000;
        }

        printf("Elements in array are: ");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        double timetaken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Sorted array: ");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        printf("Time taken to sort the elements: %f seconds\n", timetaken);
        printf("Continue? (0/1): ");
        scanf("%d", &ch);
    }
    return 0;
}
