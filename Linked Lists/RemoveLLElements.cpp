// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

// Example 1:


// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
// Example 2:

// Input: head = [], val = 1
// Output: []
// Example 3:

// Input: head = [7,7,7,7], val = 7
// Output: []
 

// Constraints:

// The number of nodes in the list is in the range [0, 104].
// 1 <= Node.val <= 50
// 0 <= val <= 50
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

// Function to remove elements with a given value
ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr) {
        if (curr->val == val) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

// Create linked list from input
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

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, valToRemove;
    cout << "Enter number of nodes in the list: ";
    cin >> n;

    ListNode* head = createList(n);

    cout << "Enter value to remove: ";
    cin >> valToRemove;

    head = removeElements(head, valToRemove);

    cout << "Modified list after removing " << valToRemove << ": ";
    printList(head);

    return 0;
}
