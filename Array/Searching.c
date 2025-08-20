#include<stdio.h>
int main()
{
    int size,n,i,key,count;
    printf("Enter the size of array:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the no. of terms that should be filled in array:");
    scanf("%d",&n);

    if(n<=size)
    {
        for(i=0;i<=n-1;i++)
        {
            printf("Enter your array data:");
            scanf("%d",&arr[i]);   
        }
         printf("Enter the value that you want to search:");
        scanf("%d",&key);
        count = 0;
        for(i=0; i<n; i++ )
        {
            if(arr[i] == key)
            {
                printf("Value Found at index!\n");
                printf("%d\n",i);
                count=1;

            }
        }
        if(count==0)
        {
            printf("Value not Found!");
        } 
        
    }
    else
    {
        printf("Invalid Input!");
    }
   

    return 0;
}