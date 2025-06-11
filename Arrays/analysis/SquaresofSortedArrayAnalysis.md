Approach
========

If there are no constraints, this question is very easy. Just multiply each number twice and sort them.

But the description says "could you find an O(n) solution?" So I'll show you O(n) solution.

```
Input: nums = [-4,-1,0,3,10]
```

Let's calculate square of each number.

```
-4 → 16
-1 → 1
0  → 0
3  → 9
10 → 100
```

There are two important points. Any idea?

* * * * *

⭐️ Points

-   Square of each number is positive or 0 which means we don't have to care about negative or positive for original numbers. We can foucs on only numbers even if numbers are negative. For example, `4` for `-4` or `1` for `-1`

-   Numbers at edge of array will produce bigger number because input array is sorted and we only focus on numbers. In this case, A number at index `0` or index `4` will produce the biggest square number.

```
[-4,-1,0,3,10]
[16,1,0,9,100]
```

* * * * *

From idea above, it's good idea to have two pointers starting from index `0` and the last index. Let's say `left` pointer and `right` pointer.

```
[-4,-1,0,3,10]
  L         R
```

One more important point is that as I explain above, we don't have to care about negative or positive, so we use an absolute value, so that we can focus on only numbers.

```
original → absolute value → square
-4 → 4 → 16
10 → 10 → 100
```

In this case, right number will produce bigger square, so this number should go to the last index of result array(= `i`).

To do that, simply we should have index value starting from the last. Create array with the same length of input array

```
         i
[0,0,0,0,0]
```

Then update `i` with `100` and `i` move next. After that `right` pointer also move next.

```
       i
[0,0,0,0,100]

[-4,-1,0,3,10]
  L      R
```

We will repeat the same process. I'll speed up.

```
abs(-4) vs abs(3)
= 16 vs 9

     i
[0,0,0,16,100]

[-4,-1,0,3,10]
    L    R
```

```
abs(-1) vs abs(3)
= 1 vs 9

   i
[0,0,9,16,100]

[-4,-1,0,3,10]
    L  R
```

```
abs(-1) vs abs(0)
= 1 vs 0

 i
[0,1,9,16,100]

[-4,-1,0,3,10]
       L
       R
```

```
abs(0) vs abs(0)
= 0 vs 0

 i
[0,1,9,16,100]

[-4,-1,0,3,10]
       R L
```

We will repeat that process with length of input array.

```
return [0,1,9,16,100]
```

* * * * *

Complexity
==========

-   Time complexity: O(n)

-   Space complexity: O(n)\
    If we count `res`. If not, O(1)

Python

JavaScript

Java

C++

```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[i] = nums[left] * nums[left];
                left++;
            } else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};
```

Step by Step Algorithm
----------------------

1.  Initialize Variables:
    -   `res`: Initialize a result list with the same length as the input list `nums`, filled with zeros. This list will store the squared values of the input list.
    -   `left`: Initialize a pointer at the beginning of the `nums` list.
    -   `right`: Initialize a pointer at the end of the `nums` list.

```
res = [0] * len(nums)
left = 0
right = len(nums) - 1
```

1.  Iterate over the List in Reverse:
    -   Start a loop that iterates over the indices of the `nums` list in reverse order (from the last index to the first index).

```
for i in range(len(nums) - 1, -1, -1):
```

1.  Comparing Absolute Values:
    -   Check if the absolute value of the element at index `left` is greater than the absolute value of the element at index `right`.
    -   If `abs(nums[left]) > abs(nums[right])`, square the value at index `left` and assign it to the current index `i` of the `res` list. Move the `left` pointer one step to the right.
    -   Otherwise, square the value at index `right` and assign it to the current index `i` of the `res` list. Move the `right` pointer one step to the left.

```
if abs(nums[left]) > abs(nums[right]):
    res[i] = nums[left] ** 2
    left += 1
else:
    res[i] = nums[right] ** 2
    right -= 1
```

1.  Return Result:
    -   After iterating through all elements of the `nums` list, return the `res` list containing squared values.

```
return res
```

This algorithm takes advantage of the fact that the input list `nums` is sorted (though it can contain negative numbers). It squares each number and sorts the squared values in non-decreasing order.