#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {                             // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];                              // swap
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;                                    // sorted state
    }
}

int linearSearch(int arr[], int n, int search) {                // Linear Search
    for (int i = 0; i < n; i++) {
        if (arr[i] == search)
            return i;                                               
    }
    return -1;                                                  // not found
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

    bubbleSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    
    cout << "Enter search value: ";
    cin >> search;

    
    int result = linearSearch(arr, n, search);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
