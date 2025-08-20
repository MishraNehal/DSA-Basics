#include<stdio.h>

int main()
{
    int size, n, i,loc, value;
    
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the number of elements to fill in array: ");
    scanf("%d", &n);
    
    if (n <= size) 
    {
        for (i = 0; i < n; i++) 
        {
            printf("Enter array element %d: ", i+1);
            scanf("%d", &arr[i]);   
        }
        printf("Enter Location(1-based index) where you want to insert the value: ");
        scanf("%d", &loc);
        if (loc < 0 || loc > n + 1) 
        {
            printf("Invalid position!\n");
            return 1;  // Exit the program early if position is invalid
        }
        printf("Enter the value: ");
        scanf("%d", &value);
        if (loc <= n + 1 && n < size) 
        {
            for (i = n - 1; i >= loc; i--) {
                arr[i + 1] = arr[i];
            }
            
            arr[loc-1] = value;
            n++;
            
            printf("Updated array: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } 
        else 
        {
            printf("Invalid Location or no space left in the array!\n");
        }
        
    } 
    else 
    {
        printf("Array Overflow or Invalid Input!\n");
    }

    return 0;
}
