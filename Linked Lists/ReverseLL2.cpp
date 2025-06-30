// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n
 

// Follow up: Could you do it in one pass?
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

// Reverse a sublist between left and right (1-based indexing)
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    for (int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }

    ListNode* cur = prev->next;

    for (int i = 0; i < right - left; i++) {
        ListNode* temp = cur->next;
        cur->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy->next;
}

// Helper to create linked list from input
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

// Print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, left, right;
    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = createList(n);

    cout << "Enter left and right positions to reverse between (1-based index): ";
    cin >> left >> right;

    head = reverseBetween(head, left, right);

    cout << "Modified list: ";
    printList(head);

    return 0;
}
