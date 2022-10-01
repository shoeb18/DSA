#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

// linear search --> work on sorted & unsorted array
// time complexity --> O(n)
void linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element){
            printf("%d found at %d index\n", arr[i], i);
            return;
        }
    }
    printf("element not found\n");
}

int main(){

    int arr[] = {1, 4, 5, 4, 65, 76, 87, 56, 34, 90};
    int size = sizeof(arr) / sizeof(int);

    linearSearch(arr, size, 54);

    return 0;
}