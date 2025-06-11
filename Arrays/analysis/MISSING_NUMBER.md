
#  Missing Number

## 📘 Problem Statement

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the **only number** in the range that is **missing** from the array.

> **Constraints:**
> - `n == nums.length`
> - `0 <= nums[i] <= n`
> - All numbers of the range `[0, n]` are present in `nums` except one.

---

## 🔍 Step-by-Step Problem Solving Process

### ✅ 1. Understand the Problem
- Array of size `n` contains numbers from `0` to `n` (inclusive), missing one number.
- Exactly one number is missing — find and return it.
- No duplicates, all elements are unique and in the valid range.

---

### 🧪 2. Explore Approaches

#### 🧠 Idea 1: Use Sum Formula

Sum of first `n` natural numbers is `n * (n + 1) / 2`.  
Subtract actual sum of array from this to get the missing number.

```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2;
    int actualSum = accumulate(nums.begin(), nums.end(), 0);
    return expectedSum - actualSum;
}
```

- ✅ Time: O(n)
- ✅ Space: O(1)

---

#### ⚡ Idea 2: Use XOR Trick

Let:
- `xor1` be XOR of all elements in nums
- `xor2` be XOR of all numbers from 0 to n

The missing number will be: `xor1 ^ xor2`

```cpp
int missingNumber(vector<int>& nums) {
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        xor1 ^= nums[i];
        xor2 ^= i;
    }
    xor2 ^= nums.size();
    return xor1 ^ xor2;
}
```

- ✅ Time: O(n)
- ✅ Space: O(1)

---

#### ❌ Idea 3: Sorting (Not optimal)

Sort the array and compare index with value.  
Less efficient due to sorting overhead.

```cpp
int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i) return i;
    }
    return nums.size();
}
```

- ❌ Time: O(n log n)
- ✅ Space: O(1)

---

## 🧠 Visual Explanation (ASCII Diagram)

### Example: `nums = [3, 0, 1]`

```
Expected range = [0, 1, 2, 3]
Sum = 0 + 1 + 2 + 3 = 6
Actual sum = 3 + 0 + 1 = 4
Missing = 6 - 4 = 2 ✅
```

---

## 📊 Time and Space Complexity

| Approach         | Time       | Space      | Notes                              |
|------------------|------------|------------|------------------------------------|
| Sum Formula      | O(n)       | O(1)       | ✅ Clean and optimal                |
| XOR Trick        | O(n)       | O(1)       | ✅ Clever and efficient             |
| Sorting          | O(n log n) | O(1)       | ❌ Less efficient due to sorting   |

---

## 📌 Best Practices Followed

- ✅ Multiple approaches explored
- ✅ Used mathematical and bitwise logic
- ✅ Optimized for time and space
- ✅ Included clear examples and edge cases

---

## 🧪 Sample Test Cases

| Input            | Output |
|------------------|--------|
| `[3,0,1]`         | 2      |
| `[0,1]`           | 2      |
| `[9,6,4,2,3,5,7,0,1]` | 8  |

---

## 🧾 Summary

Use the **Sum Formula** or **XOR trick** to efficiently find the missing number in O(n) time and O(1) space.

> 💬 “Sometimes the best solutions are the ones that use math or bitwise logic.”
