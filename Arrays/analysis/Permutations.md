Approach
========

This is based on Python solution. Other might be different a bit.

1.  The function `permute` takes a list of integers `nums` as input and aims to generate all possible permutations of the elements in the input list.

2.  The base case is checked: if the length of the `nums` list is 1, then it means there's only one element left to permute, and at this point, a list containing that single element is returned as a permutation.

3.  If the `nums` list has more than one element, the algorithm proceeds with permutation generation.

4.  Initialize an empty list `res` to store the permutations.

5.  Iterate over each element in the `nums` list (using `_` as a placeholder for the loop variable). In each iteration, pop the first element `n` from the `nums` list.

6.  Recursively call the `permute` function on the remaining elements in `nums` after removing the first element. This generates all possible permutations of the remaining elements.

7.  For each permutation `p` generated in the recursive call, append the previously removed element `n` to it.

8.  Extend the `res` list with the permutations generated in the recursive calls, each with the element `n` appended.

9.  After the loop completes, add the removed element `n` back to the end of the `nums` list, restoring the original state for the next iteration.

10. Finally, return the list `res` containing all the generated permutations.

In summary, this code uses a recursive approach to generate all possible permutations of the input list `nums`. It removes one element at a time, generates permutations for the remaining elements, appends the removed element to those permutations, and collects all permutations in the `res` list. The recursion continues until only one element is left in the list, at which point a permutation containing that single element is returned.

Complexity
==========

-   Time complexity: O(n * n!)

    -   Recursive Calls: The permute function is called recursively, and each time it generates permutations for a smaller list by removing one element. In the worst case, the recursion depth is equal to the length of the input list nums, which is n.

    -   Permutation Generation: For each index, we are generating permutations for the remaining elements and appending the removed element at the end. This involves recursive calls and list manipulations. In general time complexity of permutation should be O(n!)

-   Space complexity: O(n)

    -   Recursion Depth: The depth of recursion goes up to the number of elements in the input list. So, the maximum recursion depth is O(n).

    -   Additional Memory: The additional memory usage includes the res list, the n variable, and the space used in each recursive call.

        Considering these factors, the space complexity is O(n)

```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 1) {
            vector<int> singleList;
            singleList.push_back(nums[0]);
            res.push_back(singleList);
            return res;
        }

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            vector<int> remainingNums;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    remainingNums.push_back(nums[j]);
                }
            }

            vector<vector<int>> perms = permute(remainingNums);
            for (vector<int> p : perms) {
                p.insert(p.begin(), n);  // Insert n at the beginning of the permutation
                res.push_back(p);  // Append the modified permutation to the result
            }
        }

        return res;
    }
};
```

-   This is bonus codes I don't explain in the article.

```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
```

`\
`