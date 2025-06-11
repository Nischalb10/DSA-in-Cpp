Solution 1 - HashMap
====================

In solution 1, we use `HashMap`.

### What data should we keep with the HashMap?

Of course, we should have numbers we already saw in the loop. Let's keep the numbers as a key for `HashMap`.

Do you guess what data is for values of `HashMap`?

...😩

...😅

...😃!

* * * * *

⭐️ Points

My strategy is to keep track of the latest index at which each number appears, which I'll call index `j`. This index represents the closest position for that number from the current index.

This approach works because we need to find duplicate numbers within a distance of `k` from the current index `i`, so the closer the previous index `j` is to the current index i, the more likely we are to find an answer.

* * * * *

### How it works

Let's see this example.

```
Input: nums = [1,0,1,1], k = 1

seen = {}
```

First of all, we don't have numbers in `HashMap`. Just add a current number and index to `seen`.

```
seen = {1: 0}
```

Next

```
[1,0,1,1]
   i
```

We don't have `0` in `seen`, so just add `0` and index `1` to `seen`.

```
seen = {1: 0, 0: 1}
```

Next

```
[1,0,1,1]
     i
```

We have `1` in `seen`. Let's calculate distance of `i - j`.

```
i - j <= k
= 2 - 0 <= 1
= false
```

That is not an answer. Just update `1` in `seen` with index `2`.

```
seen = {1: 2, 0: 1}
```

Next

```
[1,0,1,1]
       i
```

We have `1` in `seen`. Let's calculate distance of `i - j`.

```
i - j <= k
= 3 - 2 <= 1
= true
```

```
return True
```

* * * * *

[](https://youtu.be/bU_dXCOWHls)

* * * * *

Complexity
==========

Based on Python. Other might be different.

-   Time complexity: O(n)

-   Space complexity: O(n)

Python

JavaScript

Java

C++

```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (seen.find(val) != seen.end() && i - seen[val] <= k) {
                return true;
            }
            seen[val] = i;
        }

        return false;
    }
};
```

Step by Step Algorithm
======================

#### Step 1: Initialize a dictionary to keep track of the last seen indices.

```
seen = {}
```

Explanation:\
We create an empty dictionary called `seen`. This dictionary will store each number as a key and the index at which it was last seen as the corresponding value. This allows us to quickly check the last occurrence of each number in `nums`.

#### Step 2: Iterate through each element in the `nums` list with its index.

```
for i, val in enumerate(nums):
```

Explanation:\
We use a `for` loop with `enumerate` to iterate over the list `nums`. `enumerate` provides both the index `i` and the value `val` at each step in the list. This allows us to track the position of each number as we loop through `nums`.

#### Step 3: Check if the current number is already in `seen` and if the distance is within the limit `k`.

```
if val in seen and i - seen[val] <= k:
    return True
```

Explanation:\
In this step, we check two conditions:

1.  If `val` is already in `seen`. This means we've seen this number before and need to check if the duplicate is within the allowed distance.
2.  If `i - seen[val] <= k`. This calculates the distance between the current index `i` and the last seen index `seen[val]` for this number. If this distance is less than or equal to `k`, we have found a valid pair of duplicate indices that are within the allowed distance. In this case, we immediately return `True`.

#### Step 4: Update the last seen index of the current number.

```
else:
    seen[val] = i
```

Explanation:\
If the conditions in Step 3 are not met, we update `seen[val]` with the current index `i`. This keeps track of the latest occurrence of `val` in `nums`. Updating `seen[val]` ensures that any future checks will only compare against the most recent occurrence of `val`, minimizing the distance between indices.

#### Step 5: Return `False` if no valid pairs were found.

```
return False
```

Explanation:\
If we finish the loop without finding any duplicate pairs within the distance `k`, we return `False`. This indicates that no such pairs exist in the list `nums`.

* * * * *

Solution 2 - Set
================

In solution 1, each time I found a nearby number and its index from the current index, I kept track of them. The basic idea in Solution 2 is similar, but the method of keeping track of nearby numbers is different.

Let's see how it works.

```
nums = [2,0,3,2,3,4], k = 2
```

Basically, we add each number to `Set` every time.

```
[2,0,3,2,3,4]
 i

seen = (2)
-------------------------
[2,0,3,2,3,4]
   i

seen = (2)
```

We found `0` at index `1`. If we have `0` in `Set`, we can return `true`, but there is no `0`, so just add `0` to `Set`.

```
seen = (2,0)
```

Next

```
[2,0,3,2,3,4]
     i

seen = (2,0)
Do we have 3 in Set? → No → add 3 to Set.

seen = (2,0,3)
----------------------------
[2,0,3,2,3,4]
       i

seen = (2,0,3)
```

Here is an important point before checking `Set` and adding `2` to `Set`. Now we are at index `3` and we have `k = 2` from input. Since `k = 2`, the search range for duplicate numbers from index `3` only goes back to index `1`. This means that the number at index 0 is outside the target range and should be removed from the set of possible duplicates. Even if we have `2` at index 0, that is not answer.

Formula to calculate out of bounds position is very simple.

* * * * *

⭐️ Points

```
i - k - 1

i: current position
k: search range from current position
-1: next position of edge of target range

```

For example,

```
i - k - 1
= 3 - 2 - 1
= 0
```

* * * * *

We should remove the number at index `0` which is `2`.

```
[2,0,3,2,3,4]
       i

seen = (2,0,3)
Remove 2 from Set →　seen = (0,3)
Do we have 2 in Set? → No → add 2 to Set.
seen = (0,3,2)
------------------------------
[2,0,3,2,3,4]
         i

seen = (0,3,2)
Remove 0 from Set → seen = (3,2)
Do we have 3 in Set? → Yes
```

```
return True
```

Let's see solution codes!

* * * * *

Complexity
==========

Based on Python. Other might be different.

-   Time complexity: O(n)

-   Space complexity: O(n)

Python

JavaScript

Java

C++

```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                seen.erase(nums[i - k - 1]);
            }

            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }

            seen.insert(nums[i]);
        }

        return false;
    }
};
```

Step by Step Algorithm
======================

### Step 1

```
seen = set()
```

Explanation:\
This line initializes an empty set called `seen`, which will be used to keep track of the numbers we've encountered within the last `k` indices. Using a set is efficient because checking for the presence of an element in a set is faster than in a list (average time complexity is O(1)).

* * * * *

### Step 2

```
for i, val in enumerate(nums):
```

Explanation:\
This line starts a `for` loop, iterating through each element in `nums` with `enumerate`, which gives us both the index (`i`) and the value (`val`) of each element in `nums`.

* * * * *

### Step 3

```
if i > k:
    seen.remove(nums[i - k - 1])
```

Explanation:\
This condition checks if the current index `i` is greater than `k`. If so, it means that we have moved past the `k`-distance window for duplicates.

-   `nums[i - k - 1]` is the number that is `k + 1` indices behind the current position.
-   We remove this number from the `seen` set to keep only numbers within the last `k` indices in the set.

This helps ensure that only the most recent `k` indices are tracked for duplicates.

* * * * *

### Step 4

```
if val in seen:
    return True
```

Explanation:\
This condition checks if the current value `val` already exists in the `seen` set.

-   If `val` is found in `seen`, it means we've encountered a duplicate within the last `k` indices.
-   In this case, we return `True`, as we've found a nearby duplicate within the specified range.

* * * * *

### Step 5

```
seen.add(val)
```

Explanation:\
If `val` was not in `seen`, we add it to the set. This ensures that we're tracking the most recent values as we move through the `nums` array, within the `k` distance.

* * * * *

### Step 6

```
return False
```

Explanation:\
If the loop completes without finding any nearby duplicates, the function returns `False`, indicating that no duplicates were found within a distance of `k`.