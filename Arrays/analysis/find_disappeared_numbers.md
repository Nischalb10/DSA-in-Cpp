# Find Disappeared Numbers - Problem Analysis

## 🧠 Problem Understanding

**Input:**  
Array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`

**Output:**  
Array of missing integers in the range `[1, n]`

### 🔒 Constraints

- `n == nums.length`
- `1 ≤ n ≤ 10⁵`
- `1 ≤ nums[i] ≤ n`

---

## 💡 Solution Approaches

---

### 1. ✅ Hash Set Approach (Current Implementation)

```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> set_nums(nums.begin(), nums.end());
    vector<int> ret;
    for (int i = 1; i <= nums.size(); i++) {
        if (set_nums.find(i) == set_nums.end())
            ret.push_back(i);
    }
    return ret;
}
```

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`
- **Pros:** Simple to implement, good readability
- **Cons:** Uses extra space

---

### 2. 🚀 In-Place Modification Approach (Optimal)

```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;

    // Step 1: Mark seen numbers by negating the number at their corresponding index
    for (int i = 0; i < nums.size(); i++) {
        int pos = abs(nums[i]) - 1;  // Convert value to index (1-based to 0-based)
        nums[pos] = -abs(nums[pos]); // Negate the value at index if not already negative
    }

    // Step 2: Find indices with positive numbers, those are the missing numbers
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1); // Convert index back to 1-based number
        }
    }

    return result;
}
```

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)` *(excluding output array)*
- **Pros:** No extra space needed
- **Cons:** Modifies input array

---
