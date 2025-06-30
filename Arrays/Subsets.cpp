// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.
#include <iostream>
#include <vector>
using namespace std;

// O(n * 2^n)
void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
    if (i == nums.size()) {
        allSubsets.push_back(ans);
        return;
    }

    // Include current element
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);

    // Backtrack and exclude current element
    ans.pop_back();
    getAllSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<vector<int>> result = subsets(nums);

    cout << "All subsets:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int val : subset)
            cout << val << " ";
        cout << "}\n";
    }

    return 0;
}
