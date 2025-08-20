#include <iostream>
#define size 100
using namespace std;

int BinarySearch(int arr[], int low, int high, int key)
{
    if(low > high)
        return -1;
    
    int mid = (low + high) / 2;

    if(arr[mid] == key) 
        return mid;
    else if(arr[mid] < key) 
        return BinarySearch(arr, mid + 1, high, key);
    else 
        return BinarySearch(arr, low, mid - 1, key);
}

int main()
{
    int arr[size];
    int n, pos, key;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements in sorted order:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the key to search: ";
    cin >> key;

    pos = BinarySearch(arr, 0, n - 1, key);

    if(pos == -1)
        cout << "Key not found in the array.\n";
    else
        cout << "Key found at index " << pos << ".\n";

    return 0;
}
