// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n
#include <iostream>
#include <vector>
using namespace std;

void backtrack(int start, vector<int>& comb, vector<vector<int>>& res, int n, int k) {
    if (comb.size() == k) {
        res.push_back(comb);
        return;
    }

    for (int num = start; num <= n; num++) {
        comb.push_back(num);
        backtrack(num + 1, comb, res, n, k);
        comb.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> comb;
    backtrack(1, comb, res, n, k);
    return res;
}

int main() {
    int n, k;
    cout << "Enter n (upper limit): ";
    cin >> n;
    cout << "Enter k (combination size): ";
    cin >> k;

    vector<vector<int>> result = combine(n, k);

    cout << "Combinations of size " << k << " from 1 to " << n << ":\n";
    for (const auto& comb : result) {
        cout << "{ ";
        for (int num : comb)
            cout << num << " ";
        cout << "}\n";
    }

    return 0;
}
