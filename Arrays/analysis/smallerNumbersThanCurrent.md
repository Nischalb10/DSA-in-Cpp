## 📘 Problem Statement

Given an array `nums`, return an array `result` such that `result[i]` is the number of elements in `nums` that are **strictly smaller than `nums[i]`**.

### 🧾 Input:
- `nums`: vector of integers where `0 <= nums[i] <= 100`

### 🎯 Output:
- A new vector of integers where each element is the count of numbers smaller than the corresponding element in `nums`.

---

## 🔒 Constraints

- `2 <= nums.length <= 500`
- `0 <= nums[i] <= 100`

---

## 🧪 Example

### Input:
```cpp
nums = [8, 1, 2, 2, 3]

### Output:

cpp

Copy

Download

[4, 0, 1, 1, 3]

**Explanation:**

-   4 numbers are smaller than 8: [1, 2, 2, 3]

-   0 numbers are smaller than 1

-   1 number is smaller than 2: [1]

-   1 number is smaller than 2: [1]

-   3 numbers are smaller than 3: [1, 2, 2]

* * * * *

🧩 Approach 1: Brute Force (O(n²))
----------------------------------

cpp

Copy

Download

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] < nums[i]) {
                count++;
            }
        }
        res[i] = count;
    }
    return res;
}

### ✅ Pros:

-   Simple to understand and implement.

### ❌ Cons:

-   Inefficient for large inputs (nested loop).

### ⏱️ Time Complexity:

-   O(n²)

* * * * *

⚡ Approach 2: Optimized Using Counting Sort (O(n))
--------------------------------------------------

cpp

Copy

Download

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> count(101, 0);

    // Step 1: Count frequencies
    for (int num : nums) {
        count[num]++;
    }

    // Step 2: Prefix sum to accumulate counts
    for (int i = 1; i < 101; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Build the result using prefix sums
    vector<int> result;
    for (int num : nums) {
        result.push_back(num == 0 ? 0 : count[num - 1]);
    }

    return result;
}

### ✅ Pros:

-   O(n) time --- extremely efficient due to small fixed range [0, 100]

-   No sorting needed

### ❌ Cons:

-   Slightly more logic to understand (prefix sum step)

-   Assumes fixed value range --- not generalizable to larger or unbounded ranges

### ⏱️ Time Complexity:

-   O(n + k) → O(n), where k = 101 (max value of nums[i])

### 🗂️ Space Complexity:

-   O(1) extra space (excluding output), as 101 is a constant

* * * * *

🔍 Why This Works
-----------------

The key idea is to count how many times each number appears and then compute a prefix sum. This gives, for any number x, the count of how many numbers are strictly less than x in constant time.

**Prefix Sum Intuition:**

-   If `count[i]` is how many times `i` appeared, then after prefix sum, `count[i]` becomes: how many numbers are ≤ `i`.

-   For `num = x`, `count[x - 1]` = how many numbers are < `x`.

* * * * *

✅ Summary
---------

| Approach | Time Complexity | Space Complexity | Notes |
| --- | --- | --- | --- |
| Brute Force | O(n²) | O(1) | Simple but slow |
| Counting Sort Logic | O(n) | O(1) | Fast and optimal for small k |

* * * * *

📌 Final Thoughts
-----------------

This problem is a great example of:

-   Using constraints to guide algorithm choice (range-based counting)

-   Optimizing time using frequency + prefix sum

-   Trade-offs between generality and efficiency