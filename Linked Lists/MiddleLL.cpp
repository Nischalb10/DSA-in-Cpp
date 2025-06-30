// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

// Constraints:

// The number of nodes in the list is in the range [1, 100].
// 1 <= Node.val <= 100
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the middle node
ListNode* middleNode(ListNode* head) {
    ListNode* p = head;
    ListNode* q = head;
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
    }
    return p;
}

// Function to create linked list from user input
ListNode* createList(int n) {
    if (n == 0) return nullptr;

    int val;
    cout << "Enter value of node 1: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* tail = head;

    for (int i = 2; i <= n; ++i) {
        cout << "Enter value of node " << i << ": ";
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    return head;
}

// Function to print linked list from a given node
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = createList(n);

    ListNode* mid = middleNode(head);

    cout << "Middle node value: " << mid->val << endl;
    cout << "List starting from middle node: ";
    printList(mid);

    return 0;
}
