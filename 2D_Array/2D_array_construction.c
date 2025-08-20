#include <stdio.h>

int main() {
    int rows, cols, r, c, choice, value;

    // Get dimensions
    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input! Rows must be positive.\n");
        return 1;
    }

    printf("Enter number of columns: ");
    if (scanf("%d", &cols) != 1 || cols <= 0) {
        printf("Invalid input! Columns must be positive.\n");
        return 1;
    }

    int arr[rows][cols];

    // Input matrix elements
    printf("Enter elements of the %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at [%d][%d]: ", i, j);
            if (scanf("%d", &arr[i][j]) != 1) {
                printf("Invalid input!\n");
                return 1;
            }
        }
    }

    // Menu
    printf("\nChoose operation:\n1. Insert value\n2. Delete value\n");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (choice == 1) {
        // Insertion
        printf("Enter row (0-%d) and column (0-%d) to insert: ", rows - 1, cols - 1);
        if (scanf("%d %d", &r, &c) != 2 || r < 0 || r >= rows || c < 0 || c >= cols) {
            printf("Invalid position!\n");
            return 1;
        }

        printf("Enter value: ");
        if (scanf("%d", &value) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        arr[r][c] = value;

        printf("\nMatrix after insertion:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    else if (choice == 2) {
        // Deletion (replace with 0 to mark as "deleted")
        printf("Enter row (0-%d) and column (0-%d) to delete: ", rows - 1, cols - 1);
        if (scanf("%d %d", &r, &c) != 2 || r < 0 || r >= rows || c < 0 || c >= cols) {
            printf("Invalid position!\n");
            return 1;
        }

        arr[r][c] = 0;  // Mark as deleted (could also use special flag)

        printf("\nMatrix after deletion:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
