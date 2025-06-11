#### 1\. Brute Force Solution

The brute force solution would be to create a nested loop that compares every possible pair of values in the array.

> Solution Steps

1.  Find the minimum absolute difference between every pair of integers in the array.
2.  Create a result array to store the result.
3.  For each pair of integers, if their absolute difference is equal to the minimum absolute value of array then append the pair to result.

> Pseudo Code

```
int[][] minimumAbsDifference(int input[], int size)
{
    int min_abs_diff = INT_MAX
    int result[][]
    for(int i = 0 to size)
    {
        for(int j = i+1 to size)
           min_abs_diff = min(min_abs_diff, abs(input[i] - input[j]))
    }
    int k = 0
    for(int i = 0 to size)
    {
        for(int j = i+1 to size)
        {
            if(abs(input[i] - input[j]) == min_abs_diff)
            {
                if(input[i] < input[j])
                {
                    result[k][0] = input[i]
                    result[k][1] = input[j]
                }
                else
                {
                    result[k][0] = input[j]
                    result[k][1] = input[i]
                }
                k = k + 1
            }
        }
    }
    return result
}
```

> Complexity Analysis

We are running two nested loops to calculate the minimum absolute difference. Time Complexity = O(n²)

Space Complexity = O(1)

> Crital Ideas to Think

-   Do you feel that there is no need to compare every possible pair?
-   If the question just asks you to find the pairs with the minimum difference (not absolute) then what changes will you make in this code?

#### 2\. Using Sorting

The better idea is to first sort the array, which simplifies everything. Notably, the minimal difference between 2 values in a sorted array must be between 2 adjacent values, hence once the array is sorted, we only need to go over the array once to find the minimal value.

This could be possible in two ways:

1.  Sort the array then, loop over the array to find the minimal difference and then loop over it again to store all pairs with that difference, or
2.  Sort the array then loop over the array to find the smallest difference while storing all pairs with that difference. Then, if we come across a pair with a smaller difference, we delete all the saved pairs and start storing only pairs with the lower difference, from then on.

The first solution would likely be more efficient in the average case, although there is no difference in n-notation running time.

> Solution steps

-   Sort the input array
-   For each index compare the absolute difference of adjacent elements and update the corresponding minimum.
-   Again iterate over the sorted array and check if the absolute difference between the neighboring elements is equal to the minimum absolute difference. If so then add it to the result array.

> Pseudo Code

```
int[][] minimumAbsDifference(int input[], int size)
{
    sort(input)
    int min_abs_diff = INT_MAX
    int result[][]
    for(int i = 0 to size-1)
        min_abs_diff = min(min_abs_diff, abs(input[i] - input[i+1]))
    int k = 0
    for(int i = 0 to size-1)
    {
        if(abs(input[i] - input[i+1]) == min_abs_diff)
        {
            result[k][0] = input[i]
            result[k][1] = input[i+1]
            k = k + 1
        }
    }
    return result
}
```

> Complexity Analysis

Time Complexity = Time Complexity of sorting + Time complexity of the loop to find the minimum absolute difference = O(n log n) + O(n) = O(n logn)

Space Complexity: O(1)