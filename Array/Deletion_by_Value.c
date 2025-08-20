#include<stdio.h>

int main()
{
    int size, n, i, value, count;

    // Get the array size
    printf("Enter the size of array: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Array size must be greater than zero!.\n");
        return 1;  // Stop the program if size is zero
    }

    
    int arr[size];

    // Get the number of elements to fill in array
    printf("Enter the number of elements to fill in array: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Number of elements must be greater than zero!\n");
        return 1;
    }

    
    if(n <= size && n > 0)
    {
        // Input array elements
        for (i = 0; i < n; i++) 
        {
            printf("Enter array element %d: ", i+1);
            scanf("%d", &arr[i]);
        }

        // Get the value to delete
        printf("Enter the value you want to delete from the array: ");
        scanf("%d", &value);

        count = 0;  // Initialize count to zero

        // Traverse the array and find the value to delete
        for(i = 0; i < n; i++)
        {
            if(arr[i] == value)
            {
                // Shift elements to the left to fill the gap
                for(int j = i; j < n - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                
                // Decrement the number of elements and adjust index
                n--;
                 // Decrement i to check the new element at position i
                i--;
                count = 1;  // Mark that we found and deleted the element
            }
        }

        // If the value was not found
        if(count == 0)
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
                for(i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        }
    }
    else
    {
        printf("Invalid input! Either n is larger than size or zero.\n");
        return 1;
    }

    return 0;
}
