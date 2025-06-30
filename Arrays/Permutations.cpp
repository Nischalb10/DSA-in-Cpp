// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());  // Ensure we start from the first permutation
    do {
        ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<vector<int>> result = permute(nums);

    cout << "All permutations:\n";
    for (const auto& perm : result) {
        cout << "{ ";
        for (int val : perm)
            cout << val << " ";
        cout << "}\n";
    }

    return 0;
}
