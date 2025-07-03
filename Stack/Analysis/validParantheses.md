Approach
========

Just compare two values from `list 1` and `list 2`, then take the small value and create a new list.

But problem is that we can't return "the head of the merged linked list". So my strategy is to use dummy pointer which is always pointing to head node as a next node.

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
```Approach
========

We use `HashMap` and `Stack`. We know valid combination, so initialize the combination with `HashMap` before we iterate through the input string.

```
mapping = { ")":"(", "}":"{", "]":"[" }
```

`Stack` has only open parentheses. When a close parenthesis comes, we use it as a key to find valid open parenthesis in the `mapping`. If the two parentheses(current parenthesis and the latest parenthesis in `Stack`) are not valid combination, we should return `False`.

At last, if `Stack` is empty, we should return `True`.


Complexity
==========

-   Time complexity: O(n)

-   Space complexity: O(n)

```
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (mapping.find(c) == mapping.end()) {
                stack.push(c);
            } else if (!stack.empty() && mapping[c] == stack.top()) {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();
    }
};
```

* * * * *

Solution 2
==========

We can solve this question with `Stack` only. If `Stack` has some parenthesis, we check the latest parenthesis in `Stack` and current parenthesis are valid combination.

If true, just pop the parenthesis from the `Stack` and move next, if false, add current parenthesis to the `Stack`.

At last, if `Stack` is empty, return `True`.

* * * * *

Complexity
==========

-   Time complexity: O(n)

-   Space complexity: O(n)

```
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char cur : s) {
            if (!st.empty()) {
                char last = st.top();
                if (isPair(last, cur)) {
                    st.pop();
                    continue;
                }
            }
            st.push(cur);
        }

        return st.empty();
    }

private:
    bool isPair(char last, char cur) {
        return (last == '(' && cur == ')') ||
               (last == '{' && cur == '}') ||
               (last == '[' && cur == ']');
    }
};
```

`\
`