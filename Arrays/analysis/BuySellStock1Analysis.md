Intuition --- Why This Is a Classic Greedy Problem
================================================

This problem is a textbook case of greedy strategy.\
The goal is to buy at the lowest price so far and sell at the highest price after buying, all in one pass.

At each day:

We keep track of the minimum price seen so far --- the best day to buy.

We calculate the profit if we sell today, and update our maximum profit if it's higher.

This local, greedy decision --- to always buy at the lowest and sell today if profitable --- guarantees a globally optimal answer.

No need to look back or try every combination --- just greedily track the best buy and sell as you go.

Approach
========

1.  Initialize:

    mini = prices[0] -- our current best day to buy.

    profit = 0 -- maximum profit so far.

2.  Iterate through prices from day 1:\
    For each prices[i]:

    -   Calculate cost = prices[i] - mini, the profit if we buy at mini and sell today.

    -   Update profit = max(profit, cost), storing the best profit seen so far.

    -   Update mini = min(mini, prices[i]), in case today is a new cheaper day to buy.

3.  Return the maximum profit.

Complexity Analysis
===================

### Time Complexity:

O(n) -- We traverse the prices array once.

### Space Complexity:

O(1) -- We use only a few variables (mini, profit, cost) and no extra data structures.

Code
====

C++

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),cost=0,profit=0,mini=prices[0];
        for(int i=1;i<n;i++){
            cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};
```