#include<stdio.h>

int main()
{
    int size, n, i, pos;
    
    printf("Enter the size of array: ");
    scanf("%d", &size);
    if (size <= 0) 
    {
        printf("Array size must be greater than zero!\n");
        return 1;
    }

    
    int arr[size];
    
    printf("Enter the number of elements to fill in array: ");
    scanf("%d", &n);   
    if(n<=size )
    {
        for (i = 0; i < n; i++) 
        {
            printf("Enter array element %d: ", i+1);
            scanf("%d", &arr[i]);   
        }

        if (size !=0)
       {
            printf("Enter the position (0-based index) where you want to delete the value: ");
            scanf("%d", &pos);
    
        
            if (pos < 0 || pos >= size || pos >= n) 
            {
                printf("Invalid position or index no. given by you");
            }
            else 
            {
                int temp = arr[pos];

                for (i = pos; i <= size-1; i++) 
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
