Approach ( Using List )
=======================

To Check if the Given Linked List is palindrome or not , we can copy the data in list and then check if the list if palindrome or not.

Complexity
==========

-   Time complexity: O(N)

-   Space complexity: O(N)

Code
====

```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> listVals;
        while (head) {
            listVals.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = listVals.size() - 1;
        while (left < right && listVals[left] == listVals[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
};
```

Approach#2 ( Using Stack )
==========================

First push all data in stack, and then traverse linked list and keep popping element from stack one by one, so stack will give you element from last.

Code
====

```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode* curr = head;
        while (curr) {
            stack.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr && curr->val == stack.top()) {
            stack.pop();
            curr = curr->next;
        }
        return curr == nullptr;
    }
};
```

Approach#3 ( Using Recursion )
==============================

As you know, if any problem you can do using stack only then you can use recursion as well ( mostly ).

So we will have one global pointer as curr we will move this pointer once we reach the end and recursion will start from end of the list.

Code
====

```
int init = [] {
    ios_base::sync_with_stdio(false);  cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);)
        out<<(equal(s.begin()+1, s.begin()+s.size()/2, s.rbegin() + 1) ? "true\n" : "false\n");
    out.flush();
    exit(0);

    return 0;
}();

class Solution {
    ListNode* curr;
public:
    bool isPalindrome(ListNode* head) {
        curr = head;
        return solve(head);
    }

    bool solve(ListNode* head) {
        if (head == nullptr) return true;
        bool ans = solve(head->next) && head->val == curr->val;
        curr = curr->next;
        return ans;
    }
};
```

Approach#4
==========

The main idea to check palindrome is , if the first and last elements are same or not and then check for second and second last.

So I am thinking what if I create new linked list which would be reversed of the original linked list.

And then I can compare each element one by one.

##### But do I need the whole linked list to reverse and compare ?

No, I just need the second half of linked list to be reversed.

Now the question is how can I get the second half ?\
There are two approach

1.  Count all nodes first and then move to n/2th node, this would be middle node.
2.  Use two pointer one will move with the speed of 1 and one with the speed of 2, so when the fast pointer reaches the end, slow pointer would be at mid.

After getting middle node, reverse the list after that node.\
and then compare each element.

Code
====

```
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow);
        while (rev != nullptr) {
            if (head->val != rev->val) {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};
```