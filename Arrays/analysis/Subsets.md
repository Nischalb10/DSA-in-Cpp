* * * * *

Approach
========

To create subsets, point is that we have two choices for each number.

* * * * *

⭐️ Points

-   Include current number
-   Not include current number

* * * * *

This picture is an example with input array `[1,2,3]`

![スクリーンショット 2024-04-30 1.56.40.png](https://assets.leetcode.com/users/images/91e72321-e214-49db-8a46-43d02db5103c_1714409832.6692474.png)

First of all, we have two choices for `1`. We can create two subsets.

```
[1] or []
```

Next, we have two choices for `2`. We need to think about each pattern (= `[1] or []`).

For `[1]` case, we can create subsets

```
[1,2] or [1]

[1,2] is including 2
[1] is not including 2
```

For `[]` case, we can create subsets

```
[2] or []

[2] is including 2
[] is not including 2
```

We have 4 subsets so far.

```
[1,2], [1], [2], []
```

We do the same thing about `3` with all the 4 patterns above. In the end, we can create and return

```
For [1,2],
[1,2,3]
[1,2]

For [1],
[1,3]
[1]

For [2],
[2,3]
[2]

For [],
[3]
[]
```

Complexity
==========

-   Time complexity: O(2n)\
    `n` is number of elements in the input array. We have two choices for each number. For examples, length of input array is `3(= n)`, output should be `2 * 2 * 2 = 8 subsets`.

-   Space complexity: O(2n)

```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        createSubset(nums, 0, res, subset);
        return res;
    }

    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        createSubset(nums, index + 1, res, subset);

        subset.pop_back();
        createSubset(nums, index + 1, res, subset);
    }
};
```

Step by Step Algorithm
----------------------

1.  Initialization:

    -   Initialize an empty list `res` to store the subsets.
    -   Initialize an empty list `subset` to temporarily store subsets during recursion.

    ```
    res = []
    subset = []
    ```

2.  Define Recursive Function:

    -   Define a recursive function `create_subset` that takes an index `i` as its parameter.
    -   If the index `i` reaches the length of the input list `nums`, add the current `subset` to the result `res`.
    -   Otherwise, for each element in `nums`, include it in the `subset` and recursively call `create_subset` with the next index (`i+1`).
    -   After the recursive call, remove the last element from the `subset` to backtrack, and recursively call `create_subset` with the same index (`i+1`).

    ```
    def create_subset(i):
        if i == len(nums):
            res.append(subset[:])
            return

        subset.append(nums[i])
        create_subset(i+1)

        subset.pop()
        create_subset(i+1)
    ```

3.  Initial Function Call:

    -   Call the `create_subset` function with the initial index `0`.

    ```
    create_subset(0)
    ```

4.  Return Result:

    -   Return the list `res` containing all subsets.

    ```
    return res
    ```

In summary, this algorithm recursively generates all possible subsets of the input list `nums`, using backtracking to explore all combinations. The subsets are stored in the `res` list and returned as the final result.