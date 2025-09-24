#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int search) {            // Binary Search
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;                // finding middle index

        if (arr[mid] == search)                             // if equals to middle element, return
            return mid;
        else if (arr[mid] < search)                         // if greater than middle, shift mid to right
            left = mid + 1;
        else
            right = mid - 1;                                // if smaller, shift middle to left
    }

    return -1;                                      // not found
}


void insertionSort(int arr[], int n) {              // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {            // shift to right whatevers greater than key
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}


int main() {
    int n, search;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ":";
        cin >> arr[i];
    }

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    
    
    insertionSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    
    cout << "Enter value to search using binary search: ";
    cin >> search;

    
    int result = binarySearch(arr, n, search);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
