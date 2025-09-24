#include <iostream>
using namespace std;

// void interpolationSearch(int arr[], int size, int val)  {
//     int low = 0, high = size-1;

//     while (low <= high && val >= arr[low] && val <= arr[high]) {
//         if (low == high) {
//             if (arr[low] == val) {
//                 cout << low;
//                 return;
//             }
//         }

//         int pos = low + ((double)(val - arr[low]) * (high - low)) / (arr[high] - arr[low]);

//         if (arr[pos] < val) {
//             low = pos+1;
//         }   else    {
//             high = pos - 1;
//         }

//     }
//     cout << "Not found" << endl;
//     return;
// }


void interpolation(int arr[], int size, int val) {

    int low = 0, high = size - 1;

    while (low <= high && val >= arr[low] && val <= arr[high]) {
        if (low == high)    {
            if (arr[low] == val)    {
                cout << low;
                return;
            }
        }

        int pos = low + ((double)(val - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] < val) {
            low = pos + 1;
        }   else {
            high = pos - 1;
        ]
    }
    cout << "Not found" << endl;

    return;
}