Intuition
=========

The main idea to solve the question of detecting a cycle in a singly-linked list is to use the concept of two pointers: a "slow" pointer that moves one step at a time and a "fast" pointer that moves two steps at a time. By having these two pointers traverse the list simultaneously, if there is a cycle, the fast pointer will eventually catch up to the slow pointer. If there is no cycle, the fast pointer will reach the end of the list.



Approach
========

This is based on Python. Other might be different a bit.

1.  Initialize `fast` and `slow` pointers to the head of the linked list.

    -   `fast` and `slow` are initially pointing to the head of the linked list, which is the starting point.
2.  Enter a loop while both `fast` and `fast.next` are not null.

    -   This loop will continue until either `fast` or `fast.next` becomes null, indicating the end of the linked list or if there is no cycle.
3.  Move the `fast` pointer two steps ahead (`fast = fast.next.next`) and the `slow` pointer one step ahead (`slow = slow.next`).

    -   This step simulates the two-pointer traversal where `fast` moves twice as fast as `slow`.
4.  Check if `fast` is equal to `slow`.

    -   If `fast` and `slow` pointers meet at the same node, it means there is a cycle in the linked list, and we return `True`.
5.  If the loop exits without finding a cycle, return `False`.

    -   If the loop completes without finding a cycle, it means that the `fast` pointer has reached the end of the list, and there is no cycle. In this case, we return `False`.

This algorithm uses two pointers, `fast` and `slow`, to traverse the linked list. The `fast` pointer moves twice as fast as the `slow` pointer. If there is a cycle, the `fast` pointer will eventually catch up to the `slow` pointer. If there is no cycle, the `fast` pointer will reach the end of the list, and the function will return `False`. This algorithm is an efficient way to detect cycles in a singly-linked list.



Complexity
==========

-   Time complexity: O(n)

-   Space complexity: O(1)

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
```