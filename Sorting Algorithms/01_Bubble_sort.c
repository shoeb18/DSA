#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void BubbleSort(int arr[], int n)
{
    int temp;
    int isSorted = 0;

    for (int i = 0; i < n - 1; i++) // no of passes
    {
        printf("working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - i - 1; j++) // no of comparisons in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                isSorted = 0;
            }
        }
        if (isSorted){
            return;
        }
    }
}

int main()
{

    int arr[] = {5, 6, 7, 12, 3, 54, 15};
    // int arr[] = {5, 7, 12, 13, 54, 150,444};
    int n = 7;

    printArray(arr, n); // printing array before sorting
    BubbleSort(arr, n); // function for sorting array
    printArray(arr, n); // printing array after sorting

    return 0;
}