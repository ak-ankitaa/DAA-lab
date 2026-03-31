#include <iostream>
using namespace std;

void subsetSum(int arr[], int n, int index, int sum, int target) {
    if (sum == target) {
        cout << "Subset found\n";
        return;
    }

    if (index == n || sum > target)
        return;

    // Include current element
    subsetSum(arr, n, index + 1, sum + arr[index], target);

    // Exclude current element
    subsetSum(arr, n, index + 1, sum, target);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6;
    int target = 9;

    subsetSum(arr, n, 0, 0, target);
}
