#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = (mid - left + 1); 
    int n2 = (right - mid);

    /* Define local arrays and copy data */
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    /* Merge the temporary arrays back into arr[] */
    int i = 0, j = 0, k = left;
    while((i < n1) && (j < n2))
    {
        if (L[i] <= R[j])
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

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, (mid + 1), right);
        merge(arr, left, mid, right);
    }
}

