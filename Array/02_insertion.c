#include <stdio.h>
#include <stdlib.h>

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

// insert element at index
void insertAtIndex(int arr[], int size, int capacity, int index, int element)
{
    if (size>=capacity){
        return;
    }
    
    for (int i = size-1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
}


int main(){

    int arr[100] = {34, 23, 322, 433, 544};
    int size = 5;

    printf("Array before Insertion\n");
    displayArray(arr, size);

    insertAtIndex(arr, size, 100, 3, 98);
    size++;

    printf("Array after Insertion\n");
    displayArray(arr, size);

    return 0;
}