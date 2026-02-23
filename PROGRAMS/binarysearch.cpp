#include <iostream>
using namespace std;

// Iterative binary search function
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // prevent overflow
        if (arr[mid] == target)
            return mid;        // element found
        else if (arr[mid] < target)
            low = mid + 1;    // search right half
        else
            high = mid - 1;   // search left half
    }
    return -1; // element not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter number to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}