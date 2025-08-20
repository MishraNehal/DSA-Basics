#include<stdio.h>

int main()
{
    int size, n, i, pos, value, count;
    
    // Get the array size
    printf("Enter the size of array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid input! Array size must be a positive integer.\n");
        return 1;  // Stop the program if size is zero or invalid
    }

    int arr[size];

    // Get the number of elements to fill in array
    printf("Enter the number of elements to fill in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Number of elements must be a positive integer.\n");
        return 1;
    }

    if (n <= size && n > 0)
    {
        // Input array elements
        for (i = 0; i < n; i++) 
        {
            printf("Enter array element %d: ", i + 1);
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input! Please enter an integer.\n");
                return 1;
            }
        }

        // Menu for insertion or deletion
        int choice;
        printf("Choose an operation:\n1. Insert a value\n2. Delete a value\n");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            return 1;
        }

        if (choice == 1) 
        {
            // Insertion
            printf("Enter the position (0-based index) where you want to insert the value: ");
            if (scanf("%d", &pos) != 1 || pos < 0 || pos > n) 
            {
                printf("Invalid position!\n");
                return 1;  // Exit the program early if position is invalid
            }
            
            printf("Enter the value: ");
            if (scanf("%d", &value) != 1) {
                printf("Invalid input! Please enter an integer.\n");
                return 1;
            }
            
            if (pos <= n && n < size) 
            {
                for (i = n - 1; i >= pos; i--) 
                {
                    arr[i + 1] = arr[i];
                }

                arr[pos] = value;
                n++;

                printf("Updated array: ");
                for (i = 0; i < n; i++) 
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            } 
            else 
            {
                printf("Invalid position or no space left in the array!\n");
            }
        } 
        else if (choice == 2) 
        {
            // Deletion
            printf("Enter the value you want to delete from the array: ");
            if (scanf("%d", &value) != 1) {
                printf("Invalid input! Please enter an integer.\n");
                return 1;
            }

            count = 0;  // Initialize count to zero

            // Traverse the array and find the value to delete
            for (i = 0; i < n; i++) 
            {
                if (arr[i] == value) 
                {
                    // Shift elements to the left to fill the gap
                    for (int j = i; j < n - 1; j++) 
                    {
                        arr[j] = arr[j + 1];
                    }

                    // Decrement the number of elements and adjust index
                    n--;
                    i--; // Decrement i to check the new element at position i
                    count = 1;  // Mark that we found and deleted the element
                }
            }

            // If the value was not found
            if (count == 0) 
            {
                printf("Value not found!\n");
            } 
            else 
            {
                if (n == 0) 
                {
                    printf("Array after deletion is empty.\n");
                } 
                else 
                {
                    printf("Array after deletion:\n");
                    for (i = 0; i < n; i++) 
                    {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
            }
        } 
        else 
        {
            printf("Invalid choice!\n");
        }
    } 
    else 
    {
        printf("Invalid input! Either n is larger than size or zero.\n");
        return 1;
    }

    return 0;
}