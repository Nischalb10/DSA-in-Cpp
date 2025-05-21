// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:

// Input: nums = [1,1]
// Output: [2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
 

// Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> set_nums(nums.begin(),nums.end());
    vector<int> ret;
    for(int i =1;i<=nums.size();i++){
        if(set_nums.find(i) == set_nums.end())//find function returns end iterator if value is missing
            ret.push_back(i);
    }
    return ret;
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> missing = findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    for (int num : missing) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}