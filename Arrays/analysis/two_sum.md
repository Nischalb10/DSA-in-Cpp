# Two Sum - Problem Analysis

## 🧠 Problem Understanding

**Input:**
- Integer array `nums`
- Target integer `target`

**Output:**
- Array of two indices where corresponding elements sum to `target`

### 🔒 Constraints

- `2 ≤ nums.length ≤ 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `-10⁹ ≤ target ≤ 10⁹`
- Exactly one valid solution exists

---

## 💡 Solution Approaches

---

### 1. 🚫 Brute Force Approach

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}
```

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`
- **Pros:** Simple implementation  
- **Cons:** Inefficient for large inputs

---

### 2. ✅ Hash Map Approach (Optimal)

```cpp
vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> m; // value | index
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++){
        int first = nums[i];
        int second = target - first;
        if(m.find(second) != m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }
        m[first] = i;
    }
    return ans;
}
```

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`
- **Pros:** Single pass solution  
- **Cons:** Uses extra space

---

## 🔍 Two Sum - Follow-up Questions Analysis

---

### 1. 🔁 How to handle multiple valid solutions?

To handle multiple valid solutions, we can modify the code to return all possible pairs:

```cpp
vector<vector<int>> twoSumMultiple(vector<int>& nums, int target) {
    unordered_map<int, vector<int>> m; // value -> vector of indices
    vector<vector<int>> results;

    // Store all indices for each value
    for(int i = 0; i < nums.size(); i++) {
        m[nums[i]].push_back(i);
    }

    // Find all pairs
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(m.find(complement) != m.end()) {
            for(int j : m[complement]) {
                if(i != j) { // Avoid using same element twice
                    results.push_back({i, j});
                }
            }
        }
        // Remove current number to avoid duplicates
        m[nums[i]].clear();
    }
    return results;
}
```

---

### 2. 🔄 Can we optimize for sorted input?

Yes, we can use two pointers approach for sorted arrays with `O(n)` time and `O(1)` space:

```cpp
vector<int> twoSumSorted(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while(left < right) {
        int sum = nums[left] + nums[right];
        if(sum == target) {
            return {left, right};
        } else if(sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}
```
