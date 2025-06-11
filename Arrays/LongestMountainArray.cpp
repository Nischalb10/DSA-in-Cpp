// You may recall that an array arr is a mountain array if and only if:

// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

// Example 1:

// Input: arr = [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
// Example 2:

// Input: arr = [2,2,2]
// Output: 0
// Explanation: There is no mountain.
 

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 104
 

// Follow up:

// Can you solve it using only one pass?
// Can you solve it in O(1) space?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestMountain(vector<int>& arr) {
    int n = arr.size();
        // 1. IDENTIFY PEAKS
        // 2. TRAVERSE BACKWARDS WHILE PREVIOUS ELEMENT -
        // - IS SMALLER THAT CURRENT (i.e. GO TO THE START ROOT OF THE MOUNTAIN)
        // 3. TRAVERSE FORWARD WHILE NEXT ELEMENT IS SMALLER THAN CURRENT 
        // (i.e. GO TO THE END ROOT OF THE MOUNTAIN)
        // 4 . ADD THEM TO CALCULATE THE MOUNTAIN LENGTH
    int max_length = 0;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            int start_root = i;
            int end_root = i;

            // Expand left
            while (start_root > 0 && arr[start_root] > arr[start_root - 1]) {
                start_root--;
            }

            // Expand right
            while (end_root < n - 1 && arr[end_root] > arr[end_root + 1]) {
                end_root++;
            }

            max_length = max(max_length, end_root - start_root + 1);
            i = end_root; // Skip processed elements
        }
    }

    return max_length;
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = longestMountain(arr);
    cout << "Length of the longest mountain is: " << result << endl;

    return 0;
}
