// Given the head of a singly linked list, reverse the list, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:


// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000
 

// Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;   // Store next node
        curr->next = prev;   // Reverse current node's pointer
        prev = curr;         // Move prev to current
        curr = next;         // Move to next node
    }

    return prev;
}

// Function to create a linked list from user input
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

// Function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = createList(n);

    cout << "Original list: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
