#include <iostream>
#define size 100
using namespace std;

int main() {
    int arr[size];
    int n, key, position = -1;

    cout << "Enter the number of elements (max " << size << "): ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            position = i;
            break;
        }
    }

    if (position != -1)
        cout << "Key " << key << " found at position " << position + 1 << " (index " << position << ")" << endl;
    else
        cout << "Key " << key << " not found in the array." << endl;

    return 0;
}
