#include <stdio.h>
#include <stdlib.h>

// function to display elements of an array
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[ %d ]\n", arr[i]);
    }
}

int main(){

    int arr[100] = {34, 54, 65, 76, 87, 98};
    int size = 6;

    displayArray(arr, size);

    return 0;
}