#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;

    // Traverse through all array elements
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIdx != i) {
            temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12 , 15 , 56 ,34 , 68 , 1 , 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
