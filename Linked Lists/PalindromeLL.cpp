// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
 

// Follow up: Could you do it in O(n) time and O(1) space?
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse a linked list
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

// Check if a linked list is a palindrome
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Move slow to middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* rev = reverse(slow);

    // Compare both halves
    while (rev != nullptr) {
        if (head->val != rev->val) {
            return false;
        }
        head = head->next;
        rev = rev->next;
    }

    return true;
}

// Create linked list from user input
ListNode* createList(int n) {
    if (n == 0) return nullptr;

    int val;
    cout << "Enter value for node 1: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* tail = head;

    for (int i = 2; i <= n; ++i) {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    return head;
}

int main() {
    int n;
    cout << "Enter number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = createList(n);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
