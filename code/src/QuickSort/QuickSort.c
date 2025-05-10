#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    /* Chosing the last element as the pivot */
    int mid = (low + (high - low) / 2);
    int pivot = 0;

    /* Move the pivot element to the end */
    swap(&arr[pivot], &arr[high]);
    pivot = arr[high];

    /* Index of the smaller element */
    int i = (low - 1);

    for(int j = low; j < high; j++)
    {
        /* If the current element is smaller than or equal to the pivot */
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    /* Swap the pivor t element to its correct position */
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}