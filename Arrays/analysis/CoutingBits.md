EXPLANATION

```
 1. we are iterating till n;
	for every i, we have to count 1's bits in its binary form.
	0 --> 0
	1 --> 1
	2 --> 10
	3 --> 11
	4 --> 100
	5 --> 101

	Output: [0,1,1,2,1,2]

2.  Iterating till i becomes  zero and adding it remainder to sum on division by 2
	& reducing i by 2;

3.Add sum to the ans vector.
```

CODE (Onlogn)

```

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

		// iterating fromt 0 to n
        for(int i = 0; i<=n; i++)
        {
			// sum is initialised as 0
            int sum = 0;
            int num = i;
			// while num not equals zero
            while(num != 0)
            {
				// we have to count 1's in binary representation of i, therefore % 2
                sum += num%2;
                num = num/2;
            }
			// add sum to ans vector
            ans.push_back(sum);
        }
		// return
        return ans;
    }
};
```

Intuition
=========

The most important idea to solve the question of counting the number of set bits (1s) in the binary representation of numbers from 0 to n is to recognize and utilize the pattern that relates the count of set bits in a number to the count of set bits in another number that is a power of 2. This concept allows you to optimize the counting process and avoid redundant calculations.

The key idea is to leverage dynamic programming and exploit the fact that a number i can be represented as the sum of a smaller number i - sub and 1. The value of sub is adjusted whenever i is a power of 2. This enables efficient counting of set bits by using the previously calculated counts for smaller numbers.

By following this approach, you can dramatically reduce the number of bit counting operations needed to solve the problem, making the algorithm more efficient and faster than naïve approaches that directly iterate through each bit of every number.

* * * * *


Approach
========

This is based on Python. Other might be differnt a bit

1.  Initialize Variables and Data Structures:

    -   Create a class named `Solution`.
    -   Define a method within the class called `countBits`, which takes an integer `n` as an argument.
    -   Create an array `dp` of length `(n + 1)` to store the count of set bits for numbers from 0 to `n`.
    -   Initialize a variable `sub` with the value 1.
2.  Iterate through Numbers:

    -   Use a `for` loop to iterate over numbers from 1 to `n`, inclusive.
3.  Determine Subsequence Reset:

    -   Check if `sub` multiplied by 2 is equal to the current value of `i`.
    -   If true, update the value of `sub` to be equal to `i`. This step is responsible for resetting the subsequence when the current number is a power of 2.
4.  Count Set Bits:

    -   Calculate the count of set bits for the current number by accessing `dp[i - sub]` and adding 1.
    -   This step utilizes the fact that the count of set bits for a number `i` can be obtained by counting the set bits of the number `i - sub` and adding 1.
5.  Store Result in dp Array:

    -   Assign the calculated count of set bits for the current number to `dp[i]`.
6.  Return Result:

    -   After the loop completes, the `dp` array will contain the count of set bits for numbers from 0 to `n`.
    -   Return the `dp` array as the final result of the `countBits` method.

In summary, the code implements a dynamic programming approach to count the number of set bits (1s) in the binary representation of numbers from 0 to `n`. It uses an array `dp` to store the results and calculates the count of set bits step by step, based on the idea of resetting subsequences at powers of 2.

Complexity
==========

-   Time complexity: O(n)

-   Space complexity: O(n)

```
class Solution {
public:
    vector<int> countBits(int n) {
       std::vector<int> dp(n + 1, 0);
        int sub = 1;

        for (int i = 1; i <= n; i++) {
            if (sub * 2 == i) {
                sub = i;
            }

            dp[i] = dp[i - sub] + 1;
        }

        return dp;
    }
};
```