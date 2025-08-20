#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n) {
    vector<vector<float>> buckets(n);

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];  // index in bucket
        buckets[idx].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Concatenate all buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    cout << "Bucket Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
