Intuition
=========

Create an answer node and copy it as dummy node to return entire new linked list and delete the first node if it is target value.

Approach
========

1.  Create a new node 'ans' with value 0 and set its next pointer to the 'head' of the input linked list. This is done to simplify the handling of the edge case where the head node of the linked list needs to be removed.

2.  Create a new node 'dummy' and set it to 'ans'. This 'dummy' node will be used to traverse the linked list and remove nodes with the value 'val'.

3.  Start a while loop that continues until 'dummy' is not None. This loop iterates through the linked list.

4.  Inside the outer while loop, start another while loop that continues as long as 'dummy.next' is not None and the value of 'dummy.next' is equal to 'val'. This inner loop skips all the consecutive nodes with the value 'val'.

5.  Inside the inner while loop, update the 'next' pointer of 'dummy' to skip the node with the value 'val' by setting it to 'dummy.next.next'. This effectively removes the node with the value 'val' from the linked list.

6.  After the inner while loop, move 'dummy' one step forward by setting it to 'dummy.next'. This is done to continue traversing the linked list.

7.  Repeat steps 4-6 until the inner while loop can no longer find consecutive nodes with the value 'val'. At this point, 'dummy' will be pointing to the last node in the original linked list, or None if all nodes with the value 'val' have been removed.

8.  Return the 'next' pointer of 'ans', which is the head of the modified linked list with nodes containing the value 'val' removed.

Complexity
==========

-   Time complexity: O(N)\
    N is the number of nodes in the linked list. This is because the code iterates through the linked list once with a single while loop. The inner while loop only runs when the value of the next node matches the given value 'val', and in the worst case, it may iterate through all the nodes in the linked list.

-   Space complexity: O(1)\
    The code uses a constant amount of extra space. The only extra space used is for the two pointers 'ans' and 'dummy', which are used to manipulate the linked list, and they do not depend on the size of the input linked list. The original linked list is modified in place, and no additional data structures are used, resulting in constant space complexity.

```
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode(0, head);
        ListNode* dummy = ans;

        while (dummy != nullptr) {
            while (dummy->next != nullptr && dummy->next->val == val) {
                dummy->next = dummy->next->next;
            }
            dummy = dummy->next;
        }

        ListNode* result = ans->next;
        delete ans;

        return result;
    }
};
```