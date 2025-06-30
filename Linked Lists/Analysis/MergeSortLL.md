Approach
========

Just compare two values from `list 1` and `list 2`, then take the small value and create a new list.

But problem is that we can't return "the head of the merged linked list". So my strategy is to use dummy pointer which is always pointing to head node as a next node.

I visualized the solution in the video. Please check it out!


Complexity
==========

-   Time complexity: O(m+n)\
    `m` is length of `list1` and `n` is length of `list2`

-   Space complexity: O(1)

```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
```

Step by Step Algorithm
======================

1.  Initialize variables:

    -   We create a dummy node to serve as the starting point of the merged list.
    -   We initialize a pointer `cur` to keep track of the current node in the merged list, initially pointing to the dummy node.

    ```
    dummy = ListNode()
    cur = dummy
    ```

2.  Merge the lists:

    -   We iterate through both lists until either `list1` or `list2` becomes None.
    -   At each iteration, we compare the values of the current nodes of `list1` and `list2`.
    -   If the value of the current node in `list1` is greater than that of `list2`, we append the current node of `list2` to the merged list and move `list2` pointer to the next node.
    -   Otherwise, we append the current node of `list1` to the merged list and move `list1` pointer to the next node.

    ```
    while list1 and list2:
        if list1.val > list2.val:
            cur.next = list2
            list2 = list2.next
        else:
            cur.next = list1
            list1 = list1.next

        cur = cur.next
    ```

3.  Append remaining nodes:

    -   After the loop, if there are remaining nodes in either `list1` or `list2`, we append them to the end of the merged list.

    ```
    if list1:
        cur.next = list1
    else:
        cur.next = list2
    ```

4.  Return the merged list:

    -   We return the next node after the dummy node, which is the head of the merged list.

    ```
    return dummy.next
    ```

This algorithm effectively merges two sorted lists into one sorted list by splicing together their nodes.

* * * * *

Bonus
=====

These are bonus codes with recursion.

```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) {
            return list1 ? list1 : list2;
        }

        if (list1->val > list2->val) {
            swap(list1, list2);
        }

        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
};
```