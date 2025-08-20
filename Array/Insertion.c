#include<stdio.h>

int main()
{
    int size, n, i, pos, value;
    
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the number of elements to fill in array: ");
    scanf("%d", &n);
    
    if (n <= size) {
        for (i = 0; i < n; i++) {
            printf("Enter array element %d: ", i+1);
            scanf("%d", &arr[i]);   
        }
        printf("Enter the position (0-based index) where you want to insert the value: ");
        scanf("%d", &pos);
        
        if (pos < 0 || pos > n) {
            printf("Invalid position!\n");
            return 1;  // Exit the program early if position is invalid
        }
        
        printf("Enter the value: ");
        scanf("%d", &value);
        if (pos <= n && n < size) 
        {
            for (i = n - 1; i >= pos; i--) {
                arr[i + 1] = arr[i];
            }
            
            arr[pos] = value;
            n++;
            
            printf("Updated array: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } 
        else 
        {
            printf("Invalid position or no space left in the array!\n");
        }
        
    } 
    else 
    {
        printf("Array Overflow or Invalid Input!\n");
    }

    return 0;
}
