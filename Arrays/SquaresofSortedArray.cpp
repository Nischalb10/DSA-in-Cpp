// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.
 

// Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
#include <iostream>
#include <vector>
#include <deque>
#include <cmath> // for abs()

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    deque<int> ans;
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int left = abs(nums[l]);
        int right = abs(nums[r]);
        if (left > right) {
            ans.push_front(left * left);
            l++;
        } else {
            ans.push_front(right * right);
            r--;
        }
    }

    return vector<int>(ans.begin(), ans.end());
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements (sorted, may contain negatives): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = sortedSquares(nums);

    cout << "Sorted squares: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
