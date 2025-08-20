#include<stdio.h>

int main()
{
    int size, n, i, loc;
    
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the number of elements to fill in array: ");
    scanf("%d", &n);
    if(n<=size && n > 0)
    {
        for (i = 0; i < n; i++) 
        {
            printf("Enter array element %d: ", i+1);
            scanf("%d", &arr[i]);   
        }

        if (n > 0)
       {
        printf("Enter the Location where you want to delete the value: ");
        scanf("%d", &loc);
    
        
        if (loc <= 0 || loc > size || loc > n ) 
        {
            printf("Invalid Location given by you");
        }
        else 
        {
            int temp = arr[loc-1];

            for (i = loc-1; i <= n - 1; i++) 
            {
                arr[i] = arr[i + 1];
            }
            
            n--;
            
            printf("Updated array: ");
            for (i = 0; i < n; i++) 
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } 
        
        }
        else
        {
            printf("Array is empty!\n");
        }
    
    }
    else
    {
        printf("Invalid Input!");

    }
  return 0;    
    
}
