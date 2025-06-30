🧠 Intuition
============

Naively, for each `sumRange(left, right)` query, we could loop from `left` to `right` and sum the elements.\
But that would take O(n) per query, which is too slow if there are many queries.

To optimize this, we use the Prefix Sum technique.

🚀 Approach
===========

Step 1: Preprocessing with Prefix Sum Array
-------------------------------------------

-   We create a `preSum` array such that:
    -   `preSum[i] = sum` of all elements from `nums[0]` to `nums[i]`.
-   We compute this once in the constructor in O(n) time.

Step 2: Answer Queries in O(1)
------------------------------

-   To get the sum of `nums[left...right]`, we use:
    -   If `left == 0`: `preSum[right]`
    -   Else: `preSum[right] - preSum[left - 1]`

This avoids recomputing sums repeatedly and makes each query constant time.

Complexity
==========

-   Time complexity: O(n)

-   Space complexity: O(n)

Code
====

```
class NumArray {
public:
    vector<int>& presum;
    NumArray(vector<int>& nums) : presum(nums) {
        for(int i = 1; i < presum.size(); i++)
            presum[i] += presum[i-1];
    }

    int sumRange(int left, int right) {
        if(left == 0) return presum[right];
        return presum[right] - presum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```

-   `preSum[i]` stores sum of first `i+1` elements.
-   Constructor precomputes all prefix sums in one pass.
-   `sumRange()` answers queries in constant time.