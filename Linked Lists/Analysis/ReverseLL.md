Intuition💡:
============

### Iterative Approach:

-   Use two pointers: `prev` (starts as `null`) and `curr` (starts at `head`).
-   At each step:\
    1 . Store `curr.next` in `temp`.\
    2 . Reverse `curr.next` to point to `prev`.\
    3 . Move `prev` to `curr` and `curr` to `temp`.
-   Repeat until `curr` is `null`.
-   `prev` becomes the new head of the reversed list.

### Visualization:

-   Original list : `1 -> 2 -> 3 -> 4 -> 5 ->null`
-   Reversed list : `5 -> 4 -> 3 -> 2 -> 1 -> null`

* * * * *

Approach & Step-by-Step Visualization🔍:
========================================

![giphy.gif](https://assets.leetcode.com/users/images/88001cde-da6d-4c9b-b071-dab8ff72c737_1746460191.785913.gif)

-   Here Assume `(next = temp)`

1 . `prev = null`:

-   prev starts as null because there's no node before the head.

2 . `curr = head`:

-   curr points to the first node (head) of the list.

![image.png](https://assets.leetcode.com/users/images/a042459e-2a0a-4f4e-90b5-54431a37fcb6_1742277024.3267157.png)

* * * * *

Step 1: Save the Next Node
--------------------------

-   Code:\
    `ListNode temp = curr.next;`

-   Action: Save the next node of curr in a temporary variable temp.

-   Visualization:

```
curr -> 1
temp -> 2
```

![image.png](https://assets.leetcode.com/users/images/02bdf1af-933d-45ac-accd-5a5345d379d2_1742277208.9818907.png)

* * * * *

Step 2: Reverse the Link
------------------------

-   Code: `curr.next = prev;`
-   Action: Reverse the link of curr to point to prev.
-   Visualization:\
    `null <- 1 2 -> 3 -> 4 -> 5 -> null`

![Screenshot 2025-03-18 112749.png](https://assets.leetcode.com/users/images/fd9d3869-a909-4cd1-809a-a62307149e02_1742277545.876817.png)

* * * * *

### Step 3: Move `prev` to `curr`

-   Code: `prev = curr`;
-   Action: Move `prev` to the current node (`curr`).
-   Visualization:

```
prev -> 1
curr -> 1
temp -> 2
```

![image.png](https://assets.leetcode.com/users/images/a1d9fcf0-419a-4bc5-a36a-030ebad78ad3_1742277725.5548484.png)

* * * * *

Step 4: Move `curr` to `temp`
-----------------------------

-   Code: `curr = temp;`
-   Action: Move `curr` to the next node (saved in `temp`).
-   Visualization:

```
prev -> 1
curr -> 2
temp -> 2
```

![image.png](https://assets.leetcode.com/users/images/92720154-3377-478a-ac16-fa01131f2d46_1742277960.6540473.png)

* * * * *

Step 5: Next Iteration - Save Next Node
---------------------------------------

-   Code: `ListNode temp = curr.next;`
-   Action: Save the next node of `curr` in `temp` for the next reversal step.
-   Visualization:

```
curr -> 2
temp -> 3
prev -> 1
```

![image.png](https://assets.leetcode.com/users/images/597018ad-2d5d-461b-a917-43b90d25d17d_1742278135.0936155.png)

* * * * *

Step 6: Reverse the Link
------------------------

-   Code: `curr.next = prev;`
-   Action: Reverse the link of `curr` to point to `prev`.
-   Visualization:

```
null <- 1 <- 2    3 -> 4 -> 5 -> null
```

![image.png](https://assets.leetcode.com/users/images/9bce19ef-dae6-4f28-8478-f0ac2331b7e4_1742278274.6449509.png)

* * * * *

Final State (After All Iterations)
----------------------------------

-   Code: `return prev;`
-   Action: Return `prev`, which is now the new head of the reversed list.
-   Visualization:

```
Reversed Linked List: 5 -> 4 -> 3 -> 2 -> 1 -> null
```

![image.png](https://assets.leetcode.com/users/images/12dc8bdd-6aed-4493-b112-5911e399903a_1742278403.5573204.png)

-   Result: The original `list 1 -> 2 -> 3 -> 4 -> 5 -> null` is now reversed to `5 -> 4 -> 3 -> 2 -> 1 -> null`.

* * * * *

⏳Complexity Analysis
====================

-   Time complexity: O(n) (linear time).

-   Space complexity:O(1) (constant space).

* * * * *

💻Code Implementation
=====================

```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next; // Store the next node
            curr->next = prev;            // Reverse the current node's pointer
            prev = curr;                  // Move prev to current node
            curr = temp;                  // Move to the next node
        }
        return prev; // New head of the reversed list
    }
};
```