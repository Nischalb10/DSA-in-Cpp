Brute Force
===========

```
class Solution {
public:
    int timeRequiredToBuy(vector<int>& v, int k) {
        int n=v.size();
        int t=0;
        while(true) {
            for(int i=0;i<n;i++) {
                if(v[i]>0) {
                    v[i]=v[i]-1;
                    t++;
                }
                if(i==k && v[i]==0)
                    return t;
            }
        }
        return 0;
    }
};
```

Complexity
==========

-   Time complexity:

```
O(n * m)
n: size of array
m : max number within the array
```

-   Space complexity:

```
O(1)
```

Approach
========

#### 1\. Initialize a variable `time` to keep track of the total time taken.

#### 2\. While the person at position k hasn't bought all their tickets:

-   Iterate through the queue and let each person buy a ticket.
-   Update the queue by decrementing the number of tickets for the person who bought a ticket.
-   Increment the time by 1 second for each pass.

#### 3\. Return the total time taken.

Complexity
==========

-   Time complexity:
    ----------------

#### The algorithm iterates through each person in the queue once, so the time complexity of the loop is O(n), where n is the number of people in the queue.

-   Space complexity:
    -----------------

#### The algorithm uses only a constant amount of extra space for variables such as `total`, `i`, and `x`.

#### Therefore, the space complexity is O(1).

* * * * *

Code
====

```
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;

        for (int i = 0; i < tickets.size(); ++i) {
            if (i <= k) {
                total += min(tickets[i], tickets[k]);
            } else {
                total += min(tickets[i], tickets[k] - 1);
            }
        }

        return total;
    }
};
```

`\
`