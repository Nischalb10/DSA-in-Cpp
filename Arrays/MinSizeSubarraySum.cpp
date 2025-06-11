// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 

// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
 

// Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& arr) {
    int n = arr.size();
    int minLen = INT_MAX;
    int left = 0, sum = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= arr[left++];
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    int n, target;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    int result = minSubArrayLen(target, arr);
    cout << "Minimum size of subarray with sum >= " << target << " is: " << result << endl;

    return 0;
}
