#include<stdio.h>
int main()
{
    int size,n,i;
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
        
    }
    else
    {
        printf("Array Overflow or Invalid Input!");
    }
    return 0;
}