#include <stdio.h>

int printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void InsertionSort(int arr[], int n)
{
    int key,j;
    // loop for passes
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        // loop for each pass
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int arr[] = {4, 3, 65, 76, 8};
    int n = 5;

    printArray(arr, n);
    InsertionSort(arr, n);
    printArray(arr, n);

    return 0;
}