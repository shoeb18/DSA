#include <stdio.h>
#include <stdlib.h>

// binary search --> work only in sorted arrays
// time complexity --> O(log n)

void binarySearch(int arr[],int size, int element)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low<=high)
    {
        mid = (high + low) / 2;

        if (arr[mid]==element){
            printf("%d found at index %d\n", element, mid);
            return;
        }
        else if (arr[mid]<element)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

    }
    printf("element not found\n");
}



int main(){

    int arr[] = {34, 54, 65, 76, 87, 98};
    int size = sizeof(arr) / sizeof(int);

    binarySearch(arr, size, 77);

    return 0;
}