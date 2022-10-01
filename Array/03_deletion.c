#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

// delete an element at index
void deleteAtIndex(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{

    int arr[100] = {1, 3, 5, 7, 9, 11, 13};
    int size = 7;

    printf("Array before deletion :\n");
    printArray(arr, size);

    deleteAtIndex(arr, size, 4);
    size--;

    printf("Array after deletion :\n");
    printArray(arr, size);

    return 0;
}