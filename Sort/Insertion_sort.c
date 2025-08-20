#include <stdio.h>

int main () {
    int arr [100], n, i, j, key;

    printf ("Enter the size of array: ");
    scanf ("%d", &n);

    printf ("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf ("%d", &arr[i]);
    }

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr [j + 1] = arr[j];
            j = j - 1;
        }
        arr [j + 1] = key;
    }

    printf ("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf ("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
