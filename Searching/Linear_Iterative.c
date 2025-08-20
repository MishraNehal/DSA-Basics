#include <stdio.h>
#define size 100

int main() {
    int arr[size];
    int n, key, position = -1;

    printf("Enter the number of elements (max %d): ", size);
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            position = i;
            break;
        }
    }

    if (position != -1)
        printf("Key %d found at position %d (index %d)\n", key, position + 1, position);
    else
        printf("Key %d not found in the array.\n", key);

    return 0;
}
