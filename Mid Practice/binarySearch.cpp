#include <iostream>
using namespace std;

void binarySearch(int arr[], int size, int val) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == val) {
            cout << "Element found at index: " << mid << endl;
            return;
        } else if (arr[mid] < val) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Element not found." << endl;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    binarySearch(arr, size, 10);  // → Element found at index: 4
    binarySearch(arr, size, 5);   // → Element not found
}
