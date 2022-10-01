#include <stdio.h>

int printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void SelectionSort(int arr[], int n)
{
    printf("Running selection sort...\n");
    int indexOfMin, temp;

    for (int i = 0; i < n; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // swap arr[i] and arr[indexOfMin]
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main()
{

    int arr[] = {4, 3, 65, 76, 8};
    int n = 5;

    printArray(arr, n);
    SelectionSort(arr, n);
    printArray(arr, n);

    return 0;
}