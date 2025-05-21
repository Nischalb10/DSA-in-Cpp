
# 🧠 LeetCode Problem: Contains Duplicate

## 📘 Problem Statement

Given an integer array `nums`, return `true` if any value appears **at least twice**, and return `false` if every element is **distinct**.

> **Constraints:**
> - `1 <= nums.length <= 10⁵`
> - `-10⁹ <= nums[i] <= 10⁹`

---

## 🔍 Step-by-Step Problem Solving Process

### ✅ 1. Understand the Problem
- Read the problem twice.
- Ask yourself:
  - Are negative numbers allowed? → Yes.
  - Can the array be empty? → Yes, but return `false`.
  - Do we care about frequency or just the existence of duplicates? → Just existence.

---

### 🧪 2. Explore Brute Force and Alternatives

#### ❌ Brute Force (O(n²))
```cpp
for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] == nums[j]) return true;
    }
}
return false;
```

Too slow for large inputs.

---

### ✅ 3. Optimal Solutions

#### 🔁 Sorting (O(n log n), O(1) space)
```cpp
sort(nums.begin(), nums.end());
for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == nums[i - 1]) return true;
}
return false;
```

#### ⚡ Using a Set (O(n) Time, O(n) Space)
```cpp
#include <unordered_set>

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}
```

#### 🔁 Bonus: One-liner with set size comparison
```cpp
bool containsDuplicate(vector<int>& nums) {
    return unordered_set<int>(nums.begin(), nums.end()).size() != nums.size();
}
```

---

## 🧠 Visual Explanation (ASCII Diagram)

### Example: `nums = [1, 2, 3, 2]`

```
Step-by-step using set:
Seen Set: {}

1 → not in set → insert → {1}
2 → not in set → insert → {1, 2}
3 → not in set → insert → {1, 2, 3}
2 → already in set → return true ✅
```

---

## 📊 Time and Space Complexity

| Approach      | Time       | Space      | Notes                          |
|---------------|------------|------------|--------------------------------|
| Brute Force   | O(n²)      | O(1)       | Inefficient                    |
| Sorting       | O(n log n) | O(1)/O(n)  | No extra space if in-place     |
| Set-Based     | O(n)       | O(n)       | ✅ Fastest and easiest to code |

---

## 📌 Best Practices Followed

- ✅ Read the problem multiple times
- ✅ Explored multiple approaches
- ✅ Considered time and space trade-offs
- ✅ Thought E2E before coding
- ✅ Tried improving after finishing
- ✅ Reviewed and learned from other solutions

---

## 🔚 Summary

Use a `set` to detect duplicates in one pass. It's efficient and clean.

> 💬 “Think E2E, draw patterns, write clearly, and always improve.”

---

## 🧪 Sample Test Cases

| Input              | Output |
|--------------------|--------|
| `[1,2,3,4]`         | false  |
| `[1,2,3,1]`         | true   |
| `[0]`              | false  |
| `[-1, -2, -3, -1]` | true   |
