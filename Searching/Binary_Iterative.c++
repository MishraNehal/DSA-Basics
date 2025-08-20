#include <iostream>
#define size 100
using namespace std;

int main() {
    int arr[size];
    int n, key, l, u, mid, pos = -1;

    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter " << n << " sorted elements:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    l = 0;
    u = n - 1;

    while (l <= u) 
    {
        mid = (l + u) / 2;

        if (arr[mid] == key) 
        {
            pos = mid;
            break;
        } 
        else if (arr[mid] < key) 
        {
            l = mid + 1;
        } 
        else 
        {
            u = mid - 1;
        }
    }

    if (pos != -1)
        cout << "Key " << key << " found at position " << pos + 1 << " (index " << pos << ")" << endl;
    else
        cout << "Key " << key << " not found in the array." << endl;

    return 0;
}
