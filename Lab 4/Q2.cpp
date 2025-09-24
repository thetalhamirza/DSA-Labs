#include <iostream>
using namespace std;


void selectionSort(int arr[], int n) {                                  // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        
        int temp = arr[minIndex];                                       // swap
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}


int interpolationSearch(int arr[], int n, int search) {                 // Interpolation Search
    int low = 0, high = n - 1;

    while (low <= high && search >= arr[low] && search <= arr[high]) {
        
        if (arr[high] == arr[low]) {                                    // Avoiding division by zero
            if (arr[low] == search)
                return low;                                             // return first match
            else
                return -1;
        }

        
        int pos = low + ((double)(search - arr[low]) * (high - low)) / (arr[high] - arr[low]);          // Estimating position

        if (pos < low || pos > high)            // range check
            return -1;

        if (arr[pos] == search)
            return pos;                         // returns index
        else if (arr[pos] < search)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;                                  // Not found
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

    cout << "Unsorted: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;    
    
    selectionSort(arr, n);
    
    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    

    cout << "Enter value to search: ";
    cin >> search;
    
    int result = interpolationSearch(arr, n, search);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
