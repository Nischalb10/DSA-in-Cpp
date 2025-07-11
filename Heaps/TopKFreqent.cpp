// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
 

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> hash;
        for (int i : nums) {
            hash[i]++;
        }
        priority_queue<pair<int,int>> heaper;
        for(auto i : hash) {
            heaper.push({i.second,i.first});
        }
        hash.clear();
        while(k > 0 && !heaper.empty()) {
            res.push_back(heaper.top().second);
            heaper.pop();
            k--;
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
